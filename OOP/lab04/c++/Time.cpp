//
// Created by hroniko on 29.10.2017.
//

#include "Time.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Конструктор по умолчанию (реализация):
// Устанавливает текущее время
Time::Time(){
    time_t seconds = time(NULL);
    tm timeinfo = * localtime(&seconds);
    yy = timeinfo.tm_year;
    mm = timeinfo.tm_mon;
    dd = timeinfo.tm_mday;

    hour = timeinfo.tm_hour;
    minute = timeinfo.tm_min;
}

// Конструктор с параметрами (реализация):
Time::Time(int YY, int MM, int DD, int Hour, int Minute) {
    yy = YY;
    mm = MM;
    dd = DD;

    hour = Hour;
    minute = Minute;


    // Проверки на корректность времени:
    yy = isGoodTime(yy, "Годы");
    mm = isGoodTime(mm, "Месяцы");
    dd = isGoodTime(dd, "Дни");
    hour = isGoodTime(hour, "Часы");
    minute = isGoodTime(minute, "Минуты");
}

// Конструктор с параметрами (реализация), параметр - количество секунд с начала дня
Time::Time(int YY, int MM, int DD, long minute) {
    yy = YY;
    mm = MM;
    dd = DD;
    // Проверки на корректность времени:
    yy = isGoodTime(yy, "Годы");
    mm = isGoodTime(mm, "Месяцы");
    dd = isGoodTime(dd, "Дни");



    hour = minute / 60; // Считаем количесво полных часов
    minute -= hour * 60; // и уменьшаем количество минут на это количество полных часов // Считаем количество полных минут

    // Проверки на корректность времени:
    hour = isGoodTime(hour, "Часы");
    minute = isGoodTime(minute, "Минуты");
}

// Метод проверки на неотрицательность введенных значений (реализация):
int Time::isNegative(int x, string name) {
    // Проверки на корректность времени:
    if (x < 0){
        cout << "Ошибка! " + name +" не могут задаваться в отрицательном формате!\n";
        cout << "Это значение будет использоваться со знаком +!\n";
        x = -x;
    }
    return x;
}

// Метод проверки на превышение максимального значения (24 для часов, 60 для минут):
int Time::inNormalRange(int x, string name) {

    if (name == "Годы"){ // просто заглушка
        x = x;
    }
    if ((name == "Месяцы") & (x > MAX_MM)){
        // cout << "Ошибка! " + name +" превышают допустимое значение!\n";
        // cout << "Это значение будет взято путем смещения на n макисмальных значений!\n";
        // Берем остаток, а все остальное списываем на старшие разряды
        yy = inNormalRange(yy + x / (MAX_MM + 1), "Годы");
        x = x % (MAX_MM + 1); // Берем остаток, а все остальное уже списали выше
    }

    if ((name == "Дни") & (x > getNumberOfDays(yy, mm))){
        // cout << "Ошибка! " + name +" превышают допустимое значение!\n";
        // cout << "Это значение будет взято путем смещения на n макисмальных значений!\n";
        // Берем остаток, а все остальное списываем на старшие разряды
        mm = inNormalRange(mm + x / (getNumberOfDays(yy, mm+1)), "Месяцы");
        x = x % getNumberOfDays(yy, mm+1); // Берем остаток, а все остальное уже списали выше
    }

    if ((name == "Часы") & (x > MAX_HOUR)){
        // cout << "Ошибка! " + name +" превышают допустимое значение!\n";
        // cout << "Это значение будет взято путем смещения на n макисмальных значений!\n";
        // Берем остаток, а все остальное списываем на старшие разряды
        dd = inNormalRange(dd + x / (MAX_HOUR + 1), "Дни");
        x = x % (MAX_HOUR + 1); // Берем остаток, а все остальное уже списали выше
    }

    if ((name == "Минуты") & (x > MAX_MINUTE)){
        // cout << "Ошибка! " + name +" превышают допустимое значение!\n";
        // locout << "Это значение будет взято путем смещения на n макисмальных значений!\n";
        // Берем остаток, а все остальное списываем на старшие разряды
        hour = inNormalRange(hour + x / (MAX_MINUTE + 1), "Часы");
        x = x % (MAX_MINUTE + 1); // Берем остаток, а все остальное уже списали выше
    }

    return x;
}

// Обобщающий метод проверки на корректность введенного времени (реализация):
int Time::isGoodTime(int x, std::string name) {
    return inNormalRange(isNegative(x, name), name);
}

// Метод вычисления количества дней в месяце MM для года YY (реализация)
int Time::getNumberOfDays(int YY, int MM){
    int leap = (1 - (YY % 4 + 2) % (YY % 4 + 1)) * ((YY % 100 + 2) % (YY % 100 + 1)) + (1 - (YY % 400 + 2) % (YY % 400 + 1));
    return 28 + ((MM + (MM / 8)) % 2) + 2 % MM + ((1 + leap) / MM) + (1 / MM) - (leap / MM);
}

// Метод печати в консоль занчения времени (реализация):
void Time::print() {
    cout << "Текущие дата и время: ";
    cout << toString() << "\n";
}

// Метод конвертации времени в количество минут (реализация)
int Time::toMinute() {
    return (hour * 60 + minute) * 60;
}

// Метод получения информации о времени (реализация) - конвертация в строку
std::string Time::toString() {
    string info = "";
    info = info + std::to_string(yy) + "-";
    info = info + (mm > 9 ? "" : "0") + std::to_string(mm) + "-";
    info = info + (dd > 9 ? "" : "0") + std::to_string(dd) + " ";

    info = info + (hour > 9 ? "" : "0") + std::to_string(hour) + ":";
    info = info + (minute > 9 ? "" : "0") + std::to_string(minute) + "\t";
    return info;
}

int Time::getYY() {
    return yy;
}

void Time::setYY(int YY) {
    yy = YY;
    // Проверки на корректность времени:
    yy = isGoodTime(yy, "Годы");
}

int Time::getMM() {
    return mm;
}

void Time::setMM(int MM) {
    mm = MM;
    // Проверки на корректность времени:
    mm = isGoodTime(mm, "Месяцы");
}

int Time::getDD() {
    return dd;
}

void Time::setDD(int DD) {
    dd = DD;
    // Проверки на корректность времени:
    dd = isGoodTime(dd, "Дни");
}

int Time::getHour() {
    return hour;
}

void Time::setHour(int Hour) {
    hour = Hour;
    // Проверки на корректность времени:
    hour = isGoodTime(hour, "Часы");
}

int Time::getMinute() {
    return minute;
}

void Time::setMinute(int Minute) {
    minute = Minute;
    // Проверки на корректность времени:
    minute = isGoodTime(minute, "Минуты");
}
