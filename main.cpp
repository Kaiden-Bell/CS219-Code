#include "operators.h"
#include <fstream>
#include <iostream>
#include <sstream>


// only used to parse together the strings
string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t"); // find non-whitespace char, (basically anything not a space, or a tab)
    size_t end = str.find_last_not_of(" \t"); // find last non-whitespace char (where the whitespace ends, and what we can ignore)
    return (start == string::npos) ? "" : str.substr(start, end - start + 1); // if we cant find a non-whitespace char, just return sum empty, if it has characters, then just return the new substring
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Error location File!" << endl;
        return 1;
    }

    string infile_name = argv[1];
    ifstream infile(infile_name);

    if (!infile.is_open()) {
        cout << "Error opening file: " << infile_name << endl;
        return 1;
    }

    string line;
    Operators op;

    while (getline(infile, line)) {
        istringstream iss(line);
        string operation, num1_str, num2_str;
        iss >> operation >> num1_str >> num2_str; // split the input in the file into two parts

        operation = trim(operation);
        num1_str = trim(num1_str);
        num2_str = trim(num2_str);

        uint32_t num1 = stoul(num1_str, nullptr, 16);
        uint32_t num2 = (!num2_str.empty()) ? stoul(num2_str, nullptr, 16) : 0;
        
        op.setNum1(num1);
        op.setNum2(num2);

        bool setFlags = (operation.back() == 'S'); // handle the operation like normal, instead of ADDS, just ADD
        if (setFlags) {
            operation.pop_back();
        }

        uint32_t result;
        // not using switch statement, reqs enums
        if (operation == "ADD") {
            result = op.add();
        } else if (operation == "AND") {
            result = op._and();
        } else if (operation == "ASR") {
            result = op.asr().first;
        } else if (operation == "LSR") {
            result = op.lsr().first;
        } else if (operation == "LSL") {
            result = op.lsl().first;
        } else if (operation == "NOT") {
            result = op._not().first;
        } else if (operation == "ORR") {
            result = op.orr();
        } else if (operation == "SUB") {
            result = op.sub();
        } else if (operation == "XOR") {
            result = op._xor();
        } else {
            cout << "Unknown Operator used: " << operation << endl;
            continue;
        }


        if (setFlags){ 
            op.updateFlags(result);
        }

        cout << operation << " 0x" << hex << num1 << " 0x" << num2 << ": 0x" << result << endl;
        cout << "N: " << op.getNFlag() << " Z: " << op.getZFlag() << endl;
    }

    infile.close();
    return 0;
}
