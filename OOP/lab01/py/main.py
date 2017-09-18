# -*- coding: utf-8 -*-

class Book: # Класс книги

    def __init__(self, name, pageCount, price): # Конструктор с параметрами
        self.name = name
        self.pageCount = pageCount
        self.price = price

    def getPriceOnePage(self): # Метод вычисления средней стоимости одной страницы
        return (self.price / self.pageCount) if (self.pageCount > 0) else 0.0

    def printPriceOnePage(self): # Метод печати средней стоимости одной страницы
        print("Стоимость одной страницы: " + str("%.2f" % self.getPriceOnePage()) + " руб.")

    def setPriceX2(self): # Метод увеличения стоимости книги в два раза, если название начинается со слова "Программирование":
        num = self.name.lower().find("программирование")
        if num == 0: # Если подстрока найдена (найдено совпадение с нулевой позиции), то
            self.price *= 2
            print("Цена книги увеличена в 2 раза: " + str("%.2f" % self.price) + " руб.")
        else:
            print("Цена книги осталась прежней: " + str("%.2f" % self.price) + " руб.")

    def info(self): # Метод формирования информации об объекте (книге):
        return ("Книга: \""  + str(self.name) + '\"' + ", количество страниц: " + str(self.pageCount) +
                ", цена: " + str(self.price) + " руб.")


# Оновная программа
book = Book("Программирование на Python", 300, 800.00)
print(book.info())
book.printPriceOnePage()

book.setPriceX2()
print(book.info())
book.printPriceOnePage()
