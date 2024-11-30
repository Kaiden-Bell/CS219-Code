Author: Kaiden Bell
Date: 11/29/24
Ver: 3.0

Purpose:

This program simulates a basic machine-level instruction set. Performs both arithmetic and bitwsie operations on
all hexadecimal using a virtual register set (R0-R7). The instructions are read from an input file and executed one after
another with results outputted to the console.

The program is designed to highlight functionality of a low-level programming language, used to 
examine how flags (N, Z, C, V) are updated during computation.

File Stucture and Functionality:

1. Operators.h/Operators.cpp
    Purpose: Encapsulates arithmetic and bitwise operations

- Operators()
    Initinalizes all regs to zero, sets default state of flags
- Operators(uint32_t, uint32_t)
    Parameterized constructor to intialize the vals of num1 and num2.
- Operators(const Operator& rhs)
    Copy constructor for deep copying state of an Operator object.

Getters/Setters

- getNum1(), getNum2()
    Used to get the values of num1, and num2

- setNum1(), setNum2()
    Used to assign vals to num1, and num2

- All flag getters
    Used to retrive the current value of a flag (1, or a 0)

Operations
- add()
    add together two hex numbers, return val, update flags
- sub()
    subtract two hex numbers, return val, update flags
- _and, orr, xor
    perform common bitwise functions and, or and xor on the nums, return vals, and update flags if req
- lsr, lsl, asr
    perform common bitshifts, return vals, update flags if req
- cmp
    perform subtraction without saving val to a register, but update flags
- tst
    perform AND without saving val to a register, but update flags
- void updateFlags
    updates the N, Z flags based off res
- void updateFlagsSub(uint32_t, uint32_t, uint32_t)
    updates C, and V flags in addition to N and Z for subtraction ops

2. Main.cpp
    Purpose: Parses togeter, and executes instructions from input files

    Main functions:
    -   string trim:
            Removes whitespace (mostly) from the string
    - toLowerCase and toUpperCase
        convert a string, either upper/lower
    - isInstruction
        determines if a line is a vaild operation

SUPPORTED INSTRUCTIONS
MOV: Moves either an I-type or R-type val into a dest reg
ADD/SUB: Adds or subtracts a I-type, or R-type val to and from a register
AND,ORR,XOR: Performs bitwsie ops
LSL,LSR,ASR: Performs logical and arthimetic shifts
CMP,TST: Compares or tests vals without updating to a reg


Compilation Instructions

call ./output <insert text file>

for example ./output Programming-Project-3.txt

Program only accepts correct input format, or else it wont work




