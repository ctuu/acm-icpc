#include <stdio.h>
int DayofYear(int year, int month, int day);
int Is_leapyear(int year);
int daysofmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int daysofmonth2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void MonthDay(int year, int yearDay, int *pMonth, int *pDay)
{
    int i, last;
    if (Is_leapyear(year))
    {
        for (i = 0; yearDay > 0; i++)
        {
            last = yearDay;
            yearDay -= daysofmonth2[i];
        };
        *pDay = last;
        *pMonth = i;
    }
    else
    {
        for (i = 0; yearDay > 0; i++)
        {
            last = yearDay;
            yearDay -= daysofmonth[i];
        }
        *pDay = last;
        *pMonth = i++;
    }
}
int main(void)
{
    int res, year, month, day, yearDay;
    int T, s;
    scanf("%d", &T);
    while (T--)
    {

        scanf("%d-%d-%d", &year, &month, &day);
        scanf("%d", &s);
        s /= 86400;
        res = DayofYear(year, month, day);
        yearDay = res + s;
        //printf("\nDay of year is %d \n",res);
        if (Is_leapyear(year) == 1)
        {
            for (;;)
            {
                if (yearDay < 366)
                    break;
                if (Is_leapyear(year) == 1)
                {
                    year++;
                    yearDay -= 366;
                    continue;
                }
                else
                {
                    year++;
                    yearDay -= 365;
                }
            }
        }
        else
        {
            for (;;)
            {
                if (yearDay <= 366)
                    break;
                if (Is_leapyear(year) == 1)
                {
                    year++;
                    yearDay -= 366;
                    continue;
                }
                else
                {
                    year++;
                    yearDay -= 365;
                }
            }
        }
        MonthDay(year, yearDay, &month, &day);
        printf("%d-%02d-%02d\n", year, month, day);
    }
}

int Is_leapyear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    else
        return 0;
}

int DayofYear(int year, int month, int day)
{
    int i, res = 0;

    if (Is_leapyear(year))
    {
        for (i = 0; i < month - 1; i++)
        {
            res += daysofmonth2[i];
        }
        res += day;
        return res;
    }
    else
    {
        for (i = 0; i < month - 1; i++)
        {
            res += daysofmonth[i];
        }
        res += day;
        return res;
    }
}
