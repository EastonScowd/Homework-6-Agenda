/**
 *   @file: appointment_main.cc
 * @author: Easton Scowden
 *   @date: 11/14/2019
 *  @brief: A program that returns information about an appointment using classes. 
 */

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
private:
    string title ; 
    string date ; 
    int month ; 
    int day ; 
    int year ; 
    int time ; 
    int duration ; 
} ;
//function prototypes

int main(int argc, char const *argv[]) {
    Appointment one ; 
    cout << one.getDate() ;  
    
    return 0;
}// main

//Add class functions here
int Appointment::getDay(){
    return day ; 
}

void Appointment::setDay(int newDay){
    if(newDay > 0 && newDay <= 31){
        day = newDay ; 
    }
}

int Appointment::getMonth(){
    return month ;
}

void Appointment::setMonth(int newMonth){
    if(newMonth > 0 && newMonth <= 12){
        month = newMonth ;
    } 
}

int Appointment::getYear(){
    return year ;
}

void Appointment::setYear(int newYear){
    if(newYear > 0 && newYear <= 9999){
        year = newYear ;
    } 
}

int Appointment::getTime(){
    return time ;
}

void Appointment::setTime(int newTime){
    if(newTime >= 0 && newTime <= 1159){
        time = newTime ;
    } 
}

int Appointment::getDuration(){
    return duration ;
}

void Appointment::setDuration(int newDuration){
    if(newDuration > 0 && newDuration <= 9999){
        duration = newDuration ;
    } 
}

string Appointment::getTitle(){
    return title ;
}

void Appointment::setTitle(string newTitle){
    title = newTitle ; 
}

string Appointment::getDate(){
    string y = to_string(getYear()) ; 
    string m = to_string(getMonth()) ; 
    string d = to_string(getDay()) ;

    return y + "-" + m + "-" + d ; 
}