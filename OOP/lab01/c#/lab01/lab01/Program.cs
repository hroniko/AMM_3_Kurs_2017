using System;
using System.Collections.Generic;
using lab01.Properties;

namespace lab01
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            var myBook = new Book("Программирование на C#", 700, 1200.00);
            myBook.printPriceOnePage();
            Console.WriteLine(myBook);
            
            myBook.setPriceX2();
            myBook.printPriceOnePage();
        }
    }
}