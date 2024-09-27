#ifndef OPERATORS_H
#define OPERATORS_H


#include <iostream>
#include <iomanip>
#include <cstdint>

using namespace std;

class Operators {
    private:
        uint32_t num1, num2;
    public:
        Operators();
        Operators(uint32_t, uint32_t);
        Operator(const Operator& rhs);

        // Getters & Setters
        uint32_t getNum1();
        uint32_t getNum2();
        void setNum1(uint32_t);
        void setNum2(uint32_t);

        uint32_t add();

        bool checkOverflow(uint32_t a, uint32_t b, uint32_t res);
}
#endif