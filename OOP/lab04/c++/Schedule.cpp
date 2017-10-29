//
// Created by hroniko on 29.10.17.
//

#include "Schedule.h"

#include "Time.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Класс Расписание // Реализация


// Конструктор с параметрами (реализация)
Schedule::Schedule(std::string fName, std::string lName, std::string sName) {
    firstname = fName;
    lastname = lName;
    surname = sName;

    time = new Time(1900, 1, 1, 0, 0);
    sc_next = NULL;
}

// Конструктор с параметрами #2 (реализация)
Schedule::Schedule(std::string fName, std::string lName, std::string sName, int yy, int mm, int dd, int hour, int minute) {
    firstname = fName;
    lastname = lName;
    surname = sName;

    time = new Time(yy, mm, dd, hour, minute);
    sc_next = NULL;
}

// Набор геттеров и сеттеров

// Дата:

void Schedule::setYY(int year){
    (*time).setYY(year);
}

int Schedule::getYY() {
    return (*time).getYY();
}

void Schedule::setMM(int month) {
    (*time).setMM(month);
}

int Schedule::getMM() {
    return (*time).getMM();
}

void Schedule::setDD(int day) {
    (*time).setDD(day);
}

int Schedule::getDD() {
    return (*time).getDD();
}

// Время:

void Schedule::setHour(int hour){
    (*time).setHour(hour);
}

int Schedule::getHour() {
    return (*time).getHour();
}
//

void Schedule::setMinute(int minute){
    (*time).setMinute(minute);
}

int Schedule::getMinute() {
    return (*time).getMinute();
}



// ФИО
string Schedule::getFirstname() {
    return firstname;
}

void Schedule::setFirstname(string fname) {
    firstname = fname;
}

string Schedule::getLastname() {
    return lastname;
}

void Schedule::setLastname(string lname) {
    lastname = lname;
}

string Schedule::getSurname() {
    return surname;
}

void Schedule::setSurname(string sname) {
    surname = sname;
}
//

// Ссылка на следующий элемент расписания:
Schedule * Schedule::getNext(){
    return sc_next;
}

void Schedule::setNext(Schedule * sc){
    sc_next = sc;
}


// Метод получения информации о Записи (реализация)
string Schedule::getInfo() {

    string info = getTime() + " "; // время // string info = "Запись на " + getTime() + " ";

    info += firstname + " " + lastname + " " + surname; // ФИО
    return info;
}

// Метод получения информации о времени Записи (реализация)
string Schedule::getTime() {

    string info = std::to_string(getYY()) + "-" + // год
                  ( getMM() > 9 ? std::to_string(getMM()) : "0" + std::to_string(getMM()) ) + "-" + // месяц
                  ( getDD() > 9 ? std::to_string(getDD()) : "0" + std::to_string(getDD()) ) + " "; // день

    info += ( getHour() > 9 ? std::to_string(getHour()) : "0" + std::to_string(getHour()) ) + ":" + // час
            ( getMinute() > 9 ? std::to_string(getMinute()) : "0" + std::to_string(getMinute()) ); // минуты
    return info;
}


