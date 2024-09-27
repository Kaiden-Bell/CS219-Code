// Author: Kaiden Bell
// Date: 9/27/24
// Ver: 1.0

#include "operators.h"

Operators::Operators() {
    num1 = 0;
    num2 = 0;
}

Operators::Operators(uint32_t a, uint32_t b) {
    num1 = a;
    num2 = b;
}

Operators::Operators(const Operators& rhs) {
    num1 = rhs.num1;
    num2 = rhs.num2;
}

uint32_t Operators::getNum1() const {
    return num1;    
}

uint32_t Operators::getNum2() const {
    return num2;
}

void Operators::setNum1(uint32_t a) {
    num1 = a;
}

void Operators::setNum2(uint32_t b) {
    num2 = b;
}

uint32_t Operators::add() {
    return num1 + num2;
}

bool Operators::checkOverflow(uint32_t res) {
    return res < num1 || res < num2;
}