//
// Created by hroniko on 30.09.17.
//

#include "Schedule.h"
#include "Time.h"
#include <iostream>
#include <string>

using namespace std;

// Конструктор по умолчанию:
// реализация с вызовом конструктора по умолчанию для класса Time
// и дополнительно выставлением собственных полей:
Schedule::Schedule(){
    number = 1;
    direction = "Неизвестно";
}

// Конструктор с параметрами:
// реализация с передачей параметров в конструктор с параметрами базового класса
Schedule::Schedule(int Num, std::string Dir, int HH, int MM, int SS) : Time(HH, MM, SS) {
    number = Num;
    direction = Dir;
}

void Schedule::print() {
    cout << "Поезд номер " << number << ", ";
    cout << "направление \"" << direction << "\", ";
    cout << "время отправления: ";
    hh > 9 ? cout << hh : cout << "0" << hh;
    cout << ":";
    mm > 9 ? cout << mm : cout << "0" << mm;
    cout << ":";
    ss > 9 ? cout << ss : cout << "0" << ss;
    cout << "\n";
}

Time Schedule::howMuchTime(Time currentTime) {

    // Конвертируем в количество секунд и вычетаем одно из другого:
    int secBetween = toSeconds() - currentTime.toSeconds();

    if (secBetween < 0){
        int res = (hh * 60 + mm)* 60 + ss + ((24 - currentTime.getHH()) * 60 - currentTime.getMM())*60 - currentTime.getSS();
        return Time(res);
    } else {
        return Time(secBetween);
    }

}