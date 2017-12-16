//
// Created by hroniko on 16.12.17.
//

#include "Book.h"
#include <string>
#include <iostream>

using namespace std;

// Конструктор с параметрами (реализация)
Book::Book(string title, string author, int fullCount, int onHandsCount) {
    Title = title;
    Author = author;
    FullCount = fullCount;
    OnHandsCount = onHandsCount;
    Next = NULL;
}


// Набор геттеров и сеттеров

string Book::getTitle(){
    return Title;
}

void Book::setTitle(std::string title){
    Title = title;
}

string Book::getAuthor(){
    return Author;
}

void Book::setAuthor(std::string author){
    Author = author;
}

int Book::getFullCount(){
    return FullCount;
}

void Book::setFullCount(int fullCount){
    FullCount = fullCount;
}

int Book::getOnHandsCount(){
    return OnHandsCount;
}

void Book::setOnHandsCount(int onHandsCount){
    OnHandsCount = onHandsCount;
}


// Ссылка на следующую книгу:
Book * Book::getNext(){
    return Next;
}

void Book::setNext(Book * book){
    Next = book;
}


// Взять книгу на руки
bool Book::takeBook(){
    if (OnHandsCount + 1 > FullCount ) {
        // cout << "Все книги уже на руках, нечего выдавать" << endl;
        return false;
    }
    OnHandsCount ++;
    return true;
}

// Вернуть книгу
void Book::returnBook(){
    OnHandsCount --;
    if (OnHandsCount < 0) OnHandsCount = 0;
}

// Метод конвертации в строку
string Book::toString(){
    string info = Title + ";" + Author + ";" + std::to_string(FullCount) +
            ";" + std::to_string(OnHandsCount) + ";";
    return info;
}