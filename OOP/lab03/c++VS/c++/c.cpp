// c.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>

// #include <Windows.h>
// #include <clocale>

using namespace std;

# define M_PI 3.14159265358979323846  // Число Пи



// Класс Дата (класс-родитель)
class Circle {
protected:
	double r; // Радиус круга

public:
	// Конструктор по умолчанию, устанавливает нулевой радиус
	Circle() {
		r = 0.0;
	}

	// Конструктор с параметрами
	Circle(double R) {
		// Нужно проверить, корректен ли радиус? Лучше взять по модулю.
		r = abs(R);
	}

	// Виртуальный метод вычисления площади круга
	virtual double Area() {
		return M_PI * r * r;
	}

	// Виртуальный метод увеличения площади круга
	virtual void Zoom(double x) {
		r *= abs(x);
	}

	// Метод получения информации о Круге - конвертация в строку
	virtual string toString() {
		return "круг: r = " + to_string(r) + ", S = " + to_string(Area());
	}

};



// Класс Кольцо (класс-наследник)
class Ring : public Circle {
protected:
	double r_in; // Внутренний радиус кольца 

public:
	// Конструктор по умолчанию, устанавливает нулевые радиусы
	Ring() {
		r_in = 0.0;
	}

	// Конструктор с параметрами
	Ring(double R_in, double R_out) : Circle((R_in > R_out) ? R_in : R_out) {
		// Меньший радиус - это внутренний
		r_in = abs((R_in < R_out) ? R_in : R_out);
	}

	// Переопределяем метод вычисления площади (кольца)
	double Area() {
		return M_PI * (r * r - r_in * r_in);
	}

	// Переопределяем метод увеличения площади кольца
	void Zoom(double x) {
		r *= abs(x);
		r_in *= abs(x);
	}

	// Метод получения информации о Кольце - конвертация в строку
	string toString() {
		return "кольцо: r = " + to_string(r_in) + ", R = " + to_string(r) +  ", S = " + to_string(Area());
	}

};



int main()
{
	//setlocale(LC_ALL, "");

	//setlocale(LC_CTYPE, "rus"); // вызов функции настройки локали

	setlocale(LC_ALL, "Russian");

	// SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	// SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    std::cout << "Введите радиус круга:\n";
    double rc;
    std::cin >> rc;

    std::cout << "Введите внутренний и внешний радиус кольца через пробел:\n";
    double rr1, rr2;
    std::cin >> rr1 >> rr2;


    Circle *myCircle = new Circle(rc); // Circle myCircle(rc);
    Circle *myRing = new Ring(rr1, rr2); // Ring myRing(rr1, rr2);

    std::cout << (*myCircle).toString() << "\n";
    std::cout << (*myRing).toString() << "\n";

    std::cout << "Введите, во сколько раз увеличить круг:\n";
    double x;
    std::cin >> x;

    (*myCircle).Zoom(x);


    std::cout << "Введите, во сколько раз увеличить кольцо:\n";
    std::cin >> x;

    (*myRing).Zoom(x);

    std::cout << (*myCircle).toString() << "\n";
    std::cout << (*myRing).toString() << "\n";

	system("pause"); // Команда задержки экрана

    return 0;
}

