#include <iostream>

// завдання 2

class Vector { // клас вектор
private:
    long *pointer;
    int size;
    int state;

public:

    Vector() {
        size = 1;
        pointer = new long[size];
        pointer[0] = 0;
        state = 0;
    } // Конструктор, який створює вектор розміром 1 зі значенням за замовчуванням 0.

    Vector(int sz) {
        size = sz;
        pointer = new long[size];
        for (int i = 0; i < size; ++i)
            pointer[i] = 0;
        state = 0;
    } // Конструктор, який створює вектор з заданим розміром та ініціалізує його всі значення 0.

    Vector(int sz, long init_value) {
        size = sz;
        pointer = new long[size];
        for (int i = 0; i < size; ++i)
            pointer[i] = init_value;
        state = 0;
    } // Конструктор, який створює вектор з заданим розміром та ініціалізує його всі значення вказаним значенням.

    Vector(const Vector &other) {
        size = other.size;
        pointer = new long[size];
        for (int i = 0; i < size; ++i)
            pointer[i] = other.pointer[i];
        state = other.state;
    } // Конструктор копіювання, який створює копію вектора, переданого в якості параметра.

    Vector &operator=(const Vector &other) {
        if (this != &other) {
            delete[] pointer;
            size = other.size;
            pointer = new long[size];
            for (int i = 0; i < size; ++i)
                pointer[i] = other.pointer[i];
            state = other.state;
        }
        return *this;
    } // Перевантажений оператор присвоєння, який дозволяє присвоїти один вектор іншому.

    ~Vector() {
        delete[] pointer;
    } // Деструктор, який видаляє пам'ять, виділену для масиву елементів вектора.

    void setElement(int index, long value = 0) {
        if (index >= 0 && index < size) {
            pointer[index] = value;
            state = 0;
        } else {
            state = 2;
        }
    } // Функція для встановлення значення елементу вектора за індексом.

    long getElement(int index) {
        if (index >= 0 && index < size) {
            state = 0;
            return pointer[index];
        } else {
            state = 2;
            return 0;
        }
    } // Функція для отримання значення елементу вектора за індексом.

    void print() {
        for (int i = 0; i < size; ++i)
            std::cout << pointer[i] << " ";
        std::cout << std::endl;
    } // Функція для виведення всіх елементів вектора на екран.

    Vector add(const Vector &other) {
        if (size != other.size) {
            state = 2;
            return *this;
        }
        Vector result(size);
        for (int i = 0; i < size; ++i)
            result.pointer[i] = pointer[i] + other.pointer[i];
        return result;
    } // Функція для додавання двох векторів.

    Vector subtract(const Vector &other) {
        if (size != other.size) {
            state = 2; // Установка стану, що вказує на помилку
            return *this; // // Повертаємо поточний об'єкт
        }
        Vector result(size); // // Створюємо новий об'єкт Vector для віднімання
        for (int i = 0; i < size; ++i)
            result.pointer[i] = pointer[i] - other.pointer[i]; // Віднімаємо відповідні елементи векторів
        return result; // Повертаємо новий вектор, що містить результат віднімання
    }

    Vector multiply(unsigned int scalar) { //  зберігає результату множення на скаляр
        Vector result(size);
        for (int i = 0; i < size; ++i)
            result.pointer[i] = pointer[i] * scalar; // Множимо кожен елемент вектора на скаляр
        return result; // Повертаємо новий вектор, що містить множення на скаляр
    }

    bool lessThan(const Vector &other) {
        if (size != other.size) {
            state = 2;
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (pointer[i] >= other.pointer[i])
                return false;
        }
        return true;
    } // Функція для порівняння векторів за умовою "менше за".


    bool equalTo(const Vector &other) {
        if (size != other.size) {
            state = 2; // Установка стану, що вказує на помилку
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (pointer[i] != other.pointer[i])
                return false; // Повертаємо false, якщо знайдено хоча б одну нерівність елементів
        }
        return true;
    }

    int getState() const {
        return state;
    } // Функція для отримання поточного стану вектора.

    static int getCount() {
        return count;
    } //Статичний метод для кількості створених об'єктів класу Vector.

private:
    static int count;
};

int Vector::count = 0; //для підрахунку кількості створених об'єктів.

int main() { // виклик методу
    Vector v1;
    v1.print();

    Vector v2(5);
    v2.print();

    Vector v3(3, 10);
    v3.print();

    Vector v4 = v3;
    v4.print();
    Vector v5;
    v5 = v2;
    v5.print();

    v5.setElement(2, 7);
    std::cout << "Element at index 2: " << v5.getElement(2) << std::endl;

    Vector v6 = v2.add(v3);
    v6.print();

    Vector v7 = v3.subtract(v2);
    v7.print();

    Vector v8 = v3.multiply(2);
    v8.print();

    std::cout << "State of v8: " << v8.getState() << std::endl;

    Vector v9(4);
    std::cout << "State of v9: " << v9.getState() << std::endl;

    std::cout << "Number of objects created: " << Vector::getCount() << std::endl;

    return 0;
}
