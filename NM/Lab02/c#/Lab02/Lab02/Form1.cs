using System;
using System.Drawing;
using System.Windows.Forms;
using ZedGraph;
using System.Collections.Generic;
using System.Drawing.Drawing2D;

namespace Lab02
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent(); // Инициализация компонентов
            GraphPane pane = zedGraphControl1.GraphPane; // Получаем панель для рисования
            pane.XAxis.Title.Text = "X"; // Изменяем тест надписи по оси X
            pane.XAxis.Title.FontSpec.FontColor = Color.Blue; // и цвет на синий
            pane.YAxis.Title.Text = "Y"; // Изменим текст по оси Y
            pane.YAxis.Title.FontSpec.FontColor = Color.Blue; // и цвет на синий
            pane.Title.Text = "Полиномиальная интерполяция (полином Ньютона)"; // Изменяемзаголовок холста
        }

        // [&] Исходная функция, которую аппроксимируем многочленом (можно написать любую)
        private double f(double x)
        {
            return (1 - x) / (1 + x * x);
        }


        // [&] Функция вычисления ошибки:
        double delta(List<double> Y1, List<double> Y2)
        {
            double sum = 0.0;
            int n = Y1.Count;
            for (int i = 0; i < n; i++)
            {
                sum = sum + Math.Abs(Y1[i] -Y2[i]);
            }
            return sum / n;
        }


        // [с] Только для отладки:
        // Метод вывода в консоль значений коэффициентов полинома Ньютона
        void print(List<double> D)
        {
            foreach(double d in D)
            {
                System.Console.Write(d);
                System.Console.Write("; ");
            }
            System.Console.WriteLine();
        }

        // [1] % Метод для вычисления коэффициентов полинома Ньютона путем решения n+1 линейных алгебраических уравнений
        List<double> coefPolyNewton1(List<double> X, List<double> Y)
        {
            List<double> D = new List<double>(); // Создаем список коэффициентов
            int n = X.Count; // Количество узловых точек

            for (int i = 0; i < n; i++) // Внешний цикл по D "слева"
            {
                double chislitel = Y[i];
                for (int j = 0; j < i; j++) // Вложенный цикл по D "справа"
                {
                    double pp = D[j];
                    for (int k = 0; k < j; k++) // Внутренний цикл по Х
                    {
                        pp = pp * (X[i] - X[k]);
                    }
                    chislitel = chislitel - pp;
                }
                // Посчитали числитель, находим знаменатель:
                double znamenatel = 1.0;
                for (int j = 0; j < i; j++)
                {
                    znamenatel = znamenatel * (X[i] - X[j]);
                }
                // Делим числитель на знаменатель и сохраняем полученный результат как коэффициент в список коэффициентов D:
                D.Add(chislitel / znamenatel);
            }
            // print(D);
            return D;
        }



        // [2] Метод для вычисления коэффициентов полинома Ньютона путем вычисления таблицы разделенных разностей RR
        List<double> coefPolyNewton2(List<double> X, List<double> Y)
        {
            List<double> D = new List<double>(); // Создаем список коэффициентов
            int n = X.Count; // Количество узловых точек

            // Создаем и инициализируем двумерный массив для таблицы разделенных разностей
            double[,] RR = new double[n, n];

            // Сначала заполняем нулевой столбец таблицы разделенных разностей RR:
            for (int i = 0; i < n; i++)
            {
                RR[i, 0] = Y[i];
            }

            // Затем на основе нулевого заполненного столбца заполняем оставшиеся:
            for (int j = 1; j < n; j++) // Внешний цикл по столбцам RR
            {
                int m = n - j; // Каждый переход на столбец вправо сокращает количество разностей
                for (int i = 0; i < m; i++) // Внутренний цикл по строкам RR
                {
                    RR[i, j] = (RR[i, j - 1] - RR[i + 1, j - 1]) / (X[i] - X[i + j]);
                }
            }

            // И в конце переписываем из нулевой строки RR в матрицу коэффициентов D:
            for (int j = 0; j < n; j++)
            {
                D.Add(RR[0, j]);
            }
            // print(D);
            return D;
        }


        // [3] Метод для вычисления коэффициентов полинома Ньютона путем вычисления суммы произведений 
        // без вычисления таблицы разделенных разностей
        List<double> coefPolyNewton3(List<double> X, List<double> Y)
        {
            List<double> D = new List<double>(); // Создаем список коэффициентов
            int n = X.Count; // Количество узловых точек

            for (int m = 0; m < n; m++) // Внешний цикл по D(m)
            {
                double sum = 0.0; // Для каждого D(m) в первую очередь обнуляем сумму,
                // а затем считаем произведение и суммируем с суммой:
                for (int i = 0; i <= m; i++) // Вложенный цикл по Сумме
                {
                    double pp = Y[i]; // Числитель одного из слагаемых
                    double dd = 1.0; // Начальное значение знаменателя
                    // и вычисляем значенатель:
                    for (int j = 0; j <= m; j++) // Внутренний цикл по Произведению
                    {
                        if (i != j) // Должны быть не равны, иначе знаменатель обнулится
                        {
                            dd = dd * (X[i] - X[j]);
                        }
                    }
                    sum = sum + pp / dd; // Добавляем к сумме
                }
                D.Add(sum);
            }
            //print(D);
            return D;
        }


        // [*] Метод рассчета списка координат Х узловых точек для интервала [a, b] и степени многочлена n:
        List<double> createXList(double a, double b, int n)
        {
            List<double> X = new List<double>(); // Создаем список координат х для узловых точек

            double delta = Math.Abs(a - b) / n; // Находим интервал разбиения
            X.Add(a); // Начало отрезка
            for (int i = 1; i < n; i++)
            { // Заполняем вектор X
                X.Add(X[i - 1] + delta);
            }
            X.Add(b); // конец отрезка

            return X;
        }

        // [*] Метод рассчета списка координат Y узловых точек для интервала [a, b] и степени многочлена n:
        List<double> createYList(List<double> X)
        {
            List<double> Y = new List<double>(); // Создаем список координат х для узловых точек

            for (int i = 0; i < X.Count; i++)
            { // Заполняем вектор Y
                Y.Add(f(X[i]));
            }

            return Y;
        }

        // [!] Основной метод рассчета коэффициентов полинома Ньютона тремя разными способами,
        // номер способа передается последним параметром(1, 2 или 3),
        // первые три параметра(a, b, n) - границы отрезка и степень полинома
        List<double> coefPolyNewtonBase(double a, double b, int n, int number)
        {
            // Считаем значения X и Y в равноотстоящих точках на отрезке[a, b]:
            List<double> X = createXList(a, b, n);
            List<double> Y = createYList(X);

            // В зависимости от выбранного варианта расчета запускаем нужную функцию:
            switch (number)
            {
                case 1:
                    return coefPolyNewton1(X, Y);
                case 2:
                    return coefPolyNewton2(X, Y);
                case 3:
                    return coefPolyNewton3(X, Y);
                default: // Если номер метода некорректен
                    X = createXList(0, 0, n);
                    Y = createYList(X);
                    return coefPolyNewton1(X, Y);
            }

        }

        // [!!] Метод рассчета значения полинома Ньютона в точке xx. На вход получает матрицу коэффициентов D,
        // матрицу узловых точек X и значение xx, для которого надо посчитать P(xx)
        double pointNewton(List<double> D, List<double> X, double xx)
        {
            int n = X.Count; // Количество узловых точек
            double p = 0; // Начальное значение полинома в точке

            for (int i = 0; i < n; i++) // Внешний цикл по коэффициентам D(i)
            {
                double pp = D[i];
                for (int j = 0; j < i; j++) // Внутренний цикл по произведениям на разности (по X(j))
                {
                    pp = pp * (xx - X[j]);
                }
                p = p + pp;
            }

            return p;
        }


        // [V] Метод очистки холста от старых графиков:
        void clearPlot()
        {            
            GraphPane pane = zedGraphControl1.GraphPane; // Получаем панель для рисования            
            pane.CurveList.Clear(); // Очищаем список кривых
        }


        // [V] Метод нанесения на холст узловых точек:
        void plotBasePoints(List<double> X, List<double> Y)
        {            
            GraphPane pane = zedGraphControl1.GraphPane; // Получаем панель для рисования:
            
            PointPairList list = new PointPairList(); // Создаем список точек
            for (int i = 0; i < X.Count; i++)
            { 
                list.Add(X[i], Y[i]); // Заполняем список точек:
            }

            // Создаем кривую с названием "Узловые точки". Обводка кружков будут рисоваться красным цветом (Color.Red),
            // Опорные точки - кружки (SymbolType.Circle)
            LineItem myCurve = pane.AddCurve("Узловые точки", list, Color.Red, SymbolType.Circle);
            myCurve.Line.IsVisible = false; // У кривой линия будет невидимой
            myCurve.Symbol.Size = 10; // Размер кружков 10

            zedGraphControl1.AxisChange(); // Обновляем данные об осях.
            zedGraphControl1.Invalidate(); // Обновляем график
        }


        // [V] перегруженный метод нанесения на холст узловых точек:
        void plotBasePoints(double a, double b, int n)
        {
            List<double> X = createXList(a, b, n); // Формируем вектор X
            List<double> Y = createYList(X); // Формируем вектор Y
            plotBasePoints(X, Y);

        }


        // [V] Метод нанесения на холст графика функции:
        void plotFunction(double a, double b, int countOfPoints)
        {
            // Передаем в функцию границы отрезка a и b, число разбиений (тут уже побольше, чем узлов, раз в 10 побольше) 
            List<double> X = createXList(a, b, countOfPoints); // Формируем вектор X
            List<double> Y = createYList(X); // Формируем вектор Y

            GraphPane pane = zedGraphControl1.GraphPane; // Получаем панель для рисования

            PointPairList list = new PointPairList(); // Создаем список точек
            for (int i = 0; i < X.Count; i++)
            { 
                list.Add(X[i], Y[i]); // Заполняем список точек:
            }

            LineItem myCurve = pane.AddCurve("График функции", list, Color.Red, SymbolType.None); // Создаем кривую
            zedGraphControl1.AxisChange(); // Обновляем данные об осях.
            zedGraphControl1.Invalidate(); // Обновляем график
        }

        // [V] Метод нанесения на холст графика полинома:
        // a,b - границы отрезка, n - степень полинома, countOfPoints - число точек на графике (больше n hfp d 10),
        // number - номер способа рассчета коэффициентов полинома
        void plotNewton(double a, double b, int n, int countOfPoints, int number) 
        {
            List<double> D = coefPolyNewtonBase(a, b, n, number); // Формируем список коэффициентов способом number !!!!

            List<double> basePointsX = createXList(a, b, n); // Формируем узловые точки

            List<double> X = createXList(a, b, countOfPoints); // Формируем вектор X, точки уже для графика, не для узлов
            List<double> Y = new List<double>(); // Формируем вектор Y, для графика
            foreach (double xx in X)
            {
                Y.Add(pointNewton(D, basePointsX, xx));
            }
            
            GraphPane pane = zedGraphControl1.GraphPane; // Получаем панель для рисования            
            PointPairList list = new PointPairList(); // Создаем список точек (координат х-у)
            for (int i = 0; i < X.Count; i++)
            { 
                list.Add(X[i], Y[i]); // Заполняем список точек:
            }

            LineItem myCurve;
            switch (number) // Создаем кривую с параметрами в зависимости от выбранного способа
            {
                case 1:
                    myCurve = pane.AddCurve("Полином Ньютона №1", list, Color.Blue, SymbolType.None);
                    break;
                case 2:
                    myCurve = pane.AddCurve("Полином Ньютона №2", list, Color.DarkGreen, SymbolType.None);
                    break;
                case 3:
                    myCurve = pane.AddCurve("Полином Ньютона №3", list, Color.Orange, SymbolType.None);
                    break;
            }

            zedGraphControl1.AxisChange(); // Обновляем данные об осях
            zedGraphControl1.Invalidate(); // Обновляем график
        }

        // [^] Метод автомасштаба (расчетный, работает лучше)
        private void plotMashtab(double a, double b, int n)
        {
            GraphPane pane = zedGraphControl1.GraphPane; // Получаем панель для рисования
            // Устанавливаем интересующий нас интервал по оси X
            pane.XAxis.Scale.Min = a-0.1; // xmin_limit;
            pane.XAxis.Scale.Max = b+0.1; // xmax_limit;

            // Устанавливаем интересующий нас интервал по оси Y
            // Для этого нам надо получить минимум и максимум Y
            List<double> X = createXList(a, b, 1000); // Формируем вектор X
            List<double> Y = createYList(X); // Формируем вектор Y
            Y.Sort(); // Сортируем по возрастанию
            // Устанавливаем интересующий нас интервал по оси Y
            pane.YAxis.Scale.Min = Y[0] - 0.1; // ymin_limit;
            pane.YAxis.Scale.Max = Y[Y.Count-1] + 0.1; // ymax_limit;

            zedGraphControl1.AxisChange(); // Обновляем данные об осях            
            zedGraphControl1.Invalidate(); // Обновляем график
        }

        // [^] Метод автомасштаба (встроенный, похуже)
        private void autoMashtab()
        {
            GraphPane pane = zedGraphControl1.GraphPane; // Получаем панель для рисования

            // Установим масштаб по умолчанию для оси X
            pane.XAxis.Scale.MinAuto = true;
            pane.XAxis.Scale.MaxAuto = true;

            // Установим масштаб по умолчанию для оси Y
            pane.YAxis.Scale.MinAuto = true;
            pane.YAxis.Scale.MaxAuto = true;
                        
            zedGraphControl1.AxisChange(); // Обновим данные об осях            
            zedGraphControl1.Invalidate(); // Обновляем график
        }

        // [**] Аккумулирующий метод отстройки графиков
        void plotButtonCommand(int number)
        {
            // Читаем значения полей в соотвествующие переменные:
            double a = 0.0;
            Double.TryParse(txtA.Text, out a);
            double b = 0.0;
            Double.TryParse(txtB.Text, out b);
            int n = 0;
            int.TryParse(txtN.Text, out n);

            // Работаем с графиками:
            clearPlot(); // Очищаем холст
            plotBasePoints(a, b, n); // Печатаем узловые точки
            plotFunction(a, b, 10000); // Печатаем график функции (1000 точек)

            if (number < 4) // Если получили номер от 1 до 3, то выводим один график
            {
                plotNewton(a, b, n, 10000, number); // Печатаем график полинома, посчитанного number способом, выводим 1000 точек
            }
            else // иначе выводим все графики
            {
                for (int i = 1; i < 4; i++)
                {
                    plotNewton(a, b, n, 10000, i);
                }                
            }
            //plotMashtab(a, b, n); // Выставляем автомасштаб (рассчетным способом)
        }

        // [^] Метод печати графика ошибки для текущего номера способа рассчета number
        void plotErrors(double a, double b, int n, int number)
        {
            GraphPane pane = zedGraphControl1.GraphPane; // Получаем панель для рисования 
            PointPairList Errors = new PointPairList(); // Создаем список точек (координат х-у)
            for (int i = 2; i <= 40; i++) // Пробегаем по всем значениям n от 2 до 40
            {
                List<double> pointsX = createXList(a, b, i); // Узлы
                List<double> D = coefPolyNewtonBase(a, b, i, number); // Коэффициенты

                List<double> X = createXList(a, b, 100); // Точки для рассчетов
                List<double> Y1 = createYList(X); // Значения исходной функции
                List<double> Y2 = new List<double>(); // Значения полинома
                foreach (double x in X)
                {
                    Y2.Add(pointNewton(D, pointsX, x));
                }

                double error = delta(Y1, Y2);
                
                Errors.Add(i, error); // заносим точку ошибки в список

                if (i == n)
                {
                    txt_Error.Text += error + Environment.NewLine; // Если совпал номер, выведем в поле
                }
            }
            // И тут надо напечатать:
            LineItem myCurve;
            switch (number) // Создаем кривую с параметрами в зависимости от выбранного способа
            {
                case 1:
                    myCurve = pane.AddCurve("Погрешность метода №1", Errors, Color.Blue, SymbolType.None);
                    break;
                case 2:
                    myCurve = pane.AddCurve("Погрешность метода №2", Errors, Color.DarkGreen, SymbolType.None);
                    break;
                case 3:
                    myCurve = pane.AddCurve("Погрешность метода №3", Errors, Color.Orange, SymbolType.None);
                    break;
            }
            zedGraphControl1.AxisChange(); // Обновляем данные об осях
            zedGraphControl1.Invalidate(); // Обновляем график
        }


        // [btn] Вывод графика полинома Ньютона по первому методу
        private void btn_Newton1_Click(object sender, EventArgs e)
        {
            plotButtonCommand(1);
        }

        // [btn] Вывод графика полинома Ньютона по второму методу
        private void btn_Newton2_Click(object sender, EventArgs e)
        {
            plotButtonCommand(2);
        }

        // [btn] Вывод графика полинома Ньютона по третьему методу
        private void btn_Newton3_Click(object sender, EventArgs e)
        {
            plotButtonCommand(3);
        }

        // [btn] Вывод графика полинома Ньютона по всем методам
        private void btn_NewtonFull_Click(object sender, EventArgs e)
        {
            plotButtonCommand(4);
        }

        // [btn] Вызов Метода автомасштаба №1
        private void btn_Mashtab1_Click(object sender, EventArgs e)
        {
            // Читаем значения полей в соотвествующие переменные:
            double a = 0.0;
            Double.TryParse(txtA.Text, out a);
            double b = 0.0;
            Double.TryParse(txtB.Text, out b);
            int n = 0;
            int.TryParse(txtN.Text, out n);

            plotMashtab(a, b, n); // Выставляем автомасштаб (рассчетным способом)
        }

        // [btn] Вызов Метода автомасштаба №2
        private void btn_Mashtab2_Click(object sender, EventArgs e)
        {
            // Читаем значения полей в соотвествующие переменные:
            double a = 0.0;
            Double.TryParse(txtA.Text, out a);
            double b = 0.0;
            Double.TryParse(txtB.Text, out b);
            int n = 0;
            int.TryParse(txtN.Text, out n);

            autoMashtab(); // Выставляем автомасштаб (встроенным способом)
        }

        // [btn] Метод вызова печати графика ошибки
        private void btn_Error_Click(object sender, EventArgs e)
        {
            // Читаем значения полей в соотвествующие переменные:
            double a = 0.0;
            Double.TryParse(txtA.Text, out a);
            double b = 0.0;
            Double.TryParse(txtB.Text, out b);
            int n = 0;
            int.TryParse(txtN.Text, out n);

            txt_Error.Text = ""; // Очищаем
            clearPlot(); // Очищаем

            for (int j = 1; j < 4; j++) // Пробегаем по всем способам рассчета коэффициентов
            {
                plotErrors(a, b, n, j);
            }
        }


       
    }
}
