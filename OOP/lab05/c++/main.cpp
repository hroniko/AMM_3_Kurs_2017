#include <iostream>
#include <string>
#include <cmath>
#include <vector>

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
        Sex = 1;
    }

    // Конструктор с параметрами
    Animal(string name, double age=0.0, bool sex=1) {
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
    Tiger(string name, double age=0.0, bool sex=1, int linecount=100 ) : Animal(name, age, sex) {
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
        Animal *root = head;
        while ((*root).getNext() != NULL){
            root = (*root).getNext();
            if ((*root).getAge() > 5.0){
                del((*root).getName());
            }
        }
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
   // std::cout << "Hello, World!" << std::endl;

/*

    // Создание вектора, содержащего целые числа
    std::vector<Animal> v;

    // Добавление ещё двух целых чисел в вектор
    Animal *a1 = new Animal("Животное 1");
    Animal *a2 = new Animal("Животное 2");
    Animal *a3 = new Tiger("Кусучий");

    v.push_back(*a1);
    v.push_back(*a2);
    v.push_back(*a3);




    // Проход по вектору с выводом значений
    for ( Animal animal : v ) {
        std::cout << animal.toString() << '\n';
    }


    std::cout << (*a3).toString() << std::endl;
    std::cout << v.back().toString() << std::endl;




    a1->setNext(a2);
    a2->setNext(a3);

    while ((*a1).getNext() != NULL){
        a1 = (*a1).getNext();
        cout << (*a1).toString() << endl;
    }

*/
    AnimalList *list = new AnimalList();


    Animal *a1 = new Animal("Животное 1", 6, true);
    Animal *a2 = new Animal("Животное 2", 4, false);
    Animal *a3 = new Tiger("Кусачий", 3, true, 250);

    list->add(a1);
    list->add(a2);
    list->add(a3);


    list->print();

    // list->del("Кусачий");
    list->deleteOld(); // Удаляем всех старых животных
    list->print();




    return 0;
}