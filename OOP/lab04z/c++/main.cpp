#include <iostream>
#include <string>
#include <cmath>
#include <clocale>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>

#include "Book.h"

using namespace std;






// Функция обхода всего списка и печати книг
void printBookList(Book * root){
    while ((*root).getNext() != NULL){
        root = (*root).getNext();
        cout << (*root).toString() << endl;
    }
}

// Функция обхода списка и печати списка книг только конкретного автора
void printBookListByAuthor(Book * root, string author){
    cout << "Список книг автора " << author << ":" << endl;
    while ((*root).getNext() != NULL){
        root = (*root).getNext();
        if ( (* root).getAuthor() == author ) cout << (*root).toString() << endl;
    }
}

// Функция обхода списка и печати книги только с конкретным названием
void printBookListByTitle(Book * root, string title){
    cout << "Список книг с названием " << title << ":" << endl;
    bool flag = true;
    while ((*root).getNext() != NULL){
        root = (*root).getNext();
        if ( (* root).getTitle() == title ) {
            cout << (*root).toString() << endl;
            flag = false;
        }
    }
    if (flag) cout << "книг с таким названием не найдено!" << endl;
}

// Функция обхода списка и выдачи книги с конкретным названием
void takeBookListByTitle(Book * root, string title){
    bool flag = true;
    while ((*root).getNext() != NULL){
        root = (*root).getNext();
        if ( (* root).getTitle() == title ) {
            if ( (* root).takeBook() ) {
                cout << "Книга успешно выдана: ";
            } else {
                cout << "Все книги на руках, выдавать нечего: ";
            }

            cout << (*root).toString() << endl;
            flag = false;
            break;
        }
    }
    if (flag) cout << "книг с таким названием не найдено!" << endl;
}

// Функция обхода списка и возврата книги с конкретным названием
void returnBookListByTitle(Book * root, string title){
    bool flag = true;
    while ((*root).getNext() != NULL){
        root = (*root).getNext();
        if ( (* root).getTitle() == title ) {
            (* root).returnBook();
            cout << "Книга успешно возвращена: ";

            cout << (*root).toString() << endl;
            flag = false;
            break;
        }
    }
    if (flag) cout << "книг с таким названием не найдено!" << endl;
}



// Функция добавления новой книги в список
Book * addBook(Book * head, string title, string author, int fullCount, int onHandsCount){

    // Создание новой записи
    Book *book = new Book(title, author, fullCount, onHandsCount);


    // 1 Если есть только один корневой элемент
    if ((*head).getNext() == NULL){
        (*head).setNext(book);
        return head;
    }

    // 2 иначе вставляем в конец
    Book *root = head;
    while ((*root).getNext() != NULL){
        // Иначе движемся дальше
        root = (*root).getNext();
    }
    (*root).setNext(book);

    return head;
}



// Функция удаления книги из списка
Book * deleteBook(Book * head, string title, string author){
    cout << "Выполнется попытка удаления книги \"" << title << "\" " << author << "..." << endl;
    Book * root = head;
    while ((*root).getNext() != NULL){
        Book * next = (*root).getNext();
        if (  ( (*next).getTitle() == title ) & ( (*next).getAuthor() == author) )  { // нашли!
            // нашли место удаления!
            (*root).setNext((*next).getNext());
            cout << "Книга успешно удалена" << endl;
            return head;
        }
        // Иначе движемся дальше
        root = (*root).getNext();
    }

    cout << "Книга для удаления не найдена" << endl;
    return head;
}



// Функция чтения файла в список книг
Book * readFile(Book * head, string path){

    try {
        ifstream file(path); // файл из которого читаем (для линукс путь будет выглядеть по другому) // "C:\\PriceList.dat"
        string s; // сюда будем класть считанные строки

        head = new Book("Root", "Root", 0, 0); // Корневой элемент

        while(getline(file, s)){ // пока не достигнут конец файла класть очередную строку в переменную (s)

            // Парсим строку
            string title =  "";
            string author = "";
            string fullCount = "";
            string onHandsCount = "";

            int pos = 0;

            while ( (pos < s.length()) & (s[pos] != ';') ){
                title +=s[pos];
                pos++;
            }
            pos++;

            while ( (pos < s.length()) & (s[pos] != ';') ){
                author +=s[pos];
                pos++;
            }
            pos++;


            while ( (pos < s.length()) & (s[pos] != ';') ){
                fullCount +=s[pos];
                pos++;
            }
            pos++;

            while ( (pos < s.length()) & (s[pos] != ';') ){
                onHandsCount +=s[pos];
                pos++;
            }


            head = addBook(head, title, author, std::stoi(fullCount), std::stoi(onHandsCount));


        }

        file.close(); // обязательно закрываем файл что бы не повредить его
    } catch (...) {
        return head;
    }


    return head;
}

