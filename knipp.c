int getDaysFromYMD_knipp(int y, int m, int d)
{
  int rmon = (m + 10) % 12;
  int ryear = y + (m - 11) / 10;

  // add the number of days of the months before
  int d1 = d + (3 * rmon + 2) / 5 + rmon * 30;

  // add leap days
  d1 += ryear / 4;
  d1 -= ryear / 100;
  d1 += (ryear + 1900) / 400;

  // add years
  d1 += ryear * 365;

  // offset for 1. 1. 1970 (the epoch)
  d1 -= 25509;

  return d1;
}