#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  struct tm *tm_ptr = NULL, *local_tm_ptr = NULL;
  time_t the_time;

  (void)time(&the_time);
  tm_ptr = gmtime(&the_time);

  printf("Raw time is %ld\n", the_time);
  printf("gmtime gives:\n");
  printf("data: %02d/%02d/%02d\n",
	 tm_ptr->tm_year, tm_ptr->tm_mon+1, tm_ptr->tm_mday);
  printf("time: %02d:%02d:%02d\n",
	 tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);

  local_tm_ptr = localtime(&the_time);
  printf("localtime gives:\n");
  printf("date: %02d/%02d/%02d\n",
	 local_tm_ptr->tm_year, local_tm_ptr->tm_mon+1, local_tm_ptr->tm_mday);
  printf("time: %02d:%02d:%02d\n",
	 local_tm_ptr->tm_hour, local_tm_ptr->tm_min, local_tm_ptr->tm_sec);
  exit(0);
}
