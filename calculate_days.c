#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "calculate_days.h"

/***********************************
  * calculateDays
  * Given a month and day of the month, return the number of days
  * @param:
  * month: month
  * monthDay: day of month
  * @return:
  * integer number of days
*/
int calculateDays(Month currentMonth, int monthDay, int year){
  int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  int days = monthDay;
  Month i;

  assert(year > 0);
  if(isLeapYear(year)){
    daysPerMonth[Feb] += 1;
  }
  assert(monthDay >= 1 && monthDay <= daysPerMonth[currentMonth]);


  for (i = Jan; i < currentMonth; i++){
    days += daysPerMonth[i];
  }

  return days;
}


/***********************************
  * isLeapYear
  * Given a year return 1 if it is leap else return 0
  * @param:
  * year: year
  * @return:
  * integer: 1 || 0
*/
int isLeapYear(int year){
  assert(year > 0);
  if((year % 4 == 0 && (year % 100 != 0)) || (year % 400 == 0)){
    return 1;
  }
  return 0;
}

/*
 if((year modulo 4 is 0) and (year modulo 100 is not 0))
 or

*/
