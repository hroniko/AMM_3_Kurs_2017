//
// Created by hroniko on 30.09.17.
//

#ifndef LAB02_SCHEDULE_H
#define LAB02_SCHEDULE_H


#include "Time.h"
#include <string>

using namespace std;

// Класс "Расписание", отнаследованный от класса "Время"
class Schedule : public Time{
public:
    int number; // Номер поезда
    std::string direction; // Направление

    Schedule(); // Конструктор по умолчанию
    Schedule(int Num, std::string Dir, int HH, int MM, int SS); // Конструктор с параметрами

    void print(); // Метод печати в консоль информации об объекте класса

    Time howMuchTime(Time currentTime); // Метод определения, сколько времени осталось до отправления поезда

};


#endif //LAB02_SCHEDULE_H
