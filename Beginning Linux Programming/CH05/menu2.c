#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *menu[] = {
  "a - add new record",
  "d - delete record",
  "q - quit",
  NULL,
};

static int getchoice(char *greet, char *choices[]);

int main()
{
  int choice = 0;

  if (!isatty(fileno(stdout))) {
    fprintf(stderr, "You are not a terminal!\n");
    exit(1);
  }
  
  do {
    choice = getchoice("Please select an action", menu);
    printf("You have chosen: %c\n", choice);
  } while ('q' != choice);
  exit(0);
}

static int getchoice(char *greet, char *choices[])
{
  int chosen = 0;
  int selected;
  char **option;

  do {
    printf("Choice: %s\n", greet);
    option = choices;
    while (*option) {
      printf("%s\n", *option);
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
      printf("Incorrect choice, select again\n");
    }
  } while (!chosen);
  return selected;
}