Author: Kaiden Bell
Date: 9/27/24
Ver: 1.0

Purpose:

This program was built to demonstrate the functionality of machine language by implementing the ability to add two hexadecimal numbers, and determine if overflow exists between them. The program
reads from a text file. Then performs the operation listed in the file (In this case only addition), then shall output to the screen.

File Stucture and Functionality:

Operators.h/Operators.cpp:
- Operators();
- Operators(uint32_t, uint32_t);
- Operators(const Operators& rhs);
Default, Parameterized, and Copy contrustors, used to assign num1, and num2 as either
specific or arbuitary values.

Getters/Setters:
Used to return the first/second numbers, or set a value to the first and second number.

Operators:
- uint32_t add();
Will take two numbers, most preferably, the number on the left, and then add it directly to the number on the right, uses hex libraries to do this directly, then returns a result.

-bool checkOverflow(uint32_t res);
Will take the result from the addition, and will evaluate to true or false wheter or not overflow occured (overflow refers to a program attempting to store more data than it can actually take)




