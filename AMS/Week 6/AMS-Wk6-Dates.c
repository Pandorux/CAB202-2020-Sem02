#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

bool Is_An_Integer(char str[], int size);
bool Date_Read(int *d, int *m, int *y);
void Date_Write(int d, int m, int y);
int Date_Compare(int d1, int m1, int y1, int d2, int m2, int y2);
bool Is_A_Leap_Year(int y);
int Get_Length_Of_Month(int m, bool isALeapYear);
bool Date_Valid (int d, int m, int y);


//  (Task 1) Define a function called Date_Read which uses scanf to get the 
//  data for a date. Fields are to be entered as three separate int values
//  in the format "%d-%d-%d". Dates will be entered with day first, followed by
//  month, followed by year.
// 
//  Parameters:
//      d - the address of an integer which will represent the day.
//      m - the address of an integer which will represent the month.
//      y - the address of an integer which will represent the year.
//
//  Returns:
//      The function must return a boolean value indicating the status of the 
//      I/O operation. The result is true if and only if three integer values 
//      have been successfully parsed using the designated format string.
//
//      Do not try to perform other data validation in this function.

bool Is_An_Integer(char str[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(!isdigit(str[i]))
        {
            return FALSE;
        }
    }

    return TRUE;
}

bool Date_Read(int *d, int *m, int *y)
{
    char d_str[]; 
    char m_str[]; 
    char y_str[]; 

    bool scan_result = scanf("%s-%s-%s", d_str, m_str, y_str);

    if(scan_result == TRUE) 
    {
        if(Is_An_Integer(d_str, 20)
           &&Is_An_Integer(m_str, 20)
           &&Is_An_Integer(y_str, 20))
        {
            *d = atoi(d_str);
            *m = atoi(m_str);
            *y = atoi(y_str);

            return TRUE;
        }
    }

    return FALSE;
}

//  (Task 2) Define a function called Date_Write which uses printf to 
//  display the value of a date in format "%d-%d-%d", with day followed by month
//  followed by year.
// 
//  Parameters:
//      d - an integer which will represent the day.
//      m - an integer which will represent the month.
//      y - an integer which will represent the year.
//
//  Returns:
//      Nothing.

void Date_Write(int d, int m, int y)
{
    printf("%d-%d-%d", d, m, y);
}

//  (Task 3) Define a function called Date_Compare which compares two
//  dates. Your implementation may assume that these values are valid dates.
// 
//  Parameters:
//      d1, m1, y1 - Three integers representing the first date. 
//      d2, m2, y2 - Three integers representing the second date. 
//
//  Returns:
//      An int which is:
//      -1  if the date represented by (d1, m1, y1) is before that 
//          represented by (d2, m2, y2);
//      0   if the two values represent the same date;
//      +1  otherwise.

