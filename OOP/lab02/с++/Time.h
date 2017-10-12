//
// Created by hroniko on 30.09.17.
//

#ifndef LAB02_TIME_H
#define LAB02_TIME_H

#include <string>

class Time {
protected:
    int hh; // Часы
    int mm; // Минуты
    int ss; // Секунды

private:
    const int MAX_HH = 23;
    const int MAX_MM = 59;
    const int MAX_SS = 59;

public:
    Time(); // Конструктор по умолчанию
    Time(int HH, int MM, int SS); // Конструктор с параметрами (часы, минуты, секунды)
    Time(int sec); // Конструктор с параметрами (интервал времени в секундах относительно начала дня)

private:
    int isNegative(int x, std::string name); // Метод проверки на отрицательность числа и превращение его в положительное
    int inNormalRange(int x, std::string name); // Метод проверки на превышение максимального значения(24, 60, 60)
    int isGoodTime(int x, std::string name); // Метод проверки на корретность, включает два предыдущих метода

public:
    void print(); // Метод печати в консоль времени объекта класса
    int toSeconds(); // Метод конвертации часов, минут и секунд в количество секунд
    std::string toString(); // Метод конвертации в строку

    int getHH();
    int getMM();
    int getSS();

};


#endif //LAB02_TIME_H
