// Author: Kaiden Bell
// Date: 9/27/24
// Ver: 1.0


#include "operators.h"

#include <fstream>


int main() {
    ifstream infile("input.txt");
    string line;

    if (!infile.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

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

            cout << "ADD: 0x" << std::hex << op.getNum1() << " + " << "0x" << op.getNum2() << " : 0x" << std::hex << res << std::endl;
            cout << "Overflow: " << (op.checkOverflow(res) ? "Yes" : "No") << endl;
        } else {
            cout << "Unknown Operator used: " << operation << endl;
        }
    }

    infile.close();
    return 0;
}
