#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "appointment.h" 

using namespace std;

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
    if(newTime >= 0 && newTime <= 2400){
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

string Appointment::militaryToStandard(int time){
    int hours ; 
    int minutes ; 
    string minutesString ;  
    string amPM ; 
    string standardT ; 

    if(time >= 1300 && time < 2360){
        hours = (time - 1200) / 100 ; 
        minutes = (time - 1200) - (hours * 100) ;
        minutesString = to_string(minutes) ;  
        amPM = " PM" ; 
        if(minutes < 10){
            minutesString = "0" + to_string(minutes) ; 
        }
        standardT = to_string(hours) + ":" + minutesString +  amPM ;
    } else if (time == 2400 || time == 0){
        standardT = "12:00 AM" ; 
    } else if(time >= 100 && time < 1160){
        hours = time / 100 ; 
        minutes = time - (hours * 100) ; 
        amPM = " AM" ;
        minutesString = to_string(minutes) ; 
        if(minutes < 10){
            minutesString = "0" + to_string(minutes) ; 
        }
        standardT = to_string(hours) + ":" + minutesString +  amPM ;
    } else if(time == 1200){
        standardT = "12:00 PM" ; 
    } else if(time > 1200 && time < 1260) {
        hours = time / 100 ; 
        minutes = time - (hours * 100) ; 
        amPM = " PM" ;
        minutesString = to_string(minutes) ; 
        if(minutes < 10){
            minutesString = "0" + to_string(minutes) ; 
        }
        standardT = to_string(hours) + ":" + minutesString +  amPM ;
    }
    return standardT ; 
}

int Appointment::standardToMilitary(string time){
    string militaryT ; 
    int returnTime ; 
    if(time.length() == 7){
        if(time.substr(5) == "AM"){
            militaryT += time[0] ;  
            militaryT += time.substr(2,2) ;
            returnTime = stoi(militaryT) ;
        } else if(time.substr(5) == "PM"){
            militaryT += time[0] ; 
            militaryT += time.substr(2,2) ;
            returnTime = stoi(militaryT) + 1200 ;  
        }
    }
    if(time.length() == 8){
        if(time.substr(0,2) == "12" && time.substr(6) == "AM"){
            militaryT += time.substr(3,2) ; 
            returnTime = stoi(militaryT) ; 
        } else if(time.substr(0,2) == "12" && time.substr(6) == "PM"){
            militaryT += "12" ; 
            militaryT += time.substr(3,2) ; 
            returnTime = stoi(militaryT) ;
        } else if(time.substr(6) == "AM"){
        militaryT += time.substr(0,2) ;  
        militaryT += time.substr(3,2) ;
        returnTime = stoi(militaryT) ;
        } else if(time.substr(6) == "PM"){
            militaryT += time.substr(0,2) ; 
            militaryT += time.substr(3,2) ;
            returnTime = stoi(militaryT) + 1200 ;  
        }
    }
    return returnTime ; 
}

bool operator ==(const Appointment &first, const Appointment &second){
    if(first.date == second.date && first.time == second.time && first.title == second.title && first.duration == second.duration){
        return true ; 
    }else{
        return false ;
    }  
}
string Appointment::getStandardTime(){
    return militaryToStandard(time) ; 
}