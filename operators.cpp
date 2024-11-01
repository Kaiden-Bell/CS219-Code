// Author: Kaiden Bell
// Date: 9/31/24
// Ver: 1.0

#include "operators.h"

Operators::Operators() : num1(0), num2(0), n_Flag(0), z_Flag(0) {}


Operators::Operators(uint32_t a, uint32_t b) : num1(a), num2(b), n_Flag(0), z_Flag(0) {}

Operators::Operators(const Operators& rhs) : num1(rhs.num1), num2(rhs.num2), n_Flag(rhs.n_Flag), z_Flag(rhs.z_Flag) {}

uint32_t Operators::getNum1() const {
    return num1;    
}

uint32_t Operators::getNum2() const {
    return num2;
}


int Operators::getNFlag() const { 
    return n_Flag; 
}


int Operators::getZFlag() const { 
    return z_Flag; 
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

uint32_t Operators::_and(){
    return num1 & num2;    
}

pair<int32_t, int32_t> Operators::asr(){
    return {static_cast<int32_t>(num1) >> 1, static_cast<int32_t>(num2) >> 1};
}

pair<uint32_t, uint32_t> Operators::lsr(){
    return {num1 >> 1, num2 >> 1};
}

pair<uint32_t, uint32_t> Operators::lsl(){
    return {num1 << 1, num2 << 1};
}

pair<uint32_t, uint32_t> Operators::_not(){
    return {~num1, ~num2};
}

uint32_t Operators::orr(){
    return num1 | num2;
}

uint32_t Operators::sub(){
    return num1 - num2;
}

uint32_t Operators::_xor(){
    return num1 ^ num2;
}


void Operators::updateFlags(uint32_t res) {
    n_Flag = (res >> 31) & 1; // check if MSB is set, (particuallly to a 1)
    z_Flag = (res == 0) ? 1 : 0; // check if the res is 0
}

bool Operators::checkOverflow(uint32_t res) {
    return res < num1 || res < num2;
}