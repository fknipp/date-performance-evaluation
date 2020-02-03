#include <stdlib.h>
#include <stdio.h>
#include <time.h>

time_t mktime_offset(const struct tm *tm);

int main()
{

  putenv("TZ=UTC0");
  tzset();

  int n = 0;

  struct tm tm = {0, 0, 0, 0, 0, 0, 0, 0, -1};

  for (int i = 0; i < 10000; i++)
  {
    for (int y = 0; y < 200; y++)
    {
      for (int m = 0; m <= 11; m++)
      {
        for (int d = 1; d <= 28; d++)
        {
          
          tm.tm_mday = d;
          tm.tm_mon = m;
          tm.tm_year = y;

          const time_t x1 = mktime(&tm);
          //const time_t x2 = mktime_offset(&tm);

          // if (x1 != x2)
          // {
          //   printf("%04d-%02d-%02d\n", y + 1900, m, d);
          //   printf("mktime:        %d\n", x2);
          //   printf("mktime_offset: %d\n", x1);
          // }

          n++;
        }
      }
    }
  }

  printf("%d iterations performed.\n", n);

  return 0;
}