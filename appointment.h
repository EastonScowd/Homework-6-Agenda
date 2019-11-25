#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>


using namespace std;

class Appointment{
public:
    Appointment(){
        day = 1 ;
        month = 1 ;
        year = 1 ; 
        time = 0 ; 
        duration = 1 ; 
        title = "N/A" ; 
        date = "N/A" ; 
    }
    int getMonth() ; 
    void setMonth(int newMonth) ; 
    int getDay() ; 
    void setDay(int newDay) ; 
    int getYear() ;
    void setYear(int newYear) ; 
    int getTime() ;
    void setTime(int newTime) ; 
    int getDuration();
    void setDuration(int newDuration) ; 
    string getTitle() ;
    void setTitle(string newTitle) ; 
    string getDate() ; 
    void setDate(int year, int month, int day) ;

    string militaryToStandard(int time); 
    int standardToMilitary(string time);
    //bool operator ==(const Appointment &first, const Appointment &second);

private:
    string title ; 
    string date ; 
    int month ; 
    int day ; 
    int year ; 
    int time ; 
    int duration ; 
} ;

#endif