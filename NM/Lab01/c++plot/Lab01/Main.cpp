#include <glut.h> // Подключаем заголовочный файл для работы с OpenGL
// Как настроить Visual Studio - вот тут хороший мануал:
// https://www.youtube.com/watch?v=bIcT61FdG-Y

#include <windows.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

/*
Задание:

Написать программу, исходные данные: дан отрезок [a, b] - вводим с клавиатеры,
и функция, по которой будем считать значения в узлах. Используем многочлен n-ой степени (n+1 узлов),
и они равноотстощие на отрезке [a, b]. С помощью двойного цикла запрограммировать вычисление
многочлена Лагранжа и сравнить графики функции и полинома.

*/

// Глобальные константы и переменные:

const int X_COORD = 6;// X - размерность ] должны
const int Y_COORD = 6;// Y - размерность ] быть равными
const float ITERATIONS = 0.00005;// прорисовка графика (чем меньше тем лучше)

int x_off = X_COORD / 2;// начало
int y_off = Y_COORD / 2;// оси координат

double a = 0.0; // Начало отрезка (меняется в main!!!)
double b = 3.0; // Конец отрезка (меняется в main!!!)
int n = 2; // Степень полинома (меняется в main!!!)





// Функция, которую интерполирует многочлен (можно написать любую)
double f(double x) {
	double y = (1-x)/(1+x*x); // Можно написать другую
	return y;
}

// Функция вычисления ошибки:
double delta(double y1, double y2) {
	return abs(y1 - y2);
}

// Основная функция интерполяции (объявление)
double interpolate2(vector<double> X, vector<double> Y, double xx);

// Вспомогательная функция интерполяции (+ расчет весторов X и Y) (объявление)
double interpolate1(double a, double b, int size, double xx);


// Функция печати осей и сетки на плоскости графика
void drawgrid(float SERIF_OFFSET, float SERIF_DISTANCE) {
	glBegin(GL_LINES);
	//задаем цвета
	glColor3f(0.0, 0.0, 0.0);

	//рисуем координатные оси
	//горизонталь
	glVertex2f(0.0, Y_COORD / 2);
	glVertex2f(X_COORD, Y_COORD / 2);
	//засечки по горизонтали
	int p = X_COORD / 2;
	for (int i = X_COORD / 2; i < X_COORD; i += SERIF_DISTANCE, p -= SERIF_DISTANCE) {
		glVertex2f(i, Y_COORD / 2);
		glVertex2f(i, Y_COORD / 2 + SERIF_OFFSET);

		glVertex2f(p, Y_COORD / 2);
		glVertex2f(p, Y_COORD / 2 + SERIF_OFFSET);
	}
	//вертикаль
	int t = Y_COORD / 2;
	glVertex2f(X_COORD / 2, Y_COORD);
	glVertex2f(X_COORD / 2, 0.0);
	//засечки по вертикали
	for (int i = Y_COORD / 2; i < Y_COORD; i += SERIF_DISTANCE, t -= SERIF_DISTANCE) {
		glVertex2f(X_COORD / 2, i);
		glVertex2f(Y_COORD / 2 + SERIF_OFFSET, i);

		glVertex2f(X_COORD / 2, t);
		glVertex2f(Y_COORD / 2 + SERIF_OFFSET, t);
	}
	glEnd();
}

// Функция рисования графика функции (исходной)
void drawFunc() {
	//рисуем график функции
	glBegin(GL_POINTS);
	double y = 0.0;
	glColor3f(0.8, 0.0, 0.8);
	for (double x = a; x < b; x += 0.001) {
		//перерасчитываем координаты
		y = f(x);
		glVertex2d(x_off + x, y_off + y); //не убирать x_off и y_off!! это смещение по осям!
	}
	glEnd();
}

// Функция графика многочлена Лагранжа
void drawLagrange() {
	//рисуем график полинома
	glBegin(GL_POINTS);
	double j = 0;
	glColor3f(0.8, 0.8, 0.8);
	for (double x = a; x < b; x += 0.001) {
		//перерасчитываем координаты
		j = interpolate1(a, b, n + 1, x);
		glVertex2d(x_off + x, y_off + j); //не убирать x_off и y_off!! это смещение по осям!
	}
	glEnd();
}

// Функция отрисовки всех графиков и осей
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawgrid(0.3, 5);
	drawFunc();
	drawLagrange();
	glutSwapBuffers();
	glFlush();
}

// Основная программа
int main(int argc, char **argv) {
	setlocale(LC_ALL, "rus");

	std::cout << "Интерполяция многочленом Лагранжа" << std::endl;


	// известен интервал и функция, выполняем разбиение для многочлена степени n (на n+1 узлов):
	n = 10; // Многочлен степени 10 = число узлов 10+1
	a = -4.0;
	b = 3.0; // Интервал


	glutInit(&argc, argv); // инициализируем glut
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // используем 1 буфер и цвет типа RGB (3 составляющие)
	glutInitWindowSize(800, 640); // задаем размер окна
	glutInitWindowPosition(0, 0);  // и позицию открытия окна (смещение от верхнего левого края монитора)
	glutCreateWindow("Полиномиальная интерполяция"); // создаем окно с именем "Полиномиальная интерполяция"
	glClearColor(1.0, 1.0, 1.0, 1.0); // задаем цвет фона окна - белый
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//Задаем пространство координат:
	glOrtho(0.0, X_COORD, 0.0, Y_COORD, -1.0, 1.0); // задаем размеры координатной сетки
	glutDisplayFunc(display); // задаем функцию отображающую необходимые объекты
	glutMainLoop();  // И в конце всего передаем управление в glut
}


// Основная функция интерполяции
double interpolate2(vector<double> X, vector<double> Y, double xx) {
	double sum = 0.0; // Сумма-накопитель
	for (int i = 0; i < X.size(); i++) {
		double pp = Y[i];
		for (int j = 0; j < X.size(); j++) {
			if (i != j) {
				pp *= (xx - X[j]) / (X[i] - X[j]);
			}
		}
		sum += pp;
	}
	return sum;
}

// Вспомогательная функция интерполяции (+ расчет весторов X и Y)
double interpolate1(double a, double b, int size, double xx) {
	// Передаем в функцию границы отрезка a и b, число разбиений (узлов) этого отрезка size
	// и значение xx, для которого ищем y, а также функция f, для которой это все ищется
	vector<double> X(size); // Формируем вектор X (пустой)
	vector<double> Y(size); // Формируем вектор Y (пустой)
	double delta = abs(a - b) / (size - 1); // Находим интервал разбиения
	X[0] = a; X[size - 1] = b; // Начао и конец отрезка

	for (int i = 1; i < size - 1; i++) { // Заполняем вектор X
		X[i] = X[i - 1] + delta;
	}

	for (int i = 0; i < size; i++) { // Заполняем вектор Y
		Y[i] = f(X[i]);
	}

	// И вызываем основную функцию
	return interpolate2(X, Y, xx);
}
