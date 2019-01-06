#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *menu[] = {
  "a - add new record",
  "d - delete record",
  "q - quit",
  NULL,
};

static int getchoice(char *greet, char *choices[], FILE *in, FILE *out);

int main()
{
  int choice = 0;
  FILE *input;
  FILE *output;
  
  if (!isatty(fileno(stdout))) {
    fprintf(stderr, "You are not a terminal!\n");
  }

  input = fopen("/dev/tty", "r");
  output = fopen("/dev/tty", "w");
  if (!input || !output) {
    fprintf(stderr, "Unable to open /dev/tty\n");
    exit(1);
  }
  
  do {
    choice = getchoice("Please select an action", menu, input, output);
    printf("You have chosen: %c\n", choice);
  } while ('q' != choice);
  exit(0);
}

static int getchoice(char *greet, char *choices[], FILE *input, FILE *output)
{
  int chosen = 0;
  int selected;
  char **option;

  do {
    fprintf(output, "Choice: %s\n", greet);
    option = choices;
    while (*option) {
      fprintf(output, "%s\n", *option);
      ++option;
    }
    selected = getchar();
    option = choices;
    while (*option) {
      if (selected == *option[0]) {
	chosen = 1;
	break;
      }
      ++option;
    }
    if (!chosen) {
      fprintf(output, "Incorrect choice, select again\n");
    }
  } while (!chosen);
  return selected;
}