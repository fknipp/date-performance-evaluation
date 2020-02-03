// Source: https://chromium.googlesource.com/v8/v8.git/+/refs/heads/master/src/date/date.cc
// Function: DateCache::DaysFromYearMonth
// License: https://chromium.googlesource.com/v8/v8.git/+/refs/heads/master/LICENSE

#define year_delta 399999

int getDaysFromYMD_v8(int year, int month, int d)
{
  static const int day_from_month[] = {0, 31, 59, 90, 120, 151,
                                       181, 212, 243, 273, 304, 334};
  static const int day_from_month_leap[] = {0, 31, 60, 91, 121, 152,
                                            182, 213, 244, 274, 305, 335};

  // year_delta is an arbitrary number such that:
  // a) year_delta = -1 (mod 400)
  // b) year + year_delta > 0 for years in the range defined by
  //    ECMA 262 - 15.9.1.1, i.e. upto 100,000,000 days on either side of
  //    Jan 1 1970. This is required so that we don't run into integer
  //    division of negative numbers.
  // c) there shouldn't be an overflow for 32-bit integers in the following
  //    operations.
  static const int base_day =
      365 * (1970 + year_delta) + (1970 + year_delta) / 4 -
      (1970 + year_delta) / 100 + (1970 + year_delta) / 400;
  int year1 = year + year_delta;
  int day_from_year =
      365 * year1 + year1 / 4 - year1 / 100 + year1 / 400 - base_day;
  if ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0))
  {
    return day_from_year + day_from_month[month] + d + 3;
  }
  return day_from_year + day_from_month_leap[month] + d + 3;
}