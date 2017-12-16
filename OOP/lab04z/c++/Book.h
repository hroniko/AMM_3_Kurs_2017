//
// Created by hroniko on 16.12.17.
//

#ifndef C_BOOK_H
#define C_BOOK_H

#include <string>

// Класс Книга
class Book {
protected:

    std::string Title; // Название
    std::string Author; // Автор
    int FullCount; // Количество экземпляров
    int OnHandsCount; // Количество экземпляров на руках

    // Ссылка на следующую книгу
    Book * Next;

public:
    Book(); // Конструктор по умолчанию
    Book(std::string title, std::string author, int fullCount, int onHandsCount = 0);  // Конструктор с параметрами

private:


public:

    // Набор геттеров и сеттеров

    std::string getTitle();

    void setTitle(std::string title);

    std::string getAuthor();

    void setAuthor(std::string author);

    int getFullCount();

    void setFullCount(int fullCount);

    int getOnHandsCount();

    void setOnHandsCount(int onHandsCount);


    // Ссылка на следующую книгу:
    Book * getNext();

    void setNext(Book * book);

    // Взять книгу на руки
    bool takeBook();

    // Вернуть книгу
    void returnBook();


    // Метод конвертации в строку
    std::string toString();
};


#endif //C_BOOK_H
