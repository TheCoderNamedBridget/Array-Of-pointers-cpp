/*
Bridget Naylor
Date:
Calss
Honesty statement:
*/
#include <stdio.h>
#include "myDate.h"
#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
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
        string display();//display date in format (month, day, year) no endl after
        void increaseDate( int N );//increment date by n days
        void decreaseDate( int N );//decrement date by n days
        int daysBetween( myDate D );// return number of day between this date and date D. D - this date
        int getMonth();//return the month in int forma
        int getDay();//return the day of the month
        int getYear();//return the yearint dayOfYear();//return he number of days since the current year began
        int dayOfYear();//return number of days since the year began
        string dayName();//reutrn monday, tuesday
        myDate returnDateBetween();//return a date between 2 dates
};

int Greg2Julian( int mon, int day, int year )//pass m, d, y return julian
{
    int JD = day - 32075 + 1461*(year + 4800+(mon-14)/12)/4+367*
        (mon-2-(mon-14)/12*12)/12-3*((year+4900+(mon-14)/12)/100)/4;
    return JD;
}

void Julian2Greg( int JD, int & month, int & day, int & year )//pass in julian date and get m, d, y through parameter list and pass by ref
{
    int L;
    int N;
    int J;
    int K;
    int I;
    L = JD + 68569;
    N = 4 * L / 146097;
    L = L - ( 146097 * N + 3 ) / 4;
    I = 4000 * ( L + 1 ) / 1461001;
    L = L - 1461 * I / 4 + 31;
    J = 80 * L / 2447;
    K = L - 2447 * J / 80;
    L = J / 11;
    J = J + 2 - 12 * L;
    I = 100 * ( N - 49 ) + I + L;
    
    year = I;
    month = J;
    day = K;
    //cout<<month<<" "<<day<<" "<<year<<endl;
}

myDate::myDate()
{
    month = 5;
    day = 11;
    year = 1959;
}

myDate::myDate( int M, int D, int Y )
{
    int m1, d1, y1 = 0;
    //Use gregorian 
    //int JD = G2J( m, d, y );
    //int jd2;
    //j2g( jd, m1, y1);
    if ( M != m1 || D != d1 || Y != y1 )
    {
        month = 5;
        day = 11;
        year = 1959;
    }
    month = M;
    day = D;
    year = Y;
}


string myDate::display()
{
    string m;
    if ( month == 1 )
    {
        m = "January";
    }
    else if ( month == 2 )
    {
        m = "February";
    }
    else if ( month == 3 )
    {
        m = "March";
    }
    else if ( month == 4 )
    {
        m = "April";
    }
    else if ( month == 5 )
    {
        m = "May";
    }
    else if ( month == 6 )
    {
        m = "June";
    }
    else if ( month == 7 )
    {
        m = "July";
    }
    else if ( month == 8 )
    {
        m = "August";
    }
    else if ( month == 9 )
    {
        m = "September";
    }
    else if ( month == 10 )
    {
        m = "October";
    }
    else if ( month == 11 )
    {
        m = "November";
    }
    else if ( month == 12 )
    {
        m = "December";
    }
    string days = to_string(day);
    string years = to_string(year);
    string date =  m + " " + days + ", " + years;
    return( date );
}

void myDate::increaseDate( int n )
{
    int gregDate = Greg2Julian( month, day, year ) + n;
    Julian2Greg( gregDate, month, day, year );
    //turn current date into a julian date add n 
    //convert bak to gregorian date
}

void myDate::decreaseDate( int n )
{
    //turn current date into a julian date add n 
    //convert bak to gregorian date
    int gregDate = Greg2Julian( month, day, year) - n;
    Julian2Greg( gregDate, month, day, year );
}

int myDate::daysBetween( myDate D )
{
    // turn both of the dates into julian dates then subtract 
    //original from D
    int gregDate1 = Greg2Julian( D.getMonth(), D.getDay(), D.getYear() );
    int gregDate2 = Greg2Julian( month, day, year );
    return gregDate1 - gregDate2;
}

