#include<time.h>

/**
 * Converts the broken-down time structure to calendar time representation
 * considering the given offset.
 *
 * @param tm Time structure containing tm_gmtoff (BSD extension).
 * @return The calendar time.
 *
 * The time structure is neither normalized nor tested for validity.
 *
 * The algorithm is based solely on integer operations and does not use any
 * control statements like 'for' or 'if'. To consider the leap day, the number
 * of days is calculated by moving the start of a year to the first of March
 * (see the variable rmon). January and February are assigned to the year
 * before (see ryear).
 */
time_t mktime_offset(const struct tm *tm) 
{

  // calculate shifted month and year
  int rmon = (tm->tm_mon + 10) % 12;
  int ryear = tm->tm_year + (tm->tm_mon - 11) / 10;

  // set day of month
  time_t ret = tm->tm_mday;

  // add the number of days of the months before
  ret += (3 * rmon + 2) / 5 + rmon * 30;  

  // add leap days
  ret += ryear / 4;
  ret -= ryear / 100;
  ret += (ryear + 300) / 400;

  // add years
  ret += ryear * 365; 

  // offset for 1. 1. 1970 (the epoch)
  ret -= 25509;

  // convert days to seconds
  ret *= 24 * 3600;

  // add time
  ret += ((tm->tm_hour * 60) + tm->tm_min) * 60 + tm->tm_sec;

  // subtract time zone
  // ret -= tm->tm_gmtoff;

  return ret;

}