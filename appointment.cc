#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "appointment.h" 

using namespace std;

string leading(string str) ; // a function that gets rid of spaces before and after string
void nospaces(string &str) ; // a function that gets rid of all spaces in a string

// getters and setters for all the functions
// all are unique regarding their restrictions of what they can and can't be
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
    //  makes sure it is a valid time
    string timeS = to_string(newTime) ; 
    if(timeS.length() == 2 && (newTime > 0 && newTime < 60)){
        time = newTime ;
    }
    if(timeS.length() == 3 && (stoi(timeS.substr(1,2)) < 60 || stoi(timeS.substr(0,2)) < 24)){
        time = newTime ; 
    }
    if(timeS.length() == 4 && stoi(timeS.substr(2,2)) < 60){
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
    title = leading(newTitle) ; 
}

string Appointment::getDate(){
    string date ;
    string year1 = to_string(year) ;
    string month1 ;
    string day1 ;

    if(month < 10){
        month1 = "0" + to_string(month) ; 
    } else {
        month1 = to_string(month) ; 
    }

    if(day < 10){
        day1 = "0" + to_string(day) ; 
    } else {
        day1 = to_string(day) ; 
    }

    date = year1 + "-" + month1 + "-" + day1 ; 

    return date ;
}

void Appointment::setDate(int year, int month, int day){
    setYear(year) ; 
    setMonth(month) ; 
    setDay(day) ; 
}

string Appointment::militaryToStandard(int time){
    int hours ; 
    int minutes ; 
    string minutesString ;  
    string amPM ; 
    string standardT ; 
// compares time to values to determine AM or PM then forms a string based off of hours minutes and amPM 
    if(time >= 1300 && time < 2360){
        hours = (time - 1200) / 100 ; 
        minutes = (time - 1200) - (hours * 100) ;
        minutesString = to_string(minutes) ;  
        amPM = "PM" ; 
        if(minutes < 10){
            minutesString = "0" + to_string(minutes) ; 
        }
        standardT = to_string(hours) + ":" + minutesString +  amPM ;
    } else if (time == 2400 || time == 0){
        standardT = "12:00AM" ; 
    } else if(time < 59 && time > 0){
        amPM = "AM" ; 
        standardT = "12:" + to_string(time) + amPM ; 
    } else if(time >= 100 && time < 1160){
        hours = time / 100 ; 
        minutes = time - (hours * 100) ; 
        amPM = "AM" ;
        minutesString = to_string(minutes) ; 
        if(minutes < 10){
            minutesString = "0" + to_string(minutes) ; 
        }
        standardT = to_string(hours) + ":" + minutesString +  amPM ;
    } else if(time == 1200){
        standardT = "12:00PM" ; 
    } else if(time > 1200 && time < 1260) {
        hours = time / 100 ; 
        minutes = time - (hours * 100) ; 
        amPM = "PM" ;
        minutesString = to_string(minutes) ; 
        if(minutes < 10){
            minutesString = "0" + to_string(minutes) ; 
        }
        standardT = to_string(hours) + ":" + minutesString +  amPM ;
    }
    return standardT ; 
}

int Appointment::standardToMilitary(string time){
    //reads the line for an A or a for AM and the opposite for PM, it then substr to find the hours/minutes and compiles a string
    string militaryT ; 
    int returnTime ; 
    nospaces(time) ; 
    // this section is for times with single digit hours
    if(time.length() == 6){
        if(time.substr(4, 1) == "A" || time.substr(4, 1) == "a"){
            militaryT += time[0] ;  
            militaryT += time.substr(2,2) ;
            returnTime = stoi(militaryT) ;
        } else if(time.substr(4, 1) == "P" || time.substr(4, 1) == "p"){
            militaryT += time[0] ; 
            militaryT += time.substr(2,2) ;
            returnTime = stoi(militaryT) + 1200 ;  
        }
    }
    // this section is for times with double digit hours 
    if(time.length() == 7){
        if(time.substr(0,2) == "12" && (time.substr(5,1) == "A" || time.substr(5,1) == "a")){
            militaryT += time.substr(3,2) ; 
            returnTime = stoi(militaryT) ; 
        } else if(time.substr(0,2) == "12" && (time.substr(5,1) == "P" || time.substr(5,1) == "p")){
            militaryT += "12" ; 
            militaryT += time.substr(3,2) ; 
            returnTime = stoi(militaryT) ;
        } else if(time.substr(5, 1) == "A" || time.substr(5, 1) == "a"){
        militaryT += time.substr(0,2) ;  
        militaryT += time.substr(3,2) ;
        returnTime = stoi(militaryT) ;
        } else if(time.substr(5,1) == "P" || time.substr(5,1) == "p"){
            militaryT += time.substr(0,2) ; 
            militaryT += time.substr(3,2) ;
            returnTime = stoi(militaryT) + 1200 ;  
        }
    }
    return returnTime ; 
}

bool operator ==(const Appointment &first, const Appointment &second){
    if(first.date == second.date && first.time == second.time && first.title == second.title && first.duration == second.duration){
        return true ; // determines if functions are equal or not
    }else{
        return false ;
    }  
}
string Appointment::getStandardTime(){
    return militaryToStandard(time) ; // function that returns standard time
}

Appointment::Appointment(string appData){
    appData += " |" ; 
    char delimiter = '|' ; 
    int i = 0 ;
    size_t pos = 0;
    string token;
    // reads through string until it finds a delimiter
    // if it finds it, it will stop and assign that string to one of the values depending on what i is equal to
    while ((pos = appData.find(delimiter)) != std::string::npos) {
        token = appData.substr(0, pos);
        appData.erase(0, pos + 1);
        if(i == 0){
            title = leading(token) ; 
        }
        if(i == 1){
            year = stoi(leading(token)) ;
        }
        if(i == 2){
            month = stoi(leading(token)) ;
        }
        if(i == 3){
            day = stoi(leading(token)) ;
        }
        if(i == 4){
            time = standardToMilitary(leading(token)) ;
        } 
        if(i == 5){
            duration = stoi(leading(token)) ; 
        }
        i++ ; 
    }
}

string leading(string str){
    string output ; 
    unsigned int endspace = str.length() ; 
    unsigned int count = 0 ;
    while(str[count] == ' '){
        count ++ ; 
    }
    while(count < str.length()){
        if(str[count] == ' '){
            count ++ ; 
            if(str[count] == ' ' || (count == endspace)){
                return output ; 
            }
            count-- ;
            output += " " ; 
            count++ ; 
        }
        output += str[count] ; 
        count ++ ; 
    }
    return output ; 
}

void nospaces(string &str){
    string temp ;
    for(size_t i = 0; i < str.length(); i++){
        if(str.at(i) != ' '){
            temp += str.at(i) ; 
        }
    }
    str = temp ;
}