int myDate::getMonth()
{
    return month;
}

int myDate::getDay()
{
    return day;
}

int myDate::getYear()
{
    return year;
}

int myDate::dayOfYear()//return number of days since current year began
{
    
    return 1 + Greg2Julian( month, day, year ) - Greg2Julian( 1, 1, year );
}

string myDate::dayName()//return day of week, mondy, tuesday,...
{
    //figure out today's name of the day
    //convert to julian
    //then use the modulo to calculate other dates day of the week
    //9/22/2020 = tuesday
    string dayName = "";
    int tuesdayRemainder = Greg2Julian( 9, 22, 2020 ) % 7;
    //cout<<tuesdayRemainder;
    int gregDate = Greg2Julian( month, day, year );
    if ( gregDate % 7 == tuesdayRemainder )
    {
        dayName = "Tuesday";
    }
    else if ( gregDate % 7 == tuesdayRemainder + 1 )
    {
        dayName = "Wednesday";
    }
    else if ( gregDate % 7 == tuesdayRemainder + 2 )
    {
        dayName = "Thursday";
    }
    else if ( gregDate % 7 == tuesdayRemainder + 3 )
    {
        dayName = "Friday";
    }
    else if ( gregDate % 7 == tuesdayRemainder + 4 )
    {
        dayName = "Saturday";
    }
    else if ( gregDate % 7 == tuesdayRemainder + 5 )
    {
        dayName = "Sunday";
    }
    else if ( gregDate % 7 == tuesdayRemainder - 1 )
    {
        dayName = "Monday";
    }
    return dayName;
}


// myDate myDate::returnDateBetween( myDate first, myDate second )
// {
    
//     if ( ( first.getYear() < second.getYear() ) ||  ( first.getYear() == second.getYear() && first.getMonth() < second.getMonth() ) || 
//     ( first.getYear() == second.getYear() && first.getMonth() == second.getMonth() && first.getDay() < second.getDay() )
//     {
        
//         myDate newDate( first.getMonth(), first.getDay() + 1, first.getYear());
//         return newDate;
//     }
//     else ( ( second.getYear() < first.getYear() ) ||  ( second.getYear() == first.getYear() && second.getMonth() < first.getMonth() ) || 
//     ( second.getYear() == first.getYear() && second.getMonth() == first.getMonth() && second.getDay() < first.getDay() )
//     {
        
//         myDate newDateSecond( second.getMonth(), second.getDay() + 1, second.getYear());
//         return newDateSecond;
//     }
// }
//Create student struct
struct Student
{
    char name[10];//cstring means index 9 is '/0', can fit 9 characters
    int SID;//student id
    char grade;
    myDate birthday;
    string hometown;
};//remember structs are like classes and end with semicolons

