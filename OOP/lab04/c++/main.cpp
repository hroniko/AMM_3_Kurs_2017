#include <iostream>
#include <string>
#include <cmath>
#include <clocale>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

#include "Schedule.h"

using namespace std;






// Функция обхода всего списка и печати
void printSchedule(Schedule * root){
    while ((*root).getNext() != NULL){
        root = (*root).getNext();
        cout << (*root).getInfo() << endl;
    }
}

// Функция обхода списка и печати расписания только в конкретный день
void printScheduleByDay(Schedule * root, int YY, int MM, int DD){
    cout << "Расписание на " << to_string(YY) << "-" <<  to_string(MM) << "-" << to_string(DD) << ":" << endl;
    while ((*root).getNext() != NULL){
        root = (*root).getNext();
        if ( ((* root).getYY() == YY) & ((* root).getMM() == MM) & ((* root).getDD() == DD) )
        cout << (*root).getInfo() << endl;
    }
}


// Функция определения времени в минутах между двумя записями:
long minutesBetween(Schedule * sc1, Schedule * sc2){

    long res = (* sc2).getYY() - (* sc1).getYY();
    res = res * 12 + (* sc2).getMM() - (* sc1).getMM();
    res = res * 30 + (* sc2).getDD() - (* sc1).getDD();
    res = res * 24 + (* sc2).getHour() - (* sc1).getHour();
    res = res * 60 + (* sc2).getMinute() - (* sc1).getMinute();

    return res;
}

// Функция изменения времени записи так, чтобы она помещалась следом за впереди идущей:
// Первый параметр - запись в расписании, на который ориентируемся, второй - запись, которую изменяем
Schedule * optimizeTime(Schedule * sc1, Schedule * sc2){

    if(minutesBetween(sc1, sc2) < 60L){
        string before = (*sc2).getInfo(); // Информация о записи до изменения

        (* sc2).setYY((* sc1).getYY());
        (* sc2).setMM((* sc1).getMM());
        (* sc2).setDD((* sc1).getDD());
        (* sc2).setHour((* sc1).getHour());
        (* sc2).setMinute((* sc1).getMinute() + 60); // Смещаем на 60 минут после

        cout << "Оптимизация расписания: ";

        cout << before << " передвинута на " << (*sc2).getTime() << endl;
    }



    return sc2;
}

// Функция добавления новой записи в расписание
Schedule * addSchedule(Schedule * head, string fName, string lName, string sName, int yy, int mm, int dd, int hour, int minute){

    // Создание новой записи
    Schedule *new_schedule = new Schedule(fName, lName, sName);
    (*new_schedule).setYY(yy);
    (*new_schedule).setMM(mm);
    (*new_schedule).setDD(dd);

    (*new_schedule).setHour(hour);
    (*new_schedule).setMinute(minute);
    //


    // 1 Если есть только один корневой элемент
    if ((*head).getNext() == NULL){
        (*head).setNext(new_schedule);
        return head;
    }

    // Проверяем, вдруг можно поставить новую запись перед текущей
    if (minutesBetween(new_schedule, head) >= 60L){
        // то можно записать впереди
        (*new_schedule).setNext(head);

        return new_schedule;

    }

    // Иначе нельзя, надо искать место, куда вставить
    Schedule * root = head;
    while ((*root).getNext() != NULL){
        // cout << (*root).getSurname() << endl;
        // cout << (*new_schedule).getSurname() << endl;
        // cout << minutesBetween(root, new_schedule) << endl;

        // Вот тут надо попробовать подвинуть и засунуть:
        Schedule *new_schedule2 = optimizeTime(root, new_schedule);
        if ((minutesBetween(root, new_schedule2) >= 60L) & (minutesBetween(new_schedule2, (*root).getNext()) >= 60L)){
            // нашли место для вставки!
            (*new_schedule2).setNext((*root).getNext());
            (*root).setNext(new_schedule2);
            return head;
        }
        // Иначе движемся дальше
        root = (*root).getNext();
    }

    // И, наконец, если никуда не всунули, то встраиваем в конец:
    new_schedule = optimizeTime(root, new_schedule);
    (*root).setNext(new_schedule);

    return head;
}



