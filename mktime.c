// Source: https://github.com/lattera/glibc/blob/master/time/mktime.c
// License: GPL Version 2

typedef long int long_int;

const unsigned short int __mon_yday[2][13] =
    {
        /* Normal years.  */
        {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
        /* Leap years.  */
        {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}};

#define SHR(a, b)                             \
  ((-1 >> 1 == -1 && (long_int)-1 >> 1 == -1) \
       ? (a) >> (b)                           \
       : (a) / (1 << (b)) - ((a) % (1 << (b)) < 0))

static int leapyear(long_int year)
{
  /* Don't add YEAR to TM_YEAR_BASE, as that might overflow.
     Also, work even if YEAR is negative.  */
  return ((year & 3) == 0 && (year % 100 != 0 || ((year / 100) & 3) == (-(1900 / 100) & 3)));
}

int getDaysFromYMD_mktime(int y, int m, int d)
{
  int mon_yday = ((__mon_yday[leapyear(y)][m]) - 1);
  long_int yday = mon_yday + d;

  int a4 = SHR(y, 2) + SHR(1900, 2) - !(y & 3);
  int a100 = a4 / 25 - (a4 % 25 < 0);
  int a400 = SHR(a100, 2);
  int intervening_leap_days = a4 - a100 + a400;

  int d1 = 365 * y + yday + intervening_leap_days;

  // offset for epoch
  d1 -= 37185 - 11162;

  return d1;
}