#include <stdio.h>

int getDaysFromYMD_knipp(int y, int m, int d);
int getDaysFromYMD_mktime(int y, int m, int d);
int getDaysFromYMD_v8(int y, int m, int d);
int getDaysFromYMD_libreOffice(int y, int m, int d);

int main()
{

  int n = 0;

  for (int i = 0; i < 10000; i++)
  {
    for (int y = 0; y < 200; y++)
    {
      for (int m = 0; m <= 11; m++)
      {
        for (int d = 1; d <= 28; d++)
        {
          int libreOffice = getDaysFromYMD_libreOffice(y + 1900, m + 1, d);
          int knipp = getDaysFromYMD_knipp(y, m, d);
          int mktime = getDaysFromYMD_mktime(y, m, d);
          int v8 = getDaysFromYMD_v8(y + 1900, m, d);

          if (knipp != mktime || mktime != v8 || v8 != libreOffice)
          {
            printf("%04d-%02d-%02d\n", y + 1900, m, d);
            printf("knipp:       %d\n", knipp);
            printf("mktime:      %d\n", mktime);
            printf("v8:          %d\n", v8);
            printf("libreOffice: %d\n", libreOffice);
          }

          n++;
        }
      }
    }
  }

  printf("%d iterations performed.\n", n);

  return 0;
}