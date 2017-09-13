package com.hroniko.booking;

import java.util.Locale;

// Класс книги
public class Book {

    // Поля:
    private String name = ""; // Название
    private int pageCount = 0; // Количество страниц
    private Double price = 0.0; // Цена

    // Конструктор по умолчанию:
    public Book() {
    }

    // Конструктор с параметрами:
    public Book(String name, int pageCount, Double price){
        this.name = name;
        this.pageCount = pageCount;
        this.price = price;
    }

    // Метод вычисления средней стоимости одной страницы:
    public Double getPriceOnePage(){
        return this.pageCount > 0.0 ? price / pageCount : 0.0;
    }

    // Метод печати средней стоимости одной страницы:
    public void printPriceOnePage(){
        Double priceOnePage = getPriceOnePage();
        System.out.print("Стоимость одной страницы: ");
        System.out.format(Locale.ENGLISH, "%.3f руб.%n", priceOnePage);
    }

    // Метод увеличения стоимости книги в два раза, если название начинается со слова "Программирование":
    public void setPriceX2(){
        String tmpName = this.name.toLowerCase();
        int pos = tmpName.indexOf("программирование");
        if (pos == 0){ // Если подстрока найдена, да еще на нулевой позиции, то
            this.price *= 2;
            System.out.println("Цена книги увеличена в 2 раза: " + this.price + " руб.");
        }
        else System.out.println("Цена книги осталась прежней: " + this.price + " руб.");
    }

    // Метод формирования информации об объекте (книге):
    @Override
    public String toString() {
        return "Книга: \""  + name + '\"' +
                ", количество страниц: " + pageCount +
                ", цена: " + price + " руб.";
    }
}
