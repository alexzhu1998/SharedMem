#include <stdio.h>
#include <time.h>
#include <string.h>


void assign_time(char* datetime) {
    time_t rawtime;
    struct tm * timeinfo;

    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    strcpy(datetime,asctime (timeinfo));
}

int main ()
{
  
  char datetime[30];
  assign_time(datetime);
  printf ( "Current local time and date: %s", datetime);
  
  return 0;
}