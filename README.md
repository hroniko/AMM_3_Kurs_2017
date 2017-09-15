# Материалы за 1 семестр 3 курса ПММ ВГУ "Вечерка"

### 2017-09-13

### Добавлено решение задачи №1 по ООП (Вариант 13) (Java)(С++)(C#)
[Задание:](https://github.com/hroniko/AMM_3_Kurs_2017/blob/master/OOP/lab01/%D0%97%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D0%B501.txt)

Создать класс с полями, указанными в индивидуальном задании (табл. 11.2, столб 2).
Реализовать в классе методы:
- конструктор по умолчанию;
- конструктор перегрузки с параметрами;
- деструктор для освобождения памяти (с сообщением об уничтожении объекта);
- функции обработки данных (1 и 2), указанные в индивидуальном задании (табл. 11.2, столбцы 3 и 4)
- функцию формирования строки информации об объекте.
Вар.13
1. Книга: название, количество страниц, цена. 2. Вычислить среднюю стоимость одной страницы. 3. Увеличить цену книги в два раза, если название начинается со слова "Программирование"

UPD: [Решение на Java](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/OOP/lab01/java)
UPD: [Решение на С++](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/OOP/lab01/c%2B%2B)
UPD: [Решение на С#](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/OOP/lab01/c%23/lab01)

### 2017-09-15
### Добавлено решение задачи №1 по Численным методам (С++)(Matlab)
[Задание:](https://github.com/hroniko/AMM_3_Kurs_2017/blob/master/NM/Lab01/%D0%97%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D0%B501.txt)
(интерполяция полиномом Лагранжа)

1. Написать программу, исходные данные: дан отрезок [a, b] - вводим с клавиатеры,
и функция, по которой будем считать значения в узлах. Используем многочлен второй степени (3 узла),
и они равноотстощие на отрезке [a, b]. С помощью двойного цикла запрограммировать вычисление
многочлена Лагранжа в произволной точке x. --- См. interpolate1

```cpp
double interpolate1(double a, double b, int size, double xx, func f);
```

2. Функция f задана таблицей значений. Найти с помощью многочлена Лагранжа L2(x) приближенное значение
функции в точках x* = 1.5 и x** = 2.5  --- См. interpolate2

```cpp
double interpolate2(vector<double> X, vector<double> Y, double xx);
```

Решение на C++ пока без вывода графиков, не решил еще, какую библиотеку использовать.

#### UPD: добавил решение на Matlab с выводом графиков.
В папке две основные функции: [interpolate1.m](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/matlab/interpolate1.m) и [interpolate2.m](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/matlab/interpolate2.m)
Сама исходная оригинальная функция, по которой рассчитываются узлы, в файле [f.m](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/matlab/f.m). 
Чтобы вызвать рассчет интерполяции, зная только границы отрезка и точку x (пусть она = 2.5), необходимо в командной строке матлаба ввести и выполнить:
```cpp
[Lx, Fx, d] = interpolate1(-1, 3, 2, 2.5)
```
Чтобы вызвать рассчет интерполяции по известным узлам, необходимо в командной строке матлаба сначала сформировать эти узлы, например:
```cpp
X = [1; 2; 3];
Y = [-2; 1; 6];
```
а затем уже выполнить по ним интерполяцию для точки x = 2.5:
```cpp
[Lx, Fx, d] = interpolate2(X, Y, 2.5)
```
Или можно выполнить в командной строке файл [main.m](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/matlab/main.m), в котором все это уже есть с комментариями.
В итоге сформируется новое окно с графиком такого вида:

![Пример графика](https://github.com/hroniko/AMM_3_Kurs_2017/raw/master/NM/Lab01/matlab/figure1.png)

UPD: [Решение на С++](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/c%2B%2B)
UPD: [Решение на Matlab](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/matlab)