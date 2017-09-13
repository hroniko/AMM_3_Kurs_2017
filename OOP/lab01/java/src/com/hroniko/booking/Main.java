package com.hroniko.booking;

public class Main {

    public static void main(String[] args) {

        Book myBook = new Book("Программирование на Java", 900, 1500.00);
        myBook.printPriceOnePage();
        System.out.println(myBook);

        myBook.setPriceX2();
        myBook.printPriceOnePage();

    }
}