void writeFile(Book * head, string path){
    ofstream fout(path); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt

    Book * root = head;
    while ((*root).getNext() != NULL){
        root = (*root).getNext();
        fout << (*root).toString() << endl;
    }
    fout.close(); // закрываем файл
}



int main()
{

    setlocale(LC_ALL, "Russian");

    Book *head = new Book("Root", "Root", 0, 0); // Корневой элемент

    // Подготавливаем привествнную речь))
    string hello = "Вас приветствует программа \"Библиотека\"\n- для вывода справки введите help \n- для выхода введите exit \n";
    string help = "Распечатать: print | только для автора: author | только с названием: title | добавить запись: add | удалить: delete \nзагрузить расписание: load | сохранить: save | выдать книгу: take | вернуть книгу: return | помощь: help | выход: exit";


    string str = ""; // тут будем хранить команды

    cout << hello << endl; // Выводим приветствие
    cout << help << endl;
    head = readFile(head, "/media/hroniko/DATA/AMM_3_Kurs_2017/OOP/lab04z/c++/list.txt"); // Тут надо написать свой путь к файлу!!!


    // Запускаем бесконечный цикл с выходом по ключевому слову
    while (true){
        cout << "> "; // печатаем приглашение для ввода
        cin >> str;
        if (str == "exit") break; // если выход, то выходим
        if (str == "help"){
            cout << help << endl;
            cin.ignore(); // Просто читаем Энтер для продолжения работы программы
            continue; // Пропускаем одну итерацию цикла
        }

        // иначе продолжаем работать с командами

        if (str == "load"){
            // подгружаем файл
            head = readFile(head, "/media/hroniko/DATA/AMM_3_Kurs_2017/OOP/lab04z/c++/list.txt"); // Тут надо написать свой путь к файлу!!!
            cout << "Список книг успешно загружен!" << endl;
            continue; // Пропускаем одну итерацию цикла
        }

        if (str == "save"){
            // сохраняем файл
            writeFile(head, "/media/hroniko/DATA/AMM_3_Kurs_2017/OOP/lab04z/c++/list.txt"); // Тут надо повторить свой путь к файлу!!!
            cout << "Список книг успешно сохранен!" << endl;
            continue; // Пропускаем одну итерацию цикла
        }

        if (str == "print"){
            // печатаем список
            cout << "Все книги:" << endl;
            printBookList(head);
            continue; // Пропускаем одну итерацию цикла
        }

        if (str == "author"){
            string author;
            cout << "Введите автора:" << endl;
            cin >> author;
            printBookListByAuthor(head, author);
            continue; // Пропускаем одну итерацию цикла
        }

        if (str == "title"){
            string title;
            cout << "Введите название:" << endl;
            cin >> title;
            printBookListByTitle(head, title);
            continue; // Пропускаем одну итерацию цикла
        }

        if (str == "take"){
            string title;
            cout << "Введите название:" << endl;
            cin >> title;
            // std::getline (std::cin,title);
            takeBookListByTitle(head, title);
            continue; // Пропускаем одну итерацию цикла
        }

        if (str == "return"){
            string title;
            cout << "Введите название:" << endl;
            cin >> title;
            returnBookListByTitle(head, title);
            continue; // Пропускаем одну итерацию цикла
        }

        if (str == "add"){
            // добавляем книгу

            string title, author, fullCount, onHandsCount;
            cout << "Для книги введите название:" << endl;
            cin >> title;
            cout << "введите автора:" << endl;
            cin >> author;
            cout << "всего книг и книг на руках через пробел" << endl;
            cin >> fullCount >> onHandsCount;



            head = addBook(head, title, author, std::stoi(fullCount), std::stoi(onHandsCount));
            continue; // Пропускаем одну итерацию цикла
        }

        if (str == "delete"){
            // удаляем книгу
            string title, author;

            cout << "Для удаления книги введите название:" << endl;
            cin >> title;
            cout << "введите автора:" << endl;
            cin >> author;

            head = deleteBook(head, title, author);
            continue; // Пропускаем одну итерацию цикла
        }



    }



    return 0;
}