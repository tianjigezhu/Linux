#include <unistd.h>
#include <stdlib.h>

int main()
{
  printf("Host id:%ld\n", gethostid());

  exit(0);
}
