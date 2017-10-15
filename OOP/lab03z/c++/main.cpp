#include <iostream>
#include <string>
#include <cmath>
#include <clocale>

using namespace std;

// Класс Студент (класс-родитель)
class Student {
protected:
    // ФИО
    string firstname;
    string lastname;
    string surname;

    string faculty; // Факультет
    int course; // Курс
    int minrating; // Минимальная оценка по экзаменам за последнюю сессию (от 2 до 5)

public:
    // Конструктор по умолчанию, устанавливает нулевой радиус
    Student() {
        firstname = lastname = surname = "неизвестно";
        faculty = "неизвестно";
        course = 1;
        minrating = 2;
    }

    // Конструктор с параметрами
    Student(string fName, string lName, string sName, string fac, int cou, int mRating) {
        firstname = fName;
        lastname = lName;
        surname = sName;
        faculty = fac;
        course = (cou > 0 ? ((cou < 6) ? cou : 5) : 1); // Чтобы в диапазон 1-5 курса попасть
        minrating = (mRating > 1 ? ((mRating < 6) ? mRating : 5) : 2); // Чтобы в диапазон оценок 2-5 попасть
    }

    // Виртуальный метод "Перевести на следующий курс"
    virtual void ToNextCourse() {
        if ((minrating > 2) & (course < 5)) { // Если минимальная оценка не менее 3 и курс еще не пятый (иначе переводить уже некуда)
            // то переводим на след курс
            course++;
        } // иначе ничего
    }

    // Виртуальный метод "Стипендия", возвращающий стипендию (в грн)
    virtual double GetGrant() {
        switch (minrating)
        {
            case 4:
                return 200.0;
            case 5:
                return 300.0;
            default:
                return 0.0;
        }
    }

    // Метод получения информации о Студенте
    string GetInfo() {
        string info = firstname + " " + lastname + " " + surname + "\n";
        info += "факультет \"" + faculty + ", " + to_string(course) + " курс, \n";
        info += "минимальная оценка по экзаменам: " + to_string(minrating) + "\n";
        info += "стипендия: " + to_string(GetGrant()) + "\n";
        return info;
    }

};



// Класс Студент-контрактник (класс-наследник)
class ContrStudent : public Student {
protected:
    bool isPaid; // дополнительный логический параметр - уплачен ли контракт

public:
    // Конструктор по умолчанию, устанавливает уплаченное значение контракта
    ContrStudent() {
        isPaid = true;
    }

    // Конструктор с параметрами
    ContrStudent(string fName, string lName, string sName, string fac, int cou, int mRating, bool iPaid) : Student(fName, lName, sName, fac, cou, mRating) {
        isPaid = iPaid;
    }

    // Переопределяем метод "Перевести на следующий курс"
    void ToNextCourse() {
        if ((minrating > 2) & (course < 5) & (isPaid) ) { // Если минимальная оценка не менее 3 и курс еще не пятый (иначе переводить уже некуда), и за контракт уплачено
            // то переводим на след курс
            course++;
        } // иначе ничего
    }


    // Переопределяем метод "Стипендия", возвращающий всегда 0 грн
    double GetGrant() {
        return 0.0;
    }

};



int main()
{

    setlocale(LC_ALL, "Russian");

    // SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    // SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    /*
    std::cout << "Введите ФИО первого студента:\n";
    string fName, lName, sName;
    std::cin >> fName >> lName >> sName;
    */

    // Создаем обычного среднестатистического третьекурсника-хорошиста:
    Student ivan("Иван", "Иванович", "Иванов", "ПММ", 3, 4);
    // И создаем двух студентов-контрактников третьего курса:
    ContrStudent petr("Петр", "Петрович", "Петров", "ПММ", 3, 5, 1); // уплатил за контракт, последний параметр 1
    ContrStudent sidor("Сидор", "Сидорович", "Сидоров", "ФКН", 3, 4, 0); // не уплатил за контракт, последний параметр 0

    // Выводим информацию о студентах:
    std::cout << ivan.GetInfo() << "\n";
    std::cout << petr.GetInfo() << "\n";
    std::cout << sidor.GetInfo() << "\n";

    // Применяем к ним метод "Перевести на следующий курс":
    std::cout << "\nПытаемся перевести всех студентов на следующий курс!" << "\n\n";
    ivan.ToNextCourse();
    petr.ToNextCourse();
    sidor.ToNextCourse();

    // И снова выводим информацию о студентах:
    std::cout << ivan.GetInfo() << "\n";
    std::cout << petr.GetInfo() << "\n";
    std::cout << sidor.GetInfo() << "\n";

    // system("pause"); // Команда задержки экрана, только для Windows

    return 0;
}