// Функция удаления записи из расписания
Schedule * deleteSchedule(Schedule * head, string fName, string lName, string sName){
    cout << "Выполнется попытка удаления записи для " << fName << " " << lName << " " << sName << "..." << endl;
    Schedule * root = head;
    while ((*root).getNext() != NULL){
        Schedule * next = (*root).getNext();
        if (( (*next).getFirstname() == fName ) & ( (*next).getLastname() == lName )  & ( (*next).getSurname() == sName ) )  { // нашли!
            // нашли место удаления!
            (*root).setNext((*next).getNext());
            cout << "Запись удалена!" << endl;
            return head;
        }
        // Иначе движемся дальше
        root = (*root).getNext();
    }

    cout << "Запись для удаления не найдена!" << endl;
    return head;
}



// Функция чтения файла в расписание
Schedule * readFile(Schedule * head, string path){

    try {
        ifstream file(path); // файл из которого читаем (для линукс путь будет выглядеть по другому) // "C:\\PriceList.dat"
        string s; // сюда будем класть считанные строки

        while(getline(file, s)){ // пока не достигнут конец файла класть очередную строку в переменную (s)

            // Парсим строку
            string sYY =  "";
            string sMM = "";
            string sDD = "";

            string sHour = "";
            string sMinute = "";

            string sFirstname = "";
            string sLastname = "";
            string sSurname = "";

            int pos = 0;

            while ( (pos < s.length()) & (s[pos] != '-') ){
                sYY +=s[pos];
                pos++;
            }
            pos++;

            while ( (pos < s.length()) & (s[pos] != '-') ){
                sMM +=s[pos];
                pos++;
            }
            pos++;


            while ( (pos < s.length()) & (s[pos] != ' ') ){
                sDD +=s[pos];
                pos++;
            }
            pos++;

            while ( (pos < s.length()) & (s[pos] != ':') ){
                sHour +=s[pos];
                pos++;
            }
            pos++;

            while ( (pos < s.length()) & (s[pos] != ' ') ){
                sMinute +=s[pos];
                pos++;
            }
            pos++;

            while ( (pos < s.length()) & (s[pos] != ' ') ){
                sFirstname +=s[pos];
                pos++;
            }
            pos++;

            while ( (pos < s.length()) & (s[pos] != ' ') ){
                sLastname +=s[pos];
                pos++;
            }
            pos++;

            while ( (pos < s.length()) & (s[pos] != ' ') ){
                sSurname +=s[pos];
                pos++;
            }

            head = addSchedule(head, sFirstname, sLastname, sSurname, std::stoi(sYY), std::stoi(sMM), std::stoi(sDD), std::stoi(sHour), std::stoi(sMinute));


        }

        file.close(); // обязательно закрываем файл что бы не повредить его
    } catch (...) {
        return head;
    }


    return head;
}

void writeFile(Schedule * head, string path){
    ofstream fout(path); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt

    Schedule * root = head;
    while ((*root).getNext() != NULL){
        root = (*root).getNext();
        fout << (*root).getInfo() << endl;
    }
    fout.close(); // закрываем файл
}



int main()
{

    setlocale(LC_ALL, "Russian");



    Schedule *head = new Schedule("Root", "Root", "Root"); // Корневой элемент

/*
    head = addSchedule(head, "Иван", "Иванович", "Иванов", 2017, 10, 26, 7, 55);

    head = addSchedule(head, "Петр", "Петрович", "Петров", 2017, 10, 26, 9, 20);
    head = addSchedule(head, "Сидор", "Сидорович", "Сидоров", 2017, 10, 27, 8, 30);
*/
    // printSchedule(head);

    head = readFile(head, "/media/hroniko/DATA/AMM_3_Kurs_2017/OOP/lab04/in/in.txt");

    printScheduleByDay(head, 2017, 10, 26);
    printScheduleByDay(head, 2017, 10, 27);

    head = deleteSchedule(head, "Петр", "Петрович", "Петров");
    printScheduleByDay(head, 2017, 10, 26);

    writeFile(head, "/media/hroniko/DATA/AMM_3_Kurs_2017/OOP/lab04/out/out.txt");

    // system("pause"); // Команда задержки экрана, только для Windows

    return 0;
}