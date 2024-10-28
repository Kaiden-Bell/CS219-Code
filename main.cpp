// Author: Kaiden Bell
// Date: 10/28/24
// Ver: 2.0


#include "operators.h"

#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        return 1; // if there is no file, just exit;
    }  

    string infile_name = argv[1];

    ifstream infile(infile_name);

    string line;

    // Read file line by line
    while (std::getline(infile, line)) {
        string operation = "";
        string num1_str = "";
        string num2_str = "";
        int stg = 0; // 0 = operation, 1 = num1, 2 = num2

        // Loop through each character of the line
        for (char c : line) {
            if (c == ' ') {
                stg++;
                continue; // Skip spaces, move to the next stage
            }

            if (stg == 0) {
                operation += c; // Build the operation string (e.g. "ADD")
            } else if (stg == 1) {
                num1_str += c; // Build the first hex number string
            } else if (stg == 2) {
                num2_str += c; // Build the second hex number string
            }
        }

        // Convert hex strings to integers (ignoring the "0x" part)
        uint32_t num1 = stoul(num1_str, nullptr, 16);
        uint32_t num2 = stoul(num2_str, nullptr, 16);


        // Perform the operation if valid
        if (operation == "ADD") {
            Operators op(num1, num2);
            uint32_t res = op.add();
            cout << "ADD: 0x" << std::hex << op.getNum1() << " + " << "0x" << op.getNum2() << " : 0x" << std::hex << res << endl;
            cout << "Overflow: " << (op.checkOverflow(res) ? "Yes" : "No") << endl;
        } else if (operation == "CMD") {
            // uint32_t res = op.cmd();
            // cout << "CMD: 0x" << std::hex << op.getNum1() << " + " << "0x" << op.getNum2() << " : 0x" << std::hex << res << endl;
            cout << "Not yet Implemented!" << endl;
        } else if (operation == "AND") {
            Operators op(num1, num2);
            uint32_t res = op._and();
            cout << "AND: 0x" << std::hex << op.getNum1() << " & " << "0x" << op.getNum2() << " : 0x" << std::hex << res << endl;

        } else if (operation == "ASR") {
            // Operators op(num1, num2);
            // int32_t res = op.asr();
            // cout << "ASR: 0x" << std::hex << op.getNum1() << "AND" << "0x" << std::hex << op.getNum1() << " = " << "0x" << std::hex << res << endl;
            cout << "Not yet Implemented!" << endl;
        } else if (operation == "LSR") {
            cout << "Not yet Implemented!" << endl;
        } else if (operation == "LSL") {
            cout << "Not yet Implemented!" << endl;
        } else if (operation == "NOT") {
            cout << "Not yet Implemented!" << endl;
        } else if (operation == "ORR") {
            cout << "Not yet Implemented!" << endl;
        } else if (operation == "SUB") {
            cout << "Not yet Implemented!" << endl;
        } else if (operation == "XOR") {
            cout << "Not yet Implemented!" << endl;
        } else {
            cout << "Unknown Operator used: " << operation << endl;
        }
    }

    infile.close();
    return 0;
}
