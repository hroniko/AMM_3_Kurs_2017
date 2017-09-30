#include <iostream>
#include <string>
#include "Time.h"
#include "Schedule.h"


using namespace std;

int main() {
    setlocale(LC_ALL,"");

    std::cout << "Введите номер поезда и направление, \n";
    std::cout << "разделяя значения пробелом:\n";

    int num;
    string dir;
    std::cin >> num >> dir;


    std::cout << "Введите время отправления, \n";
    std::cout << "разделяя значения часов, минут и секунд пробелом:\n";

    int HH, MM, SS;
    std::cin >> HH >> MM >> SS;


    Schedule mySchedule(num, dir, HH, MM, SS); // Создаем расписание поезда
    mySchedule.print(); // Выводим информацию о поезде

    Time currentTime; // Создаем объект класса Время (текущее время)
    currentTime.print();

    std::cout << "До отправки поезда осталось " << mySchedule.howMuchTime(currentTime).toString();


    return 0;
}