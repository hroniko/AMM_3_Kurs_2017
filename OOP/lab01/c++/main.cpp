#include <iostream>
#include <algorithm>
#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;

class Book {

private:
    string name; // Название
    int page_count; // Количество страниц
    double price; // Цена в рублях

public:
    Book(){ // Конструктор по умолчанию
        this->name = "";
        this->page_count = 0;
        this->price = 0.0;
    }

    Book(string name, int page_count, double price){ // Конструктор с параметрами
        this->name = name;
        this->page_count = page_count;
        this->price = price;
    }

    ~Book(){ // Деструктор
        cout << "Тут сработал деструктор" << endl;
    }

    // Набор геттеров и сеттеров:

    const string &getName() const {
        return name;
    }

    void setName(const string &name) {
        this->name = name;
    }

    int getPage_count() const {
        return this->page_count;
    }

    void setPage_count(int page_count) {
        this->page_count = page_count;
    }

    double getPrice() const {
        return this->price;
    }

    void setPrice(double price) {
        this->price = price;
    }



    // Метод вычисления средней стоимости одной страницы:
    double priceOnePage(){
        return this->page_count > 0.0 ? price / page_count : 0.0;
    }

    // Метод увеличения стоимости книги в два раза, если название начинается со слова "Программирование":
    void priceX2(){
        string tmp_name = this->name;
        //transform(tmp_name.begin(), tmp_name.end(), tmp_name.begin(), ::tolower); // Конвертируем к нижнему регистру
        // К сожалению, с русскими символами конвертирование string к нижнему регистру не работает

        int pos = tmp_name.find("Программирование");
        if (pos == 0) { // Если подстрока найдена, и найдена на нулевой позиции (в самом начале), //(pos != std::string::npos){ //
            this->price *= 2;
            std::cout << "Цена книги увеличена в 2 раза: " << this->price << " руб. \n";
        }
        else
            std::cout << "Цена книги осталась прежней: " << this->price << " руб. \n";
    }

    // Метод формирования информации об объекте (книге):
    void  toString(){
        std::cout << "Книга: \"" << this->name << "\" \n";
        std::cout << "     страниц: " << this->page_count<< " шт. \n";
        std::cout << "     цена: " << this->price << " руб. \n";
    }

};


int main() { // Вариант 13
    setlocale(LC_ALL, "rus");

    string nameBook;
    int pageCount;
    double priceBook;

    std::cout << "Введите название книги: ";
    std::cin >> nameBook;
    std::cout << "Введите число страниц: ";
    std::cin >> pageCount;
    std::cout << "Введите стоимость книги: ";
    std::cin >> priceBook;


    Book myBook = Book(nameBook, pageCount, priceBook);
    std::cout << "Стоимость одной страницы: " << myBook.priceOnePage() << " руб." << std::endl;
    myBook.toString();

    myBook.priceX2();
    std::cout << "Стоимость одной страницы: " << myBook.priceOnePage() << " руб." << std::endl;


    return 0;
}