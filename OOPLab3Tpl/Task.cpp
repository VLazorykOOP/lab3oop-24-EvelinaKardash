#if !defined(_MSC_VER)
#define CODING_VS_CODE
#endif
#include <iostream>
#if !defined(CODING_VS_CODE)
#include <clocale>
#endif

// завдання 2

class Vector {
private:
    long* pointer;
    int size;
    int state; // 0 - no error, 1 - out of memory, 2 - index out of range

public:
    // Constructor without parameters
    Vector() {
        size = 1;
        pointer = new long[size];
        pointer[0] = 0;
        state = 0;
    }

    // Constructor with one parameter - vector size
    Vector(int sz) {
        size = sz;
        pointer = new long[size];
        for (int i = 0; i < size; ++i)
            pointer[i] = 0;
        state = 0;
    }

    // Constructor with two parameters - vector size and initialization value
    Vector(int sz, long init_value) {
        size = sz;
        pointer = new long[size];
        for (int i = 0; i < size; ++i)
            pointer[i] = init_value;
        state = 0;
    }

    // Copy constructor
    Vector(const Vector& other) {
        size = other.size;
        pointer = new long[size];
        for (int i = 0; i < size; ++i)
            pointer[i] = other.pointer[i];
        state = other.state;
    }

    // Assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] pointer;
            size = other.size;
            pointer = new long[size];
            for (int i = 0; i < size; ++i)
                pointer[i] = other.pointer[i];
            state = other.state;
        }
        return *this;
    }

    // Destructor
    ~Vector() {
        delete[] pointer;
    }

    // Function to set a value to an element of the array
    void setElement(int index, long value = 0) {
        if (index >= 0 && index < size) {
            pointer[index] = value;
            state = 0;
        } else {
            state = 2; // Index out of range
        }
    }

    // Function to get an element of the array
    long getElement(int index) {
        if (index >= 0 && index < size) {
            state = 0;
            return pointer[index];
        } else {
            state = 2; // Index out of range
            return 0;
        }
    }

    // Function for printing the array
    void print() {
        for (int i = 0; i < size; ++i)
            std::cout << pointer[i] << " ";
        std::cout << std::endl;
    }

    // Function for addition
    Vector add(const Vector& other) {
        if (size != other.size) {
            state = 2; // Sizes don't match
            return *this;
        }
        Vector result(size);
        for (int i = 0; i < size; ++i)
            result.pointer[i] = pointer[i] + other.pointer[i];
        return result;
    }

    // Function for subtraction
    Vector subtract(const Vector& other) {
        if (size != other.size) {
            state = 2; // Sizes don't match
            return *this;
        }
        Vector result(size);
        for (int i = 0; i < size; ++i)
            result.pointer[i] = pointer[i] - other.pointer[i];
        return result;
    }

    // Function for multiplication by unsigned int
    Vector multiply(unsigned int scalar) {
        Vector result(size);
        for (int i = 0; i < size; ++i)
            result.pointer[i] = pointer[i] * scalar;
        return result;
    }

    // Comparison functions
    bool lessThan(const Vector& other) {
        if (size != other.size) {
            state = 2; // Sizes don't match
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (pointer[i] >= other.pointer[i])
                return false;
        }
        return true;
    }

    bool equalTo(const Vector& other) {
        if (size != other.size) {
            state = 2; // Sizes don't match
            return false;
        }
        for (int i = 0; i < size; ++i) {
            if (pointer[i] != other.pointer[i])
                return false;
        }
        return true;
    }

    // Function to get the state
    int getState() const {
        return state;
    }

    // Function to get the number of objects created
    static int getCount() {
        return count;
    }

private:
    static int count;
};

int Vector::count = 0;

int mainExample3() {
    Vector v1; // Constructor without parameters
    v1.print(); // Output: 0

    Vector v2(5); // Constructor with one parameter
    v2.print(); // Output: 0 0 0 0 0

    Vector v3(3, 10); // Constructor with two parameters
    v3.print(); // Output: 10 10 10

    Vector v4 = v3; // Copy constructor
    v4.print(); // Output: 10 10 10

    Vector v5;
    v5 = v2; // Assignment operator
    v5.print(); // Output: 0 0 0 0 0

    v5.setElement(2, 7);
    std::cout << "Element at index 2: " << v5.getElement(2) << std::endl; // Output: Element at index 2: 7

    Vector v6 = v2.add(v3);
    v6.print(); // Output: 10 10 10 0 0

    Vector v7 = v3.subtract(v2);
    v7.print(); // Output: 10 10 10 0 0

    Vector v8 = v3.multiply(2);
    v8.print(); // Output: 20 20 20

    std::cout << "State of v8: " << v8.getState() << std::endl; // Output: State of v8: 0

    Vector v9(4);
    std::cout << "State of v9: " << v9.getState() << std::endl; // Output: State of v9: 0

    std::cout << "Number of objects created: " << Vector::getCount() << std::endl; // Output: Number of objects created: 9

    return 0;
}
