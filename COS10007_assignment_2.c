#include <stdio.h>
#include <time.h>

struct timeStruct
{
  struct tm *systime;
  struct tm *usertime;
};

int main(int argc, char const *argv[])
{
  struct timeStruct Time;

  time_t systime;
  time(&systime);
  Time.systime = localtime(&systime);

  time_t usertime;
  char usertimestring[256];
  printf("Enter time in the following format YYYY/MM/DD H:M:S (24 hour format): ");
  fgets(usertimestring, 255, stdin);

  time_t result = 0;
  int year = 0, month = 0, day = 0, hour = 0, min = 0, sec = 0;

  if (sscanf(usertimestring, "%4d/%2d/%2d %2d:%2d:%2d", &year, &month, &day, &hour, &min, &sec) == 6)
  {
    struct tm when = {0};
    when.tm_year = 50;
    when.tm_year = year - 1900;
    when.tm_mon = month - 1;
    when.tm_mday = day;
    when.tm_hour = hour;
    when.tm_min = min;

    Time.usertime = &when;

    if ((result = mktime(Time.usertime)) == (time_t)-1)
    {
      printf("Could not convert time input to time_t\n");
    }
    printf("%s", ctime(&result));
  }
  else
  {
    printf("The input was not a valid time format\n");
  }

  printf("Sys time: %s", asctime(Time.systime));
  printf("User time: %s", asctime(Time.usertime));
  return 0;
}