int Date_Compare(int d1, int m1, int y1, int d2, int m2, int y2)
{
    if(y1 == y2)
    {
        if(m1 == m2)
        {
            if(d1 == d2)
            {
                return 0;
            }

            if(d1 < d2)
            {
                return -1;
            }
            else
            {
                return 1;
            }
        }

        if(m1 < m2)
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

    if(y1 < y2)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

//  (Task 4) Implement the Date_Valid function which determines if the 
//  supplied date is valid:
//  *   Year must be greater than or equal to 1.
//  *   Month must between 1 and 12 inclusive.
//  *   Day must be at least 1, with upper limits given below:
//      30 days: September, April June, and November.
//      31 days: January, March, May, July, August, October, December.
//      28 or 29: February (usually 28, but 29 in a leap year).
//  
//  A year is a leap year if it is divisible by 400, or if it is
//  divisible by 4 but not divisible by 100.
//  
//  Parameters:
//     d, m, y - three integers representing a date.
//
//  Returns:
//      Returns true if and only if the supplied date is valid according to 
//      the definition listed above.

bool Is_A_Leap_Year(int y)
{
    if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
    {
        return TRUE;
    }

    return FALSE;
}

int Get_Length_Of_Month(int m, bool isALeapYear)
{
    switch (m)
    {
        // Jan
        case 1:
            return 31;

        // Feb
        case 2:
            break;

        // Mar
        case 3:
            return 31;

        // Apr
        case 4:
            return 30;

        // May
        case 5:
            return 31;

        // Jun
        case 6:
            return 30;

        // Jul
        case 7:
            return 31;

        // Aug
        case 8:
            return 31;

        // Sep
        case 9:
            return 30;

        // Oct
        case 10:
            return 31;
    
        // Nov
        case 11:
            return 30;
    
        // Dec
        case 12:
            return 31;   

        // Not Valid
        default:
            return -1;
    }

    // Only February can reach this section of the code
    if(isALeapYear)
    {
        // Leap Year
        return 29;
    }
    else
    {
        return 28;
    }
}

bool Date_Valid (int d, int m, int y)
{
    if(y > 1
       && (m > 0 && m < 13)
       && (d > 0 && d <= Get_Length_Of_Month(m, Is_A_Leap_Year(y))))
    {
        return TRUE;
    }

    return FALSE;
}

//  (Task 5) Define a function called Date_Match which compares a query date to
//  a list of dates. The function returns the position of the first object in 
//  the list which satisfies a designated criterion.
//
//  If criterion is -1, then the function returns the position of 
//  the first date in the list that comes before the query date. If criterion is
//  +1, then the function returns the position of the first date in the list 
//  that comes after the query date. If criterion is 0, then the function returns 
//  the position of the first date in the list that is equal to the query.
// 
//  Parameters:
//      d, m, y    - Three integers which represents a query date.
//
//      dd, mm, yy - Three integer arrays, holding respective days, months and 
//                   years of a list of dates.
//
//      num_dates  - an int which tells the function how many elements there 
//                   are in the array.
//
//      criterion  - an int (guaranteed to be -1, 0, or 1) which defines the 
//                   matching criterion. 
//
//  Returns:
//      The integer position of the first item in the list which satisfies the 
//      matching criterion.
//
//      If num_dates is equal to or less than 0, the function returns -1.
//
//      If the query is not a valid date, the function returns -1.
//
//      If there is integer i for which 
//          0 <= i < num_dates,  
//      and
//          Date_Valid( dd[i], mm[i], yy[i] )
//      and
//          Date_Compare( dd[i], mm[i], yy[i], d, m, y ) == criterion
//      then 
//          the function returns i.
//
//      Otherwise the function returns -1.

int Date_Match(int d, int m, int y, int dd[], int mm[], int yy[], int num_dates, int criterion)
{
    if(num_dates > 0 && Date_Valid(d, m, y) == TRUE)
    {
        for(int i = 0; i < num_dates; i++)
        {
            if(Date_Valid(dd[i], mm[i], yy[i])
               && Date_Compare(d, m, y, dd[i], mm[i], yy[i]) == criterion)
            {
                return i;
            }
        }
    }

    return -1;
}

//------------------------------------------------------------------------------
#define MAX_ITEMS (100)

int main(void)
{
    int query_day, query_month, query_year;
    printf("Input query date using format %s: ", "%d-%d-%d");
    bool test = Date_Read(&query_day, &query_month, &query_year);

    printf("Did it work? %d", test);

    // int dd[MAX_ITEMS], mm[MAX_ITEMS], yy[MAX_ITEMS];
    // int num_items;

    // // Get number of ref_dates.
    // printf("Please enter number of items (up to %d) that will be processed: ", MAX_ITEMS);
    // scanf("%d", &num_items);

    // // if number of ref_dates exceeds array size, restrict it to that value.
    // if (num_items > MAX_ITEMS)
    // {
    //     num_items = MAX_ITEMS;
    // }

    // for (int i = 0; i < num_items; i++)
    // {
    //     printf("Please enter item %d of %d using format %s, with day first and year last: ", (i + 1), num_items, "%d-%d-%d");
    //     bool ok = Date_Read(&dd[i], &mm[i], &yy[i]);

    //     if ( ! ok ) {
    //         num_items = i;
    //         break;
    //     }
    // }

    // for (int i = 0; i < num_items; i++)
    // {
    //     Date_Write(dd[i], mm[i], yy[i]);

    //     if (!Date_Valid(dd[i], mm[i], yy[i]))
    //     {
    //         printf(" is not valid.\n");
    //         continue;
    //     }

    //     int cmp = Date_Compare(dd[i], mm[i], yy[i], query_day, query_month, query_year);

    //     if (cmp < -1 || cmp > 1)
    //     {
    //         printf("Error!!! Date_Compare is broken.\n");
    //         exit(1);
    //     }

    //     char * labels[] = { 
    //         "less than", 
    //         "equal to", 
    //         "greater than" 
    //     };

    //     printf(" is %s ", labels[cmp + 1]);
    //     Date_Write(query_day, query_month, query_year);
    //     printf("\n");
    // }

    // const int criterion = -1;

    // int match_idx = Date_Match(
    //     query_day, query_month, query_year, 
    //     dd, mm, yy, 
    //     num_items, criterion
    // );

    // if (match_idx >= 0)
    // {
    //     printf("The first valid date matching the search criterion is ");
    //     Date_Write(dd[match_idx], mm[match_idx], yy[match_idx]);
    // }
    // else
    // {
    //     printf("There is no valid date matching the search criterion.\n");
    // }

    return 0;
}
