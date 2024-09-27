// Author: Kaiden Bell
// Date: 9/27/24
// Ver: 1.0

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
        Operators(const Operators& rhs);

        // Getters & Setters
        uint32_t getNum1() const;
        uint32_t getNum2() const;
        void setNum1(uint32_t);
        void setNum2(uint32_t);

        uint32_t add();

        bool checkOverflow(uint32_t res);
};
#endif