void populate( Student *records[] )
{
    for ( int i = 0; i < 10; i++ )
    {
        records[i] = new Student;//allocate students
    }
    myDate birthdate( 10, 10, 2000 );
    records[0] -> SID = 1234;
    cout<<"thesid 0 "<<records[0] -> SID<<endl;
    strcpy(records[0] -> name, "Stacy Lawerence");
    records[0] -> hometown = "Burlingame";
    records[0] -> birthday = birthdate;
    //birthdate.display();
    records[0] -> grade = 'F';
    
    
    myDate birthdate1( 7, 19, 2000 );
    records[1] -> SID = 5678;
    strcpy(records[1] -> name, "Eninem D12");
    records[1] -> hometown = "8MileRanch";
    records[1] -> birthday = birthdate1;
    //birthdate.display();
    records[1] -> grade = 'A';
    
    myDate birthdate2( 3, 14, 2002 );
    records[2] -> SID = 9101;
    strcpy(records[2] -> name, "Timmy Narkowitz");
    records[2] -> hometown = "CottonCandyTown";
    records[2] -> birthday = birthdate2;
    //birthdate.display();
    records[2] -> grade = 'B';
    
    myDate birthdate3( 6, 21, 2001 );
    records[3] -> SID = 1213;
    strcpy(records[3] -> name, "Felipe Smith");
    records[3] -> hometown = "Burmingham";
    records[3] -> birthday = birthdate3;
    //birthdate.display();
    records[3] -> grade = 'A';
    
    myDate birthdate4( 12, 2, 1999 );
    records[4] -> SID = 4252;
    strcpy(records[4] -> name, "Li You Hua");
    records[4] -> hometown = "Shan Gong";
    records[4] -> birthday = birthdate4;
    //birthdate.display();
    records[4] -> grade = 'C';
    
    myDate birthdate5( 8, 11, 2001 );
    records[5] -> SID = 5663;
    strcpy(records[5] -> name, "Isiah Palo");
    records[5] -> hometown = "Jamestown";
    records[5] -> birthday = birthdate5;
    //birthdate.display();
    records[5] -> grade = 'D';
    
    myDate birthdate6( 10, 1, 2000 );
    records[6] -> SID = 2244;
    strcpy(records[6] -> name, "Cecilia KimKim");
    records[6] -> hometown = "Singapore";
    records[6] -> birthday = birthdate6;
    //birthdate.display();
    records[6] -> grade = 'A';
    
    myDate birthdate7( 6, 4, 2003 );
    records[7] -> SID = 5344;
    strcpy(records[7] -> name, "Pengu Fang");
    records[7] -> hometown = "JKTown";
    records[7] -> birthday = birthdate7;
    //birthdate.display();
    records[7] -> grade = 'D';
    
    myDate birthdate8( 1, 21, 2002 );
    records[8] -> SID = 4523;
    strcpy(records[8] -> name, "Kylie Polar");
    records[8] -> hometown = "Anchorage";
    records[8] -> birthday = birthdate8;
    //birthdate.display();
    records[8] -> grade = 'B';
    
    myDate birthdate9( 5, 29, 2000 );
    records[9] -> SID = 6575;
    strcpy(records[9] -> name, "Swati Thurumaran");
    records[9] -> hometown = "Bangali";
    records[9] -> birthday = birthdate9;
    //birthdate.display();
    records[9] -> grade = 'B';

}

void display( Student *ptrs[], int size )
{
    cout<<left<< setw(20) <<"Name:" <<  ' ' <<left<<setw(20) << "SID:" <<   ' ' <<left<<setw(20) <<"Grade:" << 
      ' ' <<left<<setw(20) <<"Birthday:" <<  ' ' <<left<<setw(20) <<"Hometown:" <<   ' '<< endl << endl;
    for ( int i = 0; i < size; i++ )
    {
        
        cout<<left<<setw(20) << ptrs[i] -> name<<  ' ' <<left<<setw(20)<< ptrs[i]->SID <<   ' ' <<left<<setw(20) <<ptrs[i] -> 
        grade<<   ' ' <<left<<setw(20) << ptrs[i] -> birthday.display() <<  ' '<<left<<setw(20) <<ptrs[i]->hometown<<   ' '<< endl << endl;
        
    }
    
}

//Sorting functions

void sortByName( int size, Student *ptrs[] )
{
}

void sortByID( int size, Student *ptrs[] )
{
    bool swapped = true;
    while ( swapped )
    {
        swapped = false;
        for ( int i = 0; i < size - 1; i++ )
        {
            
            Student * student1 = ptrs[i];
            Student * student2 = ptrs[i + 1];
            //cout<<"valueStudent 1 = "<<student1->name<<" grade "<<student1->grade<<" minStudent2 = "<<student2->name<<" grade "<<student2 ->grade<<endl;
            if ( student1 -> SID > student2 -> SID )
            {
                Student * temp = student1;
                
                ptrs[i] = student2;
                ptrs[i + 1] = temp;
                swapped = true;
            }
            cout<<" Swapped "<<swapped<<endl;
        }
    }
}

