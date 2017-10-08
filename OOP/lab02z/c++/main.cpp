#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Класс Дата (класс-родитель)
class Date {
public:
    int dd; // день
    int mm; // месяц
    int yy; // год

    // Конструктор по умолчанию, устанавливает текущую дату
    Date(){

        time_t seconds = time(NULL);
        tm timeinfo = *localtime(&seconds);
        dd = timeinfo.tm_mday;
        mm = timeinfo.tm_mon + 1;
        yy = timeinfo.tm_year + 1900;

    }

    // Конструктор с параметрами
    Date(int DD, int MM, int YY){
        // Нужно проверить, корректна ли дата?
        if (YY < 0){
            std::cout << "Год не может быть отрицательным!" << std::endl;
            std::cout << "Во избежание ошибки установлен 2000 год!" << std::endl;
            YY = 2000;
        }
        if ((MM < 1) | (MM > 12)){
            std::cout << "Неверно задан месяц! " << std::endl;
            std::cout << "Во избежание ошибки установлен январь!" << std::endl;
            MM = 1;
        }
        if ((DD < 1) | (DD > getNumberOfDays(MM, YY))){ // Вызываем метод, возвращающий количество дней в месяце
            std::cout << "Неверно задано число месяца! " << std::endl;
            std::cout << "Во избежание ошибки установлено 1 число" << std::endl;
            DD = 1;
        }
        dd = DD;
        mm = MM;
        yy = YY;
    }

    // Метод получения информации о Дате - конвертация в строку
    string toString() {
        string res = (dd > 9 ? "" : "0") + to_string(dd) + "-";
        res += (mm > 9 ? "" : "0") + to_string(mm) + "-";
        res += (yy > 9 ? "" : "0") + to_string(yy);
        return res;
    }

protected:

    // Метод вычисления количества дней в месяце MM для года YY
    int getNumberOfDays(int MM, int YY){
        int leap = (1 - (YY % 4 + 2) % (YY % 4 + 1)) * ((YY % 100 + 2) % (YY % 100 + 1)) + (1 - (YY % 400 + 2) % (YY % 400 + 1));
        return 28 + ((MM + (MM / 8)) % 2) + 2 % MM + ((1 + leap) / MM) + (1 / MM) - (leap / MM);
    }

};

// Класс Лекарство (класс-потомок)
class Drug : Date{
private:
    string name; // наименование
    string com; // фирма

public:
    // Конструктор по умолчанию, устанавливает дату 01-01-2000 путем вызова конструктора по умолчанию класса-родителя
    // и еще устанавливаем значения полей Наименование и Фирма
    Drug() : Date() {
        name = "noname";
        com = "nocom";
    }

    // Конструктор с параметрами, устанавливает дату путем передачи параметров в конструктор класса-родителя
    // и еще устанавливаем значения полей Наименование и Фирма
    Drug(string Name, string Com, int DD, int MM, int YY) : Date(DD, MM, YY) {
        name = Name;
        com = Com;
    }

    // Метод получения информации о Лекарстве - конвертация в строку
    string toString() {
        string res = "\"" + name + "\" производства фирмы \"" + com + "\", изготовлено ";
        res += (dd > 9 ? "" : "0") + to_string(dd) + "-";
        res += (mm > 9 ? "" : "0") + to_string(mm) + "-";
        res += (yy > 9 ? "" : "0") + to_string(yy);
        return res;
    }

    // Метод, возвращающий количество дней до текущуго момента с производства лекарства
    int getAge(){
        Date nowDate = Date();
        int days = ((nowDate.yy - yy) * 12 + nowDate.mm - mm) * 30 + nowDate.dd - dd;
        if (days < 0) days = 0;
        return days;
    }


};

int main() {
    setlocale(LC_ALL,"");

    std::cout << "Введите название лекарства:\n";
    string Name;
    std::cin >> Name;

    std::cout << "Введите наименование фирмы-изготовителя:\n";
    string Com;
    std::cin >> Com;

    std::cout << "Введите день, месяц и год производства,\n";
    std::cout << "разделяя значения пробелом:\n";
    int DD, MM, YY;
    std::cin >> DD >> MM >> YY;

    Drug myDrug = Drug(Name, Com, DD, MM, YY);
    std::cout << "Вы ввели: " << myDrug.toString() << std::endl;

        Date myDate = Date();
    std::cout << "Текущая дата: " << myDate.toString() << std::endl;

    // Drug myDrug = Drug("Аспирин", "Avexima", 1, 10, 2017);
    // std::cout << myDrug.toString() << std::endl;

    std::cout << "Со дня производства прошло " << to_string(myDrug.getAge()) << " дней"<< std::endl;

    return 0;
}