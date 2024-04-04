#include <math.h>
#endif
#if !defined(_MSC_VER)
#include <clocale>
#endif

using namespace std;

class triangle { // клас трикутник
    double a; // сторона
    unsigned int color; // колір
public:
    triangle() : a(1.0), color(0) {} // довжина сторони (a) на одиницю та колір на нуль

    triangle(double ai) : a(ai), color(0) {} // довжина сторони (a) переданим значенням ai та колір на нуль

    triangle(int ic) : a(1.0) { if (ic >= 0) color = ic; else color = 0; } // значення ic, але якщо ic менше за нуль

    triangle(double a, int c) { // ініціалізує довжину сторони та колір
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

    double S() { // площа трикутника
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
    triangle obj1(in_a), obj2(in_color), obj3(in_a, in_color); // виведення інформації про три об'єкти трикутника
    obj1.printInfo();
    obj2.printInfo();
    obj3.printInfo();
    cout << " End testing \n";
    return 0;
}
