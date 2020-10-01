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
#include <iomanip>
using namespace std;

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
    myDate birthdate( 6, 21, 2002 );
    records[0] -> SID = 1234;
    strcpy(records[0] -> name, "Stacy Lawerence");
    records[0] -> hometown = "Burlingame";
    records[0] -> birthday = birthdate;
    //birthdate.display();
    records[0] -> grade = 'F';
    
    
    myDate birthdate1( 6, 21, 2002 );
    records[1] -> SID = 1234;
    strcpy(records[1] -> name, "Eninem D12");
    records[1] -> hometown = "8MileRanch";
    records[1] -> birthday = birthdate;
    //birthdate.display();
    records[1] -> grade = 'A';
    
    myDate birthdate2( 6, 21, 2002 );
    records[2] -> SID = 1234;
    strcpy(records[2] -> name, "Timmy Narkowitz");
    records[2] -> hometown = "CottonCandyTown";
    records[2] -> birthday = birthdate;
    //birthdate.display();
    records[2] -> grade = 'B';
    
    myDate birthdate3( 6, 21, 2002 );
    records[3] -> SID = 1234;
    strcpy(records[3] -> name, "Felipe Smith");
    records[3] -> hometown = "Burmingham";
    records[3] -> birthday = birthdate;
    //birthdate.display();
    records[3] -> grade = 'A';
    
    myDate birthdate4( 6, 21, 2002 );
    records[4] -> SID = 1234;
    strcpy(records[4] -> name, "Li You Hua");
    records[4] -> hometown = "Shan Gong";
    records[4] -> birthday = birthdate;
    //birthdate.display();
    records[4] -> grade = 'C';
    
    myDate birthdate5( 6, 21, 2002 );
    records[5] -> SID = 1234;
    strcpy(records[5] -> name, "Isiah Palo");
    records[5] -> hometown = "Jamestown";
    records[5] -> birthday = birthdate;
    //birthdate.display();
    records[5] -> grade = 'D';
    
    myDate birthdate6( 6, 21, 2002 );
    records[6] -> SID = 1234;
    strcpy(records[6] -> name, "Cecilia KimKim");
    records[6] -> hometown = "Singapore";
    records[6] -> birthday = birthdate;
    //birthdate.display();
    records[6] -> grade = 'A';
    
    myDate birthdate7( 6, 21, 2002 );
    records[7] -> SID = 1234;
    strcpy(records[7] -> name, "Pengu Fang");
    records[7] -> hometown = "JKTown";
    records[7] -> birthday = birthdate;
    //birthdate.display();
    records[7] -> grade = 'D';
    
    myDate birthdate8( 6, 21, 2002 );
    records[8] -> SID = 1234;
    strcpy(records[8] -> name, "Kylie Polar");
    records[8] -> hometown = "Anchorage";
    records[8] -> birthday = birthdate;
    //birthdate.display();
    records[8] -> grade = 'B';
    
    myDate birthdate9( 6, 21, 2002 );
    records[9] -> SID = 1234;
    strcpy(records[9] -> name, "Swati Thurumaran");
    records[9] -> hometown = "Bangali";
    records[9] -> birthday = birthdate;
    //birthdate.display();
    records[9] -> grade = 'B';

}

void display( Student *ptrs[], int size )
{
    cout<<left<< setw(20) <<"Name:" <<  ' ' <<left<<setw(20) << "SID:" <<   ' ' <<left<<setw(20) <<"Grade:" << 
      ' ' <<left<<setw(20) <<"Birthday:" <<  ' ' <<left<<setw(20) <<"Hometown:" <<   ' '<< endl << endl;
    for ( int i = 0; i < size; i++ )
    {
        
        cout<<left<<setw(20) << ptrs[i] -> name<<  ' ' <<left<<setw(20)<< ptrs[i]-> SID <<   ' ' <<left<<setw(20) <<ptrs[i] -> 
        grade<<   ' ' <<left<<setw(20) << ptrs[i] -> grade <<  ' '<<left<<setw(20) <<ptrs[i]->hometown<<   ' '<< endl << endl;
        
    }
    
}

int main()
{
    const int numStudents = 10;
    
    Student *arrayOfStudentPointers[numStudents];//size 10
    populate( arrayOfStudentPointers );
    //display( arrayOfStudentPointers, numStudents );
    
    int userInput;
    cout<<"1) Display list sorted by Name"<<endl;
    cout<<"2) Display list sorted by Student ID"<<endl;
    cout<<"3) Display list sorted by Grade"<<endl;
    cout<<"4) Display list sorted by Birthday"<<endl;
    cout<<"5) Display list sorted by Hometown"<<endl;
    cout<<"6) Exit"<<endl;
    cin>>userInput;
    
    

    return 0;
}
