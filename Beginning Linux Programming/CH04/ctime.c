#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
  time_t the_time;

  (void)time(&the_time);

  printf("The date is: %s\n", ctime(&the_time));

  exit(0);
}
