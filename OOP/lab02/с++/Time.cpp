//
// Created by hroniko on 30.09.17.
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
    hh = timeinfo.tm_hour;
    mm = timeinfo.tm_min;
    ss = timeinfo.tm_sec;
}

// Конструктор с параметрами (реализация):
Time::Time(int HH, int MM, int SS) {
    hh = HH;
    mm = MM;
    ss = SS;

    // Проверки на корректность времени:
    hh = isGoodTime(hh, "Часы");
    mm = isGoodTime(mm, "Минуты");
    ss = isGoodTime(ss, "Секунды");
}

// Конструктор с параметрами (реализация), параметр - количество секунд с начала дня
Time::Time(int sec) {
    hh = sec / (60*60); // Считаем количесво полных часов
    sec -= hh * 60 *60; // и уменьшаем количество секунд на это количество полных часов
    mm = sec / 60; // Считаем количество полных минут
    sec -= mm * 60; // и уменьшаем на это количество полных минут
    ss = sec; // и переписывем остаток секунд в секунд

    // Проверки на корректность времени:
    hh = isGoodTime(hh, "Часы");
    mm = isGoodTime(mm, "Минуты");
    ss = isGoodTime(ss, "Секунды");
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

// Метод проверки на превышение максимального значения (24 дя часов, 60 для минут, 60 для секуд):
int Time::inNormalRange(int x, string name) {
    if (name == "Часы"){
        if (x > MAX_HH){
            cout << "Ошибка! " + name +" превышают допустимое значение!\n";
            cout << "Это значение будет взято путем смещения на n макисмальных значений!\n";
            x = x % (MAX_HH + 1); // Берем остаток, а все остальное списываем
        }
    } else {
        if (x > MAX_MM){
            cout << "Ошибка! " + name +" превышают допустимое значение!\n";
            cout << "Это значение будет взято путем смещения на n макисмальных значений!\n";
            // Берем остаток, а все остальное списываем на старшие разряды
            if (name == "Минуты"){
                hh = inNormalRange(hh + x / (MAX_MM + 1), "Часы");
            } else {
                mm = inNormalRange(mm + x / (MAX_SS + 1), "Минуты");
            }
            x = x % (MAX_MM + 1); // Берем остаток, а все остальное уже списали выше
        }
    }
    return x;
}

// Обобщающий метод проверки на корректность введенного времени (реализация):
int Time::isGoodTime(int x, std::string name) {
    return inNormalRange(isNegative(x, name), name);
}

// Метод печати в консоль занчения времени (реализация):
void Time::print() {
    cout << "Текущее время: ";
    hh > 9 ? cout << hh : cout << "0" << hh;
    cout << ":";
    mm > 9 ? cout << mm : cout << "0" << mm;
    cout << ":";
    ss > 9 ? cout << ss : cout << "0" << ss;
    cout << "\n";
}

// Метод конвертации времени в количество секунд (реализация)
int Time::toSeconds() {
    return (hh * 60 + mm) * 60 + ss;
}

// Метод получения информации о времени (реализация) - конвертация в строку
std::string Time::toString() {
    string info = "";
    info = info + (hh > 9 ? "" : "0") + std::to_string(hh) + ":";
    info = info + (mm > 9 ? "" : "0") + std::to_string(mm) + ":";
    info = info + (ss > 9 ? "" : "0") + std::to_string(ss);
    return info;
}

int Time::getHH() {
    return hh;
}

int Time::getMM() {
    return mm;
}

int Time::getSS() {
    return ss;
}