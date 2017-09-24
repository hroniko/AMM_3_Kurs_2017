using System;
using System.Drawing;
using System.Windows.Forms;
using ZedGraph;
using System.Collections.Generic;
using System.Drawing.Drawing2D;

namespace Lab01
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            // Инициализация компонентов:

            // Получим панель для рисования
            GraphPane pane = zedGraphControl1.GraphPane;

            // Изменим тест надписи по оси X
            pane.XAxis.Title.Text = "X";
            pane.XAxis.Title.FontSpec.FontColor = Color.Blue;
            // Изменим текст по оси Y
            pane.YAxis.Title.Text = "Y";
            pane.YAxis.Title.FontSpec.FontColor = Color.Blue;

            // Изменим текст заголовка графика
            pane.Title.Text = "Полиномиальная интерполяция (полином Лагранжа)";
        }



        // Исходная функция, которую аппроксимируем многочленом (можно написать любую)
        private double f(double x)
        {
            return (1 - x) / (1 + x * x);
        }


        // Функция вычисления ошибки:
        double delta(double y1, double y2)
        {
            return Math.Abs(y1 - y2);
        }

        // Основная функция интерполяции
        double interpolate2(List<double> X, List<double> Y, double xx)
        {
            double sum = 0.0; // Сумма-накопитель
            for (int i = 0; i < X.Count; i++)
            {
                double pp = Y[i];
                for (int j = 0; j < X.Count; j++)
                {
                    if (i != j)
                    {
                        pp *= (xx - X[j]) / (X[i] - X[j]);
                    }
                }
                sum += pp;
            }
            return sum;
        }

        // Основная функция интерполяции (альтернативная, раздельно считаются числитель и знаменатель)
        double interpolate2alt(List<double> X, List<double> Y, double xx)
        {
            double sum = 0.0; // Сумма-накопитель
            for (int i = 0; i < X.Count; i++)
            {
                double pp = Y[i];
                for (int j = 0; j < X.Count; j++)
                {
                    if (i != j)
                    {
                        pp *= (xx - X[j]); // Считаем числитель
                    }
                }

                double pd = 1.0;
                for (int j = 0; j < X.Count; j++)
                {
                    if (i != j)
                    {
                        pd *= (X[i] - X[j]); // Считаем знаменатель
                    }
                }

                sum += pp / pd;
            }
            return sum;
        }

        // Вспомогательная функция интерполяции (+ расчет векторов X и Y)
        double interpolate1(double a, double b, int size, double xx)
        {
            // Передаем в функцию границы отрезка a и b, число разбиений (узлов) этого отрезка size
            // и значение xx, для которого ищем y, а также функция f, для которой это все ищется

            List<double> X = new List<double>(); // Формируем вектор X (пустой)
            List<double> Y = new List<double>(); // Формируем вектор Y (пустой)
            double delta = Math.Abs(a - b) / (size - 1); // Находим интервал разбиения
            X.Add(a); // Начало отрезка

            for (int i = 1; i < size - 1; i++)
            { // Заполняем вектор X
                X.Add(X[i - 1] + delta);
            }

            X.Add(b); // конец отрезка

            for (int i = 0; i < size; i++)
            { // Заполняем вектор Y
                Y.Add(f(X[i]));
            }


            // И вызываем основную функцию
            return interpolate2(X, Y, xx);
        }

        // Вспомогательная функция интерполяции (Альтернативная + расчет векторов X и Y)
        double interpolate1alt(double a, double b, int size, double xx)
        {
            // Передаем в функцию границы отрезка a и b, число разбиений (узлов) этого отрезка size
            // и значение xx, для которого ищем y, а также функция f, для которой это все ищется

            List<double> X = new List<double>(); // Формируем вектор X (пустой)
            List<double> Y = new List<double>(); // Формируем вектор Y (пустой)
            double delta = Math.Abs(a - b) / (size - 1); // Находим интервал разбиения
            X.Add(a); // Начало отрезка

            for (int i = 1; i < size - 1; i++)
            { // Заполняем вектор X
                X.Add(X[i - 1] + delta);
            }

            X.Add(b); // конец отрезка

            for (int i = 0; i < size; i++)
            { // Заполняем вектор Y
                Y.Add(f(X[i]));
            }


            // И вызываем основную функцию
            return interpolate2alt(X, Y, xx);
        }


        private double f2(double x)
        {
            if (x == 0)
            {
                return 1;
            }

            return Math.Cos(x);
        }


        private void DrawGraph()
        {
            // Получим панель для рисования
            GraphPane pane = zedGraphControl1.GraphPane;



            // Очистим список кривых на тот случай, если до этого сигналы уже были нарисованы
            pane.CurveList.Clear();

            // Создадим список точек
            PointPairList list = new PointPairList();
            PointPairList list2 = new PointPairList();

            double xmin = -50;
            double xmax = 50;

            // Заполняем список точек
            for (double x = xmin; x <= xmax; x += 0.01)
            {
                // добавим в список точку
                list.Add(x, f(x));
                list2.Add(x, f2(x));
            }

            // Создадим кривую с названием "Sinc", 
            // которая будет рисоваться голубым цветом (Color.Blue),
            // Опорные точки выделяться не будут (SymbolType.None)
            LineItem myCurve = pane.AddCurve("Sinc", list, Color.Blue, SymbolType.None);
            LineItem myCurve2 = pane.AddCurve("Cosc", list2, Color.Red, SymbolType.None);

            // Вызываем метод AxisChange (), чтобы обновить данные об осях. 
            // В противном случае на рисунке будет показана только часть графика, 
            // которая умещается в интервалы по осям, установленные по умолчанию
            zedGraphControl1.AxisChange();

            // Обновляем график
            zedGraphControl1.Invalidate();
        }

        private void DrawMashtab()
        {

            // 1 Читаем значения полей в соотвествующие переменные:
            double a = 0.0;
            Double.TryParse(txtA.Text, out a);

            double b = 0.0;
            Double.TryParse(txtB.Text, out b);

            int n = 0;
            int.TryParse(txtN.Text, out n);

            // Получим панель для рисования
            GraphPane pane = zedGraphControl1.GraphPane;
            // !!!
            // Устанавливаем интересующий нас интервал по оси X
            pane.XAxis.Scale.Min = a-0.1; // xmin_limit;
            pane.XAxis.Scale.Max = b+0.1; // xmax_limit;

            // !!!
            // Устанавливаем интересующий нас интервал по оси Y
            // Для этого нам надо получить минимум и максимум Y
            List<double> X = new List<double>(); // Формируем вектор X (пустой)
            List<double> Y = new List<double>(); // Формируем вектор Y (пустой)
            double delta = Math.Abs(a - b) / (100); // Находим интервал разбиения
            X.Add(a); // Начало отрезка

            for (int i = 1; i < 100; i++)
            { // Заполняем вектор X
                X.Add(X[i - 1] + delta);
            }

            X.Add(b); // Начало и конец отрезка

            for (int i = 0; i < 100; i++)
            { // Заполняем вектор Y
                Y.Add(f(X[i]));
            }

            Y.Sort();

            pane.YAxis.Scale.Min = Y[0] - 0.1; // ymin_limit;
            pane.YAxis.Scale.Max = Y[99] + 0.1; // ymax_limit;

            zedGraphControl1.AxisChange();

            // Обновляем график
            zedGraphControl1.Invalidate();
        }

        private void AutoMashtab()
        {
            GraphPane pane = zedGraphControl1.GraphPane;

            // Установим масштаб по умолчанию для оси X
            pane.XAxis.Scale.MinAuto = true;
            pane.XAxis.Scale.MaxAuto = true;

            // Установим масштаб по умолчанию для оси Y
            pane.YAxis.Scale.MinAuto = true;
            pane.YAxis.Scale.MaxAuto = true;

            // Обновим данные об осях
            zedGraphControl1.AxisChange();

            // Обновляем график
            zedGraphControl1.Invalidate();
        }



        private void btnDraw_Click(object sender, EventArgs e)
        {
            // 1 Читаем значения полей в соотвествующие переменные:
            double a = 0.0; 
            Double.TryParse(txtA.Text, out a);

            double b = 0.0;
            Double.TryParse(txtB.Text, out b);

            int n = 0;
            int.TryParse(txtN.Text, out n);

            // Получим панель для рисования
            GraphPane pane = zedGraphControl1.GraphPane;


            // Очистим список кривых на тот случай, если до этого сигналы уже были нарисованы
            pane.CurveList.Clear();


            // 2 Печатаем узловые точки через вспомогательный метод:
            plotPoints(a, b, n+1);

            // 3 Печатаем график функции на заданном интервале:
            plotFunction(a, b, n * 100);

            // 4 Печатаем график полинома на заданном интервале:
            plotLagrange(a, b, n * 100, n + 1);


            //DrawGraph();
        }

        // Вспомогательный метод для печати узловых точек:
        private void plotPoints(double a, double b, int size)
        {
            // Передаем в функцию границы отрезка a и b, число разбиений (узлов) этого отрезка size
            // и значение xx, для которого ищем y, а также функция f, для которой это все ищется
            List<double> X = new List<double>(); // Формируем вектор X (пустой)
            List<double> Y = new List<double>(); // Формируем вектор Y (пустой)
            double delta = Math.Abs(a - b) / (size - 1); // Находим интервал разбиения
            X.Add(a); // Начало отрезка
            //X[0] = a; X[size - 1] = b; // Начало и конец отрезка

            for (int i = 1; i < size - 1; i++)
            { // Заполняем вектор X
                X.Add(X[i - 1] + delta);
                //X[i] = X[i - 1] + delta;
            }

            X.Add(b); // Начало и конец отрезка

            for (int i = 0; i < size; i++)
            { // Заполняем вектор Y
                Y.Add(f(X[i]));
                // Y[i] = f(X[i]);
            }

            // Получаем панель для рисования:
            GraphPane pane = zedGraphControl1.GraphPane;

            // Создадим список точек
            PointPairList list = new PointPairList();
            for (int i = 0; i < size; i++)
            { // Заполняем список точек:
                list.Add(X[i], Y[i]);
            }

            // Создаем кривую с названием "Узловые точки".
            // Обводка кружков будут рисоваться красным цветом (Color.Red),
            // Опорные точки - кружки (SymbolType.Circle)
            LineItem myCurve = pane.AddCurve("Узловые точки", list, Color.Red, SymbolType.Circle);

            // У кривой линия будет невидимой
            myCurve.Line.IsVisible = false;

            // Цвет заполнения отметок (кружков) - красный
            // myCurve.Symbol.Fill.Color = Color.Red;

            // Тип заполнения - сплошная заливка
            // myCurve.Symbol.Fill.Type = FillType.Solid;

            // !!!
            // Размер кружков
            myCurve.Symbol.Size = 10;


            // Устанавливаем интересующий нас интервал по оси X
            //pane.XAxis.Scale.Min = X[0];
            //pane.XAxis.Scale.Max = X[size - 1];

            // Устанавливаем интересующий нас интервал по оси Y
            //pane.YAxis.Scale.Min = Y[0];
            //pane.YAxis.Scale.Max = Y[size - 1];

            // Вызываем метод AxisChange (), чтобы обновить данные об осях. 
            // В противном случае на рисунке будет показана только часть графика, 
            // которая умещается в интервалы по осям, установленные по умолчанию
            zedGraphControl1.AxisChange();

            // Обновляем график
            zedGraphControl1.Invalidate();

        }


        // Вспомогательный метод печати графика функции на заданном интервале:
        private void plotFunction(double a, double b, int size)
        {
            // Передаем в функцию границы отрезка a и b, число разбиений (тут уже побольше, чем узлов, раз в 10 побольше) этого отрезка size
            // и значение xx, для которого ищем y, а также функция f, для которой это все ищется
            List<double> X = new List<double>(); // Формируем вектор X (пустой)
            List<double> Y = new List<double>(); // Формируем вектор Y (пустой)
            double delta = Math.Abs(a - b) / (size - 1); // Находим интервал разбиения
            X.Add(a); // Начало отрезка

            for (int i = 1; i < size - 1; i++)
            { // Заполняем вектор X
                X.Add(X[i - 1] + delta);
            }

            X.Add(b); // конец отрезка

            for (int i = 0; i < size; i++)
            { // Заполняем вектор Y
                Y.Add(f(X[i]));
            }

            // Получаем панель для рисования:
            GraphPane pane = zedGraphControl1.GraphPane;

            // Создадим список точек
            PointPairList list = new PointPairList();
            for (int i = 0; i < size; i++)
            { // Заполняем список точек:
                list.Add(X[i], Y[i]);
            }

            // Создаем кривую с названием "График функции".
            LineItem myCurve = pane.AddCurve("График функции", list, Color.Red, SymbolType.None);


            // Вызываем метод AxisChange (), чтобы обновить данные об осях. 
            zedGraphControl1.AxisChange();

            // Обновляем график
            zedGraphControl1.Invalidate();
        }

        // Вспомогательный метод печати графика интерполяционного полинома Лагранжа:
        private void plotLagrange(double a, double b, int size, int size2)
        {
            // Передаем в функцию границы отрезка a и b, число разбиений (тут уже побольше, чем узлов, раз в 10 побольше) этого отрезка size
            // и значение xx, для которого ищем y, а также функция f, для которой это все ищется
            List<double> X = new List<double>(); // Формируем вектор X (пустой)
            List<double> Y = new List<double>(); // Формируем вектор Y (пустой)
            double delta = Math.Abs(a - b) / (size - 1); // Находим интервал разбиения
            X.Add(a); // Начало отрезка
            //X[0] = a; X[size - 1] = b; // Начало и конец отрезка

            for (int i = 1; i < size - 1; i++)
            { // Заполняем вектор X
                X.Add(X[i - 1] + delta);
            }

            X.Add(b); // конец отрезка

            for (int i = 0; i < size; i++)
            { // Заполняем вектор Y
                Y.Add(interpolate1(a, b, size2, X[i]));
            }

            // Получаем панель для рисования:
            GraphPane pane = zedGraphControl1.GraphPane;

            // Создадим список точек
            PointPairList list = new PointPairList();
            for (int i = 0; i < size; i++)
            { // Заполняем список точек:
                list.Add(X[i], Y[i]);
            }

            // Создаем кривую с названием "Полином Лагранжа".
            LineItem myCurve = pane.AddCurve("Полином Лагранжа", list, Color.Blue, SymbolType.None);

            // Используем предустановленный стиль, рисующий кривую в виде штрихпунктирной линии.
            // myCurve.Line.Style = DashStyle.DashDot;

            // Укажем, что график должен быть сглажен
            // myCurve.Line.IsSmooth = true;


            // Вызываем метод AxisChange (), чтобы обновить данные об осях. 
            zedGraphControl1.AxisChange();

            // Обновляем график
            zedGraphControl1.Invalidate();
        }

        // Вспомогательный метод печати графика интерполяционного полинома Лагранжа:
        private void plotLagrangeAlt(double a, double b, int size, int size2)
        {
            // Передаем в функцию границы отрезка a и b, число разбиений (тут уже побольше, чем узлов, раз в 10 побольше) этого отрезка size
            // и значение xx, для которого ищем y, а также функция f, для которой это все ищется
            List<double> X = new List<double>(); // Формируем вектор X (пустой)
            List<double> Y = new List<double>(); // Формируем вектор Y (пустой)
            double delta = Math.Abs(a - b) / (size - 1); // Находим интервал разбиения
            X.Add(a); // Начало отрезка
            //X[0] = a; X[size - 1] = b; // Начало и конец отрезка

            for (int i = 1; i < size - 1; i++)
            { // Заполняем вектор X
                X.Add(X[i - 1] + delta);
            }

            X.Add(b); // конец отрезка

            for (int i = 0; i < size; i++)
            { // Заполняем вектор Y
                Y.Add(interpolate1alt(a, b, size2, X[i]));
            }

            // Получаем панель для рисования:
            GraphPane pane = zedGraphControl1.GraphPane;

            // Создадим список точек
            PointPairList list = new PointPairList();
            for (int i = 0; i < size; i++)
            { // Заполняем список точек:
                list.Add(X[i], Y[i]);
            }

            // Создаем кривую с названием "Полином Лагранжа".
            LineItem myCurve = pane.AddCurve("Полином Альтер.", list, Color.Brown, SymbolType.None);

            // Используем предустановленный стиль, рисующий кривую в виде штрихпунктирной линии.
            // myCurve.Line.Style = DashStyle.DashDot;

            // Укажем, что график должен быть сглажен
            // myCurve.Line.IsSmooth = true;


            // Вызываем метод AxisChange (), чтобы обновить данные об осях. 
            zedGraphControl1.AxisChange();

            // Обновляем график
            zedGraphControl1.Invalidate();
        }


        private void btnAutoMashtab_Click(object sender, EventArgs e)
        {
            AutoMashtab();
        }

        private void btnMashtab2_Click(object sender, EventArgs e)
        {
            DrawMashtab();
        }

        private void btnDelta_Click(object sender, EventArgs e)
        {
            // Вычисление суммарной погрешности для 100 точек между a и b
        }

        private void btnDelta_Click_1(object sender, EventArgs e)
        {
            // 1 Читаем значения полей в соотвествующие переменные:
            double a = 0.0;
            Double.TryParse(txtA.Text, out a);

            double b = 0.0;
            Double.TryParse(txtB.Text, out b);

            int n = 0;
            int.TryParse(txtN.Text, out n);

            int size = 1000;

            double sum = 0.0;

            // 2
            List<double> X = new List<double>(); // Формируем вектор X (пустой)
            double delta = Math.Abs(a - b) / (size-1); // Находим интервал разбиения
            X.Add(a); // Начало отрезка

            for (int i = 1; i < size; i++)
            { // Заполняем вектор X
                X.Add(X[i - 1] + delta);
            }

            X.Add(b); // конец отрезка

            for (int i = 0; i < size; i++)
            { // Заполняем вектор Y (
                sum =+ Math.Abs(f(X[i])-interpolate1(a, b, n+1, X[i]));
            }

            // 3
            txtDelta.Text = sum.ToString();

        }

        private void btnDraw2_Click(object sender, EventArgs e)
        {
            // 1 Читаем значения полей в соотвествующие переменные:
            double a = 0.0;
            Double.TryParse(txtA.Text, out a);

            double b = 0.0;
            Double.TryParse(txtB.Text, out b);

            int n = 0;
            int.TryParse(txtN.Text, out n);

            // Получим панель для рисования
            GraphPane pane = zedGraphControl1.GraphPane;


            // Очистим список кривых на тот случай, если до этого сигналы уже были нарисованы
            pane.CurveList.Clear();


            // 2 Печатаем узловые точки через вспомогательный метод:
            plotPoints(a, b, n + 1);

            // 3 Печатаем график функции на заданном интервале:
            plotFunction(a, b, n * 100);

            // 4 Печатаем график полинома на заданном интервале:
            plotLagrangeAlt(a, b, n * 100, n + 1);
        }
    }
}
