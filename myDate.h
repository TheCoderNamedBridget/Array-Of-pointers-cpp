
//written by Bridget Naylor for lab 2
#ifndef myDate_H
#define myDate_H
#include <iostream>
using namespace std;


class myDate 
{
    private:
        int month;
        int day;
        int year;
    
    public:
        myDate();//set date to may, 11, 1959
        myDate( int M, int D, int Y );//set date to parameter values
        void display();//display date in format (month, day, year) no endl after
        void increaseDate( int N );//increment date by n days
        void decreaseDate( int N );//decrement date by n days
        int daysBetween( myDate D );// return number of day between this date and date D. D - this date
        int getMonth();//return the month in int forma
        int getDay();//return the day of the month
        int getYear();//return the yearint dayOfYear();//return he number of days since the current year began
        int dayOfYear();//return number of days since the year began
        string dayName();//reutrn monday, tuesday
    
    
};

#endif
