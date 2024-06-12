#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <windows.h>


#include <iostream>
using namespace std;

int is_leep_year(int year);
int get_day_num(int year, int month);
int main()
{
	int year = 0;
	int month = 0;
	int daynum = 0;
	cout << "Äê month";
	scanf("%d %d", &year, &month);

	daynum = get_day_num(year, month);

	printf("%dyear%dmonth's day is:  %d", year, month, daynum);

}
int get_day_num(int year, int month)
{
	int key = 0;
	int days[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int days_res = days[month];

	key = is_leep_year(year);
	if (key && month == 2)
	{
		days_res += 1;
	}

	return days_res;
}

int is_leep_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 1;
	else
		return 0;
}