#include <iostream>
#include <string>
#include <cmath>

using namespace std;


// Класс Животное (класс-родитель)
class Animal {
protected:
    string Name; // имя
    double Age; // возраст
    bool Sex; // пол, если 1 - мужик!)

    Animal * Next; // указатель на следующее животное


public:
    // Конструктор по умолчанию, устанавливает нулевой радиус
    Animal() {
        Name = "noName";
        Age = 0.0;
        Sex = true;
    }

    // Конструктор с параметрами
    Animal(string name, double age=0.0, bool sex=true) {
        Name = name;
        Age = age;
        Sex = sex;
    }

    const string getName(){
        return Name;
    }

    void setName(string name) {
        Name = name;
    }

    double getAge(){
        return Age;
    }

    void setAge(double age) {
        Age = age;
    }

    bool getSex(){
        return Sex;
    }

    void setSex(bool sex) {
        Sex = sex;
    }

    Animal *getNext(){
        return Next;
    }

    void setNext(Animal *link) {
        Next = link;
    }


    // Виртуальный метод получения информации о животном - конвертация в строку
    virtual string toString() {
        return "Животное: имя " + Name + ", возраст " + to_string(Age) + ", пол " + (Sex ? "м" : "ж");
    }

};


// Класс Тигр (класс-наследник)
class Tiger : public Animal {
protected:
    int LineCount; // количество полос)

public:
    // Конструктор по умолчанию, устанавливает нулевые радиусы
    Tiger() {
        LineCount = 100;
        Name = "Тигр";
    }

    // Конструктор с параметрами
    Tiger(string name, double age=0.0, bool sex=true, int linecount=100 ) : Animal(name, age, sex) {
        LineCount = linecount;
    }

    int getLineCount(){
        return LineCount;
    }

    void setLineCount(int lineCount) {
        LineCount = lineCount;
    }

    // Метод получения информации о тигре - конвертация в строку
    string toString() {
        return "Тигр: имя " + Name + ", возраст " + to_string(Age) + ", пол " + (Sex ? "м" : "ж") + ", количество полос " + to_string(LineCount);
    }

};

// Класс Лев (класс-наследник)
class Lion : public Animal {
protected:
    double ManeVolume; // объем гривы

public:
    // Конструктор по умолчанию, устанавливает нулевые радиусы
    Lion() {
        ManeVolume = 0.0;
        Name = "Лев";
    }

    // Конструктор с параметрами
    Lion(string name, double age=0.0, bool sex=true, int manevolume=0.0 ) : Animal(name, age, sex) {
        ManeVolume = manevolume;
    }

    double getManeVolume(){
        return ManeVolume;
    }

    void setManeVolume(double maneVolume) {
        ManeVolume = maneVolume;
    }

    // Метод получения информации о тигре - конвертация в строку
    string toString() {
        return "Лев: имя " + Name + ", возраст " + to_string(Age) + ", пол " + (Sex ? "м" : "ж") + ", объем гривы " + to_string(ManeVolume);
    }

};

// Класс Список животных
class AnimalList {
protected:
    Animal *head; // Корневой элемент


public:
    // Конструктор по умолчанию, устанавливает нулевой радиус
    AnimalList() {
        head = new Animal("Root"); // Корневой элемент
    }

    // Функция обхода всего списка и печати
    void print(){
        Animal *root = head;
        while ((*root).getNext() != NULL){
            root = (*root).getNext();
            cout << (*root).toString() << endl;
        }
    }

    // Функция обхода всего списка и печати только животных старше 5 лет
    void printOld(){
        Animal *root = head;
        while ((*root).getNext() != NULL){
            root = (*root).getNext();
            if ((*root).getAge() > 5.0){
                cout << (*root).toString() << endl;
            }
        }
    }

    // Функция удаления животных старше 5 лет
    void deleteOld(){
        cout << "Выполнется попытка удаления животных старше 5 лет..." << endl;
        Animal *root = head;
        while ((*root).getNext() != NULL){
            root = (*root).getNext();
            if ((*root).getAge() > 5.0){
                del((*root).getName());
            }
        }
        cout << "Выполнено" << endl;
    }

    // Функция добавления нового животного в список
    void add(Animal * animal){

        // 1 Если есть только один корневой элемент
        if ((*head).getNext() == NULL){
            (*head).setNext(animal);
            return;
        }

        // 2 иначе вставляем в конец
        Animal *root = head;
        while ((*root).getNext() != NULL){
            // Иначе движемся дальше
            root = (*root).getNext();
        }
        (*root).setNext(animal);
    }

    // Функция удаления животного из списка
    void del(string name){
        cout << "Выполнется попытка удаления записи для " << name << "..." << endl;
        Animal *root = head;
        while ((*root).getNext() != NULL){
            Animal * next = (*root).getNext();
            if ( (*next).getName() == name )  { // нашли!
                // нашли место удаления!
                (*root).setNext((*next).getNext());
                cout << "Запись удалена!" << endl;
                return;
            }
            // Иначе движемся дальше
            root = (*root).getNext();
        }
        cout << "Запись для удаления не найдена!" << endl;
    }



};



int main() {

    AnimalList *list = new AnimalList();


    Animal *a1 = new Animal("Животное 1", 6, true);
    Animal *a2 = new Animal("Животное 2", 4, false);
    Animal *a3 = new Tiger("Кусачий", 7, true, 250);
    Animal *a4 = new Lion("Беззубый", 4, true, 12.5);

    list->add(a1);
    list->add(a2);
    list->add(a3);
    list->add(a4);


    list->print();

    // list->del("Кусачий");
    list->deleteOld(); // Удаляем всех старых животных
    list->print();




    return 0;
}