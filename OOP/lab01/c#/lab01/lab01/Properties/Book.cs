using System;

namespace lab01.Properties
{
    public class Book // Класс книги
    {
        // Поля:
        private string name = ""; // Название

        private int pageCount = 0; // Количество страниц
        private double price = 0.0; // Цена
        
        // Конструктор по умолчанию:
        public Book()
        {
            
        }
        
        // Конструктор с параметрами:
        public Book(string name, int pageCount, double price)
        {
            this.name = name;
            this.pageCount = pageCount;
            this.price = price;
        }
        
        // Метод вычисления средней стоимости одной страницы:
        public double getPriceOnePage()
        {
            return this.pageCount > 0.0 ? price / pageCount : 0.0;
        }
        
        // Метод печати средней стоимости одной страницы:
        public void printPriceOnePage()
        {
            var pricePnePage = getPriceOnePage();
            Console.WriteLine("Стоимость одной страницы: " + pricePnePage.ToString("F3") + " руб.");
        }
        
        // Метод увеличения стоимости книги в два раза, если название начинается со слова "Программирование":
        public void setPriceX2()
        {
            string tmpName = this.name.ToLower();
            int pos = tmpName.IndexOf("программирование");
            if (pos == 0){ // Если подстрока найдена, да еще на нулевой позиции, то
                this.price *= 2;
                Console.WriteLine("Цена книги увеличена в 2 раза: " + this.price + " руб.");
            }
            else Console.WriteLine("Цена книги осталась прежней: " + this.price + " руб.");
        }
        
        // Метод формирования информации об объекте (книге):
        public override string ToString()
        {
            return "Книга: \""  + name + '\"' +
                   ", количество страниц: " + pageCount +
                   ", цена: " + price + " руб.";
        }
    }
}