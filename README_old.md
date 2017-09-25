# Материалы за 1 семестр 3 курса ПММ ВГУ "Вечерка"

### 2017-09-13, UPD 2017-09-18 (Python)

### Добавлено решение задачи №1 по ООП (Вариант 13) (Java)(С++)(C#)(Python)
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
UPD: [Решение на Python](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/OOP/lab01/py)

### 2017-09-15, UPD 2017-09-20 (Python), UPD 2017-09-24 (C#)
### Добавлено решение задачи №1 по Численным методам (С++)(Matlab)(Python)(C#)
[Задание:](https://github.com/hroniko/AMM_3_Kurs_2017/blob/master/NM/Lab01/%D0%97%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D0%B501.txt)
(интерполяция полиномом Лагранжа)

1. Написать программу, исходные данные: дан отрезок [a, b] - вводим с клавиатуры,
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
```matlab
[Lx, Fx, d] = interpolate1(-1, 3, 2, 2.5)
```
Чтобы вызвать рассчет интерполяции по известным узлам, необходимо в командной строке матлаба сначала сформировать эти узлы, например:
```matlab
X = [1; 2; 3];
Y = [-2; 1; 6];
```
а затем уже выполнить по ним интерполяцию для точки x = 2.5:
```matlab
[Lx, Fx, d] = interpolate2(X, Y, 2.5)
```
Или можно выполнить в командной строке файл [main.m](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/matlab/main.m), в котором все это уже есть с комментариями.
В итоге сформируется новое окно с графиком такого вида:

![Пример графика](https://github.com/hroniko/AMM_3_Kurs_2017/raw/master/NM/Lab01/matlab/img/figure1.png)

#### UPD: 2017-09-24 добавил к решению на Matlab вывод полного графика функции и графика полинома.
Все оформлено в отдельную функцию без возвращаемых параметров [interpolate3.m](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/matlab/interpolate3.m), вызов следующего вида (как пример):

```matlab
interpolate3(a, b, size)
```
где a и b - концы отрезка, size - степень полинома Лагранжа.
Получим окно с графиком:

![Пример графика](https://github.com/hroniko/AMM_3_Kurs_2017/raw/master/NM/Lab01/matlab/img/figure2.png)

Кроме того, добавил пару функций для расчета абсолютной погрешности: [delta.m](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/matlab/delta.m) и [deltaPlot.m](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/matlab/deltaPlot.m). Первая из них вычисляет погрешность между функцией и полиномом Лагранжа, вторая строит график зависимости погрешности от степени полинома Лагранжа:

```matlab
deltaPlot(a, b, size1, size2)
```
где a и b - концы отрезка, size1 и size2 - начальная и конечная степень полинома Лагранжа.
Получим окно с графиком:

![Зависимость погрешности от степени полинома](https://github.com/hroniko/AMM_3_Kurs_2017/raw/master/NM/Lab01/matlab/img/figure3.png)

#### UPD: добавил решение на Python (Jupyter Notebook) с выводом графиков.

#### UPD: 2017-09-24 добавил [решение](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/c%23/Lab01) на C# на основе [WinForms](https://ru.wikipedia.org/wiki/Windows_Forms) и свободной библиотеки [ZedGraph](http://zedgraph.sourceforge.net/samples.html).
Окошко имеет вид:


![Пример графика](https://raw.githubusercontent.com/hroniko/AMM_3_Kurs_2017/master/NM/Lab01/c%23/img/figure1.png)


UPD: [Решение на С++](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/c%2B%2B)
UPD: [Решение на Matlab](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/matlab)
UPD: [Решение на Python](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/py/Lab01.ipynb)
UPD: [Решение на C#](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/c%23/Lab01)

### 2017-09-17

### Добавлено решение задачи №1 по ООП (Вариант 11) (С++)
[Задание:](https://github.com/hroniko/AMM_3_Kurs_2017/blob/master/OOP/lab01z/%D0%97%D0%B0%D0%B4%D0%B0%D0%BD%D0%B8%D0%B501.txt)

Создать класс с полями, указанными в индивидуальном задании (табл. 11.2, столб 2).
Реализовать в классе методы:
- конструктор по умолчанию;
- конструктор перегрузки с параметрами;
- деструктор для освобождения памяти (с сообщением об уничтожении объекта);
- функции обработки данных (1 и 2), указанные в индивидуальном задании (табл. 11.2, столбцы 3 и 4)
- функцию формирования строки информации об объекте.

Вар.11
1. Комплексное число: действительная (a1) и мнимая (b1) части числа. 2. Вычислить модуль комплексного числа. 3. Найти комплексное число, обратное заданному.

UPD: [Решение на С++](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/OOP/lab01z/c%2B%2B)

### 2017-09-20

### Добавлено решение задачи №1 по Численным методам (Python)

В папке файл в формате Jupyter Notebook.

UPD: [Решение на Python](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/py/Lab01.ipynb)

### 2017-09-24

### Обновлено решение задачи №1 по Численным методам (Matlab)

В папке новые файлы в формате *.m.

UPD: [Решение на Matlab](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/matlab)

### 2017-09-24

### Добавлено решение задачи №1 по Численным методам (C#)

Решение на основе WinForms и библиотеки ZedGraph.

UPD: [Решение на C#](https://github.com/hroniko/AMM_3_Kurs_2017/tree/master/NM/Lab01/c%23/Lab01)