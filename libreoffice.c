static const int aDaysInMonth[12] = {31, 28, 31, 30, 31, 30,
                                     31, 31, 30, 31, 30, 31};

int ImpYearToDays(int nYear)
{
  int nOffset;
  int nYr;
  if (nYear < 0)
  {
    nOffset = -366;
    nYr = nYear + 1;
  }
  else
  {
    nOffset = 0;
    nYr = nYear - 1;
  }
  return nOffset + nYr * 365 + nYr / 4 - nYr / 100 + nYr / 400;
}

int ImpIsLeapYear(int nYear)
{
  return ((((nYear % 4) == 0) && ((nYear % 100) != 0)) ||
          ((nYear % 400) == 0));
}

int ImplDaysInMonth(int nMonth, int nYear)
{
  if (nMonth != 2)
    return aDaysInMonth[nMonth - 1];
  else
  {
    if (ImpIsLeapYear(nYear))
      return aDaysInMonth[nMonth - 1] + 1;
    else
      return aDaysInMonth[nMonth - 1];
  }
}

int getDaysFromYMD_libreOffice(int nYear, int nMonth, int nDay)
{

  int nDays = ImpYearToDays(nYear);
  for (int i = 1; i < nMonth; i++)
    nDays += ImplDaysInMonth(i, nYear);
  nDays += nDay;
  return nDays - 730120 + 10961;
}