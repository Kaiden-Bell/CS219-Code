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
        int n_Flag = 0;
        int z_Flag = 0;
    public:
        Operators();
        Operators(uint32_t, uint32_t);
        Operators(const Operators& rhs);

        // Getters & Setters
        uint32_t getNum1() const;
        uint32_t getNum2() const;


        int getNFlag() const;
        int getZFlag() const;

        void setNum1(uint32_t);
        void setNum2(uint32_t);


        uint32_t add();
        uint32_t cmd();
        uint32_t _and();

        
        pair<int32_t, int32_t> asr();
        pair<uint32_t, uint32_t> lsr();
        pair<uint32_t, uint32_t> lsl();
        pair<uint32_t, uint32_t> _not();


        uint32_t orr();
        uint32_t sub();
        uint32_t _xor();


        void updateFlags(uint32_t res);



        bool checkOverflow(uint32_t res);
};
#endif