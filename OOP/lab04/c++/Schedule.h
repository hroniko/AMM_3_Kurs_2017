//
// Created by hroniko on 29.10.17.
//

#ifndef C_SCHEDULE_H
#define C_SCHEDULE_H

#include <string>
#include "Time.h"

// Класс Расписание
class Schedule {
protected:

    // Дата и время записи
    Time *time;

    // ФИО
    std::string firstname;
    std::string lastname;
    std::string surname;

    // Ссылка на следующую запись
    Schedule * sc_next;

public:

    // Конструктор с параметрами
    Schedule(std::string fName, std::string lName, std::string sName);

    Schedule(std::string fName, std::string lName, std::string sName, int yy, int mm, int dd, int hour, int minute);



    // Набор геттеров и сеттеров

    // Дата:

    void setYY(int year);

    int getYY();

    void setMM(int month);

    int getMM();

    void setDD(int day);

    int getDD();

    // Время:

    void setHour(int hour);

    int getHour();

    void setMinute(int minute);

    int getMinute();



    // ФИО
    std::string getFirstname();

    void setFirstname(std::string fname);

    std::string getLastname();

    void setLastname(std::string lname);

    std::string getSurname();

    void setSurname(std::string sname);
    //

    // Ссылка на следующий элемент расписания:
    Schedule * getNext();

    void setNext(Schedule * sc);




    // Метод получения информации о записи в расписании
    std::string getInfo();

    // Метод получения информации о времени расписания
    std::string getTime();

};

#endif //C_SCHEDULE_H
