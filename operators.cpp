// Author: Kaiden Bell
// Date: 11/29/24
// Ver: 3.0

#include "operators.h"

// Constructors
Operators::Operators() : num1(0), num2(0), n_Flag(0), z_Flag(0) {
    fill(begin(registers), end(registers), 0);
}

Operators::Operators(uint32_t a, uint32_t b) : num1(a), num2(b), n_Flag(0), z_Flag(0), c_Flag(0), v_Flag(0) {}

Operators::Operators(const Operators& rhs) : num1(rhs.num1), num2(rhs.num2), n_Flag(rhs.n_Flag), z_Flag(rhs.z_Flag), c_Flag(rhs.c_Flag), v_Flag(rhs.v_Flag) {}

// Getters 

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

int Operators::getCFlag() const { 
    return c_Flag; 
}

int Operators::getVFlag() const { 
    return v_Flag; 
}

// Setters

void Operators::setNum1(uint32_t a) { 
    num1 = a; 
}

void Operators::setNum2(uint32_t b) { 
    num2 = b; 
}

// Operations

uint32_t Operators::add() {
    uint32_t res = num1 + num2;
    updateFlags(res);
    c_Flag = (res < num1);
    v_Flag = (((num1 ^ num2) & 0x80000000) == 0) && ((res ^ num1) & 0x80000000);
    return res;
}

uint32_t Operators::_and() {
    uint32_t res = num1 & num2;
    updateFlags(res);
    return res;
}


pair<int32_t, int32_t> Operators::asr() {
    return {static_cast<int32_t>(num1) >> 1, static_cast<int32_t>(num2) >> 1};
}

pair<uint32_t, uint32_t> Operators::lsr() {
    uint32_t res1 = num1 >> 1;
    uint32_t res2 = num2 >> 1;
    updateFlags(res1);
    return {res1, res2};
}

pair<uint32_t, uint32_t> Operators::lsl() {
    uint32_t res1 = num1 << 1;
    uint32_t res2 = num2 << 1;
    updateFlags(res1);
    return {res1, res2};
}

pair<uint32_t, uint32_t> Operators::_not(){
    return {~num1, ~num2};
}

uint32_t Operators::orr() {
    uint32_t res = num1 | num2;
    updateFlags(res);
    return res;
}
uint32_t Operators::sub(){
    uint32_t res = num1 - num2;
    updateFlagsSub(res, num1, num2);
    return res;
}

uint32_t Operators::_xor() {
    uint32_t res = num1 ^ num2;
    updateFlags(res);
    return res;
}

void Operators::updateFlags(uint32_t res) {
    n_Flag = (res >> 31) & 1; // check if MSB is set, (particuallly to a 1)
    z_Flag = (res == 0) ? 1 : 0; // check if the res is 0
}

void Operators::updateFlagsSub(uint32_t res, uint32_t op1, uint32_t op2) {
    updateFlags(res);
    c_Flag = (op1 >= op2) ? 0 : 1; // Set carry if borrow occurs
    v_Flag = ((op1 ^ op2) & 0x80000000) && ((op1 ^ res) & 0x80000000); // Overflow flag
}

void Operators::cmp(uint32_t reg1, uint32_t reg2) {
    uint32_t res = reg1 - reg2;
    updateFlagsSub(res, reg1, reg2);
}

void Operators::tst(uint32_t reg1, uint32_t reg2) {
    uint32_t res = reg1 & reg2;
    updateFlags(res);
}

bool Operators::checkOverflow(uint32_t res) {
    return res < num1 || res < num2;
}