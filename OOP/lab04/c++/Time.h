//
// Created by hroniko on 29.10.2017.
//

#ifndef C_TIME_H
#define C_TIME_H

#include <string>

class Time {
protected:

    int yy; // Год
    int mm; // Месяц
    int dd; // День

    int hour; // Часы
    int minute; // Минуты

private:
    const int MAX_MM = 12;

    const int MAX_HOUR = 23;
    const int MAX_MINUTE = 59;

public:
    Time(); // Конструктор по умолчанию
    Time(int YY, int MM, int DD, int Hour, int Minute); // Конструктор с параметрами (год, месяц, день, часы, минуты)
    Time(int YY, int MM, int DD, long min); // Конструктор с параметрами (год, месяц, день, интервал времени в минутах относительно начала дня)

private:
    int isNegative(int x, std::string name); // Метод проверки на отрицательность числа и превращение его в положительное
    int inNormalRange(int x, std::string name); // Метод проверки на превышение максимального значения(24, 60, 60)
    int isGoodTime(int x, std::string name); // Метод проверки на корретность, включает два предыдущих метода
    int getNumberOfDays(int YY, int MM); // Метод вычисления количества дней в месяце MM для года YY

public:
    void print(); // Метод печати в консоль времени объекта класса
    int toMinute(); // Метод конвертации часов, минут и секунд в количество секунд
    std::string toString(); // Метод конвертации в строку

    int getYY();
    void setYY(int YY);

    int getMM();
    void setMM(int MM);

    int getDD();
    void setDD(int DD);

    int getHour();
    void setHour(int Hour);

    int getMinute();
    void setMinute(int Minute);

};


#endif //C_TIME_H