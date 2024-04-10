#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

class triangle { // клас трикутник
    double a; // сторона
    unsigned int color; // колір
public:
    triangle() : a(1.0), color(0) {} // довжина сторони (a) на одиницю та колір на нуль

    explicit triangle(double ai) : a(ai), color(0) {} // довжина сторони (a) переданим значенням ai та колір на нуль

    explicit triangle(int ic) : a(1.0) { if (ic >= 0) color = ic; else color = 0; } // значення ic, але якщо ic менше за нуль

    triangle(double a, int c, double a1) : a(a1) { // ініціалізує довжину сторони та колір
        this->a = a;
        if (c >= 0) color = c; else color = 0;
    } // Якщо переданий колір менше за нуль, то встановлюється колір на нуль

    double getA() const { return a; } // повертає довжину сторони трикутника

    void setA(double a) { // встановлення нової довжини сторони трикутника
        if (a < 0 || a > 1.e+100) {
            cout << " Error set a \n";
            return;
        }
        this->a = a;
    } // Перевіряється чи вказане значення в межах припустимих, в іншому випадку виводиться повідомлення про помилку

    double getColor() const { return color; } //  повертає колір трикутника

    void setColor(int c) { // встановлення нового коліру трикутника
        if (c < 0 || c > 10000) {
            cout << " Error set color \n";
            return;
        }
        this->color = c;
    } // Перевіряється чи вказане значення в межах припустимих, в іншому випадку виводиться повідомлення про помилку

    double S()  { // площа трикутника
        return (a * a * sqrt(3.0)) / 4;
    }

    double P() { // периметр трикутника
        return a * 3;
    }

    void printInfo() {
        cout << "\n a= " << a << " color = " << color;
        cout << " S= " << S() << " P= " << P() << endl;
    }
};

int main() {

    triangle obj; // Створення об'єкту трикутника зі значеннями за замовчуванням
    obj.printInfo();
    double in_a; //Зчитування значень довжини сторони та коліру для створення об'єкту
    int in_color;
    cout << " Input side and color Icosahedron ";
    cin >> in_a >> in_color;
    triangle obj1(in_a), obj2(in_color), obj3(in_a, in_color, 0); // виведення інформації про три об'єкти трикутника
    obj1.printInfo();
    obj2.printInfo();
    obj3.printInfo();
    cout << " End testing \n";
    return 0;
}

// 2 завдання