void sortByGrade( int size, Student *ptrs[] )
{
    bool swapped = true;
    while ( swapped )
    {
        swapped = false;
        for ( int i = 0; i < size - 1; i++ )
        {
            
            Student * student1 = ptrs[i];
            Student * student2 = ptrs[i + 1];
            //cout<<"valueStudent 1 = "<<student1->name<<" grade "<<student1->grade<<" minStudent2 = "<<student2->name<<" grade "<<student2 ->grade<<endl;
            if ( student1 -> grade > student2 -> grade )
            {
                Student * temp = student1;
                
                ptrs[i] = student2;
                ptrs[i + 1] = temp;
                swapped = true;
            }
            cout<<" Swapped "<<swapped<<endl;
        }
    }
}

void sortByBirthday( int size, Student *ptrs[] )
{
    bool swapped = true;
    while ( swapped )
    {
        swapped = false;
        for ( int i = 0; i < size - 1; i++ )
        {
            
            Student * student1 = ptrs[i];
            Student * student2 = ptrs[i + 1];
            //cout<<"valueStudent 1 = "<<student1->name<<" birthday "<<student1->birthday.display()<<" minStudent2 = "<<student2->name<<" birthday "<<student2 ->birthday.display()<<endl;
            if ( ( student1->birthday.getYear() > student2->birthday.getYear() ) 
            ||  ( student1->birthday.getYear() == student2->birthday.getYear() && student1->birthday.getMonth() > student2->birthday.getMonth() ) 
            || ( student1->birthday.getYear() == student2->birthday.getYear() 
            && student1->birthday.getMonth() == student2->birthday.getMonth() && student1->birthday.getDay() > student2->birthday.getDay() ))
            {
                Student * temp = student1;
                ptrs[i] = student2;
                ptrs[i + 1] = temp;
                swapped = true;
            }
            cout<<" Swapped "<<swapped<<endl;
        }
    }
}

void sortByHometown( int size, Student *ptrs[] )
{
    // int iterationsOverStrings = false;
    // for ( int i = 0; i < size - 1; i++ )
    // {
    //     if ( ( ptrs[i]->hometown.compare(ptrs[i]->hometown ) ) < 0 )//1 smaller than 2
    //     {
    //         first = false;
    //     }
    //     else 
    //     {
    //         first = true;
    //     }
        
    //     if ( first )
    //     {
            
    //     }
    // }
    
}

int main( )
{
    const int numStudents = 10;
    
    Student *arrayOfStudentPointers[numStudents];//size 10
    populate( arrayOfStudentPointers );
    
    //cout<<"Variable Cray "<<arrayOfStudentPointers[0] -> name<<endl;
    //display( arrayOfStudentPointers, numStudents );
    
    int userInput;
    cout<<"1) Display list sorted by Name"<<endl;
    cout<<"2) Display list sorted by Student ID"<<endl;
    cout<<"3) Display list sorted by Grade"<<endl;
    cout<<"4) Display list sorted by Birthday"<<endl;
    cout<<"5) Display list sorted by Hometown"<<endl;
    cout<<"6) Exit"<<endl;
    cin>>userInput;
    if ( userInput == 6)
    {
        exit;
    }
    else if (userInput == 5 )
    {
        //sort by hometown
        sortByHometown( numStudents, arrayOfStudentPointers );
        display( arrayOfStudentPointers, numStudents );
    }
    else if (userInput == 4 )//Done :D
    {
        //sort by birthday
        sortByBirthday( numStudents, arrayOfStudentPointers );
        display( arrayOfStudentPointers, numStudents );
    }
    else if (userInput == 3 )//Done :D
    {
        //sort by grade
        sortByGrade( numStudents, arrayOfStudentPointers );
        display( arrayOfStudentPointers, numStudents );
    }
    else if (userInput == 2 )//Done :D
    {
        //sort by ID
        sortByID( numStudents, arrayOfStudentPointers );
        display( arrayOfStudentPointers, numStudents );
    }
    else if (userInput == 1 )
    {
        //sort by name
        sortByName( numStudents, arrayOfStudentPointers );
        display( arrayOfStudentPointers, numStudents );
    }
    

    return 0;
}


