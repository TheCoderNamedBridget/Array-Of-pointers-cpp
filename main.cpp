/*
Bridget Naylor
Date:10/6/2020
Class: CECS 282 Section 04
Honesty statement:
I certify that this program is my own original work. I did not copy any part of this program from
any other source. I further certify that I typed each and every line of code in this program.
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
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


myDate returnDateBetween( myDate first, myDate second )//use random number generate fr this
{
    myDate biggerDate;
    int randomMonth;
    int randomDay;
    int randomYear;
    
    if ( ( first.getYear() < second.getYear() ) ||  ( first.getYear() == second.getYear() && first.getMonth() < second.getMonth() ) || 
    ( first.getYear() == second.getYear() && first.getMonth() == second.getMonth() && first.getDay() < second.getDay() ))
    {
        biggerDate = second;
        randomYear = (rand() % (second.getYear() - first.getYear())) + first.getYear();
    }
    else if( ( second.getYear() < first.getYear() ) ||  ( second.getYear() == first.getYear() && second.getMonth() < first.getMonth() ) || 
    ( second.getYear() == first.getYear() && second.getMonth() == first.getMonth() && second.getDay() < first.getDay() ))
    {
        
        biggerDate = first;
        randomYear = (rand() % (first.getYear() - second.getYear())) + second.getYear();
    }
    bool dayValid = false;
    while( !dayValid )
    {
        randomMonth = (rand() % 11) + 1;
        randomDay = (rand() % 30) + 1;
        myDate dateBetween( randomMonth, randomDay, randomYear);
        myDate defaultDate( 5, 11, 1959);
        if ( dateBetween.getYear() != defaultDate.getYear() && dateBetween.getMonth() != defaultDate.getMonth() && dateBetween.getDay() != defaultDate.getDay() )
        {
            return dateBetween;
        }
    }
    
    
}
//Create student struct
struct Student
{
    char name[15];//cstring means index 9 is '/0', can fit 9 characters
    int SID;//student id
    char grade;
    myDate birthday;
    string hometown;
};//remember structs are like classes and end with semicolons

void populate( Student *records[] )//generate ids randomly
{
    string hometowns[10]={"Burlingame", "MileRanch", "CottonCandyTown", "Burmingham", "Shan Gong", "Jamestown", "Singapore", "JKTown", "Anchorage", "Bangali"};
    char grades[10] = {'F','B','A','F','A','A','B','C','D','A'};
    char names[11][20] = { "Stacy Lawerence", "Eninem D12", "Timmy Narkowitz", "Felipe Smith", "Li You Hua", "Isiah Palo", "Cecilia KimKim", "Pengu Fang", "Kylie Polar", "Swati Thurumaran"};
    myDate bday1( 1, 1, 1998 );
    myDate bday2( 12, 28, 2001 );
    myDate birthdayChosen;
    srand(time(NULL));
    for ( int i = 0; i < 10; i++ )
    {
        birthdayChosen = returnDateBetween( bday1, bday2 );
        int randomID = rand() % 8999 + 1000;
        records[i] = new Student;//allocate students
        records[i] -> SID = randomID;
        records[i]->birthday = birthdayChosen;
        records[i]->hometown = hometowns[i];
        records[i]->grade = grades[i];
        strcpy(records[i] -> name, names[i]);
    }
}

void display( Student *ptrs[], int size )
{
    cout<<left<< setw(20) <<"Name:" <<  ' ' <<left<<setw(20) << "SID:" <<   ' ' <<left<<setw(20) <<"Grade:" << 
      ' ' <<left<<setw(20) <<"Birthday:" <<  ' ' <<left<<setw(20) <<"Hometown:" <<   ' '<<endl;
    for ( int i = 0; i < size; i++ )
    {
        
        cout<<left<<setw(20) << ptrs[i] -> name<<  ' ' <<left<<setw(20)<< ptrs[i]->SID <<   ' ' <<left<<setw(20) <<ptrs[i] -> 
        grade<<   ' ' <<left<<setw(20) << ptrs[i] -> birthday.display() <<  ' '<<left<<setw(20) <<ptrs[i]->hometown<<   ' '<< endl;
        
    }
    
}

//Sorting functions
void sortByName( int size, Student *ptrs[] )
{
    bool swapped = true;
    while ( swapped )
    {
        swapped = false;
        for ( int i = 0; i < size - 1; i++ )
        {
            bool First = strcmp( ptrs[i]->name, ptrs[1]->name) > 0;
            if ( strcmp( ptrs[i]->name, ptrs[i+1]->name) > 0 )
            {
                Student * temp = ptrs[i];
                
                ptrs[i] = ptrs[i+1];
                ptrs[i+1] = temp;
                swapped = true;
                cout<<"ptrs[0]"<<ptrs[i]->name<<endl;;
            }
        }
    }
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
            //cout<<"valueStudent 1 = "<<student1->name<<" SID "<<student1->SID<<" minStudent2 = "<<student2->name<<" SID "<<student2 ->SID<<endl;
            if ( student1 -> SID > student2 -> SID )
            {
                Student * temp = student1;
                
                ptrs[i] = student2;
                ptrs[i + 1] = temp;
                swapped = true;
            }
            //cout<<" Swapped "<<swapped<<endl;
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
    bool swapped = true;
    while ( swapped )
    {
        swapped = false;
        for ( int i = 0; i < size - 1; i++ )
        {
            if ( ptrs[i]->hometown > ptrs[i + 1]->hometown )
            {
                Student * temp = ptrs[i];
                ptrs[i] = ptrs[i + 1];
                ptrs[i + 1] = temp;
                swapped = true;
            }
        }
    }
}

int main( )
{
    const int numStudents = 10;
    
    Student *arrayOfStudentPointers[numStudents];//size 10
    populate( arrayOfStudentPointers );
    
    //cout<<"Variable Cray "<<arrayOfStudentPointers[0] -> name<<endl;
    //display( arrayOfStudentPointers, numStudents );
    
    int userInput;
    bool quit = false;
    while ( !quit )
    {
        cout<<"1) Display list sorted by Name"<<endl;
        cout<<"2) Display list sorted by Student ID"<<endl;
        cout<<"3) Display list sorted by Grade"<<endl;
        cout<<"4) Display list sorted by Birthday"<<endl;
        cout<<"5) Display list sorted by Hometown"<<endl;
        cout<<"6) Exit"<<endl;
        cin>>userInput;
        if ( userInput == 6)
        {
            quit = true;
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
    }
    
    

    return 0;
}