/*class Vector {
private:
    long *array;  // вказівник на масив
    int size;     // кількість елементів у векторі
    int state;    // змінна стану (0 - успішно, 1 - помилка виходу за межі, 2 - помилка недостатньої пам'яті)
    static int objectCount;  // лічильник об'єктів класу

public:
    // Конструктори
    Vector();  // без параметрів
    Vector(int size);  // з одним параметром - розмір вектора
    Vector(int size, long initValue);  // з двома параметрами - розмір вектора та значення ініціалізації
    Vector(const Vector &other);  // конструктор копій

    // Деструктор
    ~Vector();

    // Оператор присвоєння
    Vector &operator=(const Vector &other);

    // Функції для отримання та встановлення значень елементів масиву
    void setValue(int index, long value = 0);  // параметр за замовчуванням
    long getValue(int index) const;

    // Функція для друку вектора
    void print() const;

    // Арифметичні операції
    Vector operator+(const Vector &other) const;

    Vector operator-(const Vector &other) const;

    Vector operator*(unsigned int scalar) const;

    // Оператори порівняння
    bool operator<(const Vector &other) const;

    bool operator==(const Vector &other) const;

    bool operator!=(const Vector &other) const;

    // Підрахунок кількості об'єктів
    static int getObjectCount();

    // Функція для отримання стану об'єкту
    int getState() const;
};

int Vector::objectCount = 0;

// Реалізація конструкторів
Vector::Vector() : size(1), state(0) {
    array = new long[size];
    array[0] = 0;
    objectCount++;
}

Vector::Vector(int size) : size(size), state(0) {
    array = new long[size];
    for (int i = 0; i < size; ++i)
        array[i] = 0;
    objectCount++;
}

Vector::Vector(int size, long initValue) : size(size), state(0) {
    array = new long[size];
    for (int i = 0; i < size; ++i)
        array[i] = initValue;
    objectCount++;
}

Vector::Vector(const Vector &other) : size(other.size), state(other.state) {
    array = new long[size];
    for (int i = 0; i < size; ++i)
        array[i] = other.array[i];
    objectCount++;
}

// Реалізація деструктора
Vector::~Vector() {
    delete[] array;
    objectCount--;
}

// Реалізація оператора присвоєння
Vector &Vector::operator=(const Vector &other) {
    if (this != &other) {
        delete[] array;
        size = other.size;
        state = other.state;
        array = new long[size];
        for (int i = 0; i < size; ++i)
            array[i] = other.array[i];
    }
    return *this;
}

// Реалізація функції для отримання значення елементу
long Vector::getValue(int index) const {
    if (index >= 0 && index < size) {
        return array[index];
    } else {
        state = 1;
        return 0;
    }
}

// Реалізація функції для встановлення значення елементу
void Vector::setValue(int index, long value) {
    if (index >= 0 && index < size) {
        array[index] = value;
        state = 0;
    } else {
        state = 1;
    }
}

// Реалізація функції друку вектора
void Vector::print() const {
    for (int i = 0; i < size; ++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

// Реалізація арифметичних операцій
Vector Vector::operator+(const Vector &other) const {
    Vector result(size < other.size ? size : other.size);
    for (int i = 0; i < result.size; ++i)
        result.array[i] = array[i] + other.array[i];
    return result;
}

Vector Vector::operator-(const Vector &other) const {
    Vector result(size < other.size ? size : other.size);
    for (int i = 0; i < result.size; ++i)
        result.array[i] = array[i] - other.array[i];
    return result;
}

Vector Vector::operator*(unsigned int scalar) const {
    Vector result(size);
    for (int i = 0; i < size; ++i)
        result.array[i] = array[i] * scalar;
    return result;
}

// Реалізація операторів порівняння
bool Vector::operator<(const Vector &other) const {
    if (size != other.size)
        return false;
    for (int i = 0; i < size; ++i) {
        if (array[i] >= other.array[i])
            return false;
    }
    return true;
}

bool Vector::operator==(const Vector &other) const {
    if (size != other.size)
        return false;
    for (int i = 0; i < size; ++i) {
        if (array[i] != other.array[i])
            return false;
    }
    return true;
}

bool Vector::operator!=(const Vector &other) const {
    return !(*this == other);
}

// Реалізація функції для отримання стану об'єкту
int Vector::getState() const {
    return state;
}

int mainExample3() {
#if !defined(CODING_VS_CODE)
    setlocale(LC_CTYPE, "ukr");
    cout << "Тестування створенного класу \n";
    cout << "Тестування конструкторiв \n";
#else
    cout << "Testing create class  \n";
    cout << "Testing crot's  \n";
#endif
    Vec2 ObjCDef;
    ObjCDef.Output();
    Vec2 ObjP1(10.0);
    ObjP1.Output();
    double a = 1.0, b = 2.0;
    Vec2 ObjP2(a, b);
    ObjP2.Output();
    Vec2 ObjCopy(ObjP2);
    double *v = nullptr, v2[] = {1.2, 3.3};
    Vec2 ObjP3(v2);
    if (ObjP3.getState() != OK) cout << " ObjP3  x= 0  y= 0  \n";
    Vec2 ObjP4(v2);
    if (ObjP4.getState() != OK) cout << " ObjP4 x= 0  y= 0  \n";
#if !defined(CODING_VS_CODE)
    cout << " Кiлькiсть створених об'єктiв Vec2 " << Vec2::getCount() << endl;
    cout << "Тестування введення \n";
    ObjCDef.Input();
    cout << "Тестування функцiй \n";
    ObjCDef = ObjCDef.Add(ObjP2);
    ObjCDef.Output();
    cout << " \n Кiлькiсть створених об'єктiв Vec2 до Sub " << Vec2::getCount() << endl;
    ObjCDef = ObjCDef.Sub(ObjP2);
    cout << " \n Кiлькiсть створених об'єктiв Vec2 пiсля Sub " << Vec2::getCount() << endl;
#else
    cout << "Testing input \n";
    ObjCDef.Input();
    cout << "Testing gunction \n";
    ObjCDef = ObjCDef.Add(ObjP2);
    ObjCDef.Output();
    cout << " \n Counts create objects Vec2 before  Sub " << Vec2::getCount() << endl;
    ObjCDef = ObjCDef.Sub(ObjP2);
    cout << " \n  Counts create objects Vec2 after Sub  " << Vec2::getCount() << endl;
#endif

    ObjCDef.Output();
    ObjCDef = ObjCDef.Mul(5);
    ObjCDef.Output();
    ObjCDef = ObjCDef.Div(1.3);
    if (ObjCDef.getState() == STATE::BAD_DIV) cout << "BAD_DIV \n";
    ObjCDef.Output();

    ObjCDef = ObjCDef.Div(0.0);
    if (ObjCDef.getState() == STATE::BAD_DIV) cout << "BAD_DIV \n";
    ObjCDef.Output();
    cout << "ObjCopy state " << ObjCopy.getState() << endl;
    if (ObjCopy.CompLessAll(ObjCDef)) cout << "ObjCopy less ObjDef  " << endl;


#if !defined(CODING_VS_CODE)
    cout << "Завершення  тестування  \n";
#else
    cout << "Completion of testing  \n";
#endif
    return 1;

}*/