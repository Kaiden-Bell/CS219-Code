#include "operators.h"
#include <fstream>
#include <iostream>
#include <sstream>


// only used to parse together the strings
string trim(const string& str);

// Convert strings to lowercase and uppercase, based off given file
string toLowerCase(const string& str);
string toUpperCase(const string& str);
// Used to print the registers 
void printState(const Operators& op);

// Determines if the first line IS an instruction
bool isInstruction(const string& line);

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
        if (!isInstruction(line)) {
            continue;  // Skip lines that are not valid instructions
        }


        istringstream iss(line);
        string operation, rd, rn, rm_or_imm;
        iss >> operation >> rd >> rn >> rm_or_imm; // split by op code, dest, source, and second source if given

        operation = toLowerCase(trim(operation));
        rd = trim(rd);
        rn = trim(rn);
        rm_or_imm = trim(rm_or_imm); // this is our immediate or reg val

        int rd_index = rd[1] - '0';  // convert to ind
        int rn_index = rn[1] - '0';  // Convert to ind

        bool isImmediate = false;
        uint32_t value = 0;

        // determine val type
        if (rn[0] == '#') {
            isImmediate = (rn[0] == '#');
            value = isImmediate ? stoul(rn.substr(1), nullptr, 16) : op.registers[rn[1] - '0'];
        } else {
            isImmediate = (rm_or_imm[0] == '#' || rn[0] == '#');
            value = isImmediate ? stoul(rm_or_imm.substr(1), nullptr, 16) : op.registers[rm_or_imm[1] - '0'];
        }


        bool setFlags = (operation.back() == 's'); // handle the operation like normal, instead of ADDS, just ADD
        if (setFlags) {
            operation.pop_back();
        }

        uint32_t result = 0;

        // Perform the operation using Operators class
        if (operation == "mov") {
            op.registers[rd_index] = value;
        } else if (operation == "add") {
            op.setNum1(op.registers[rn_index]);
            op.setNum2(value);
            result = op.add();
            op.registers[rd_index] = result;
        } else if (operation == "sub") {
            op.setNum1(op.registers[rn_index]);
            op.setNum2(value);
            result = op.sub();
            op.registers[rd_index] = result;
        } else if (operation == "and") {
            op.setNum1(op.registers[rn_index]);
            op.setNum2(value);
            result = op._and();
            op.registers[rd_index] = result;
        } else if (operation == "orr") {
            op.setNum1(op.registers[rn_index]);
            op.setNum2(value);
            result = op.orr();
            op.registers[rd_index] = result;
        } else if (operation == "xor") {
            op.setNum1(op.registers[rn_index]);
            op.setNum2(value);
            result = op._xor();
            op.registers[rd_index] = result;
        } else if (operation == "lsr") {
            op.setNum1(op.registers[rn_index]);
            result = op.lsr().first;
            op.registers[rd_index] = result;
        } else if (operation == "lsl") {
            op.setNum1(op.registers[rn_index]);
            result = op.lsl().first;
            op.registers[rd_index] = result;
        } else if (operation == "cmp") {
            op.cmp(op.registers[rn_index], value);
        } else if (operation == "tst") {
            op.tst(op.registers[rn_index], value);
        } else {
            cout << "Unknown Operator used: " << operation << endl;
            continue;
        }
        
        if (rm_or_imm[0] == '<') {rm_or_imm = " ";}

        if (setFlags && operation != "cmp" && operation != "tst"){ 
            op.updateFlags(result);
        }

        cout << toUpperCase(operation) << " " << rd << " " << rn << " " << rm_or_imm << endl;
        printState(op);
    }

    infile.close();
    return 0;
}

string trim(const string& str) {
    size_t start = str.find_first_not_of(" \t"); // find non-whitespace char, (basically anything not a space, or a tab)
    size_t end = str.find_last_not_of(" \t"); // find last non-whitespace char (where the whitespace ends, and what we can ignore)
    return (start == string::npos) ? "" : str.substr(start, end - start + 1); // if we cant find a non-whitespace char, just return sum empty, if it has characters, then just return the new substring
}

string toLowerCase(const string& str) {
    string lower;
    for (char c : str) {
        lower += tolower(c);
    }
    return lower;
}

string toUpperCase(const string& str) {
    string upper;

    for (char c : str) {
        upper += toupper(c);
    }
    return upper;
}

void printState(const Operators& op) {
    for (int i = 0; i < 8; ++i) {
        cout << "R" << i << ":" << "0x" << hex << uppercase << setw(8) << setfill('0') << op.registers[i] << "  ";
        if (i == 3) cout << endl; 
    }
    cout << endl;
    cout << "N = " << op.getNFlag() << " Z = " << op.getZFlag()
         << " C = " << op.getCFlag() << " V = " << op.getVFlag() << endl;
}

bool isInstruction(const string& line) {
    const string validOpcodes[] = {
        "mov", "add", "sub", "and", "orr", "xor", "lsr", "lsl", "cmp", "tst", "adds", "subs", "ands", "lsrs", "lsls"
    };

    string opcode = toLowerCase(trim(line.substr(0, line.find(' '))));
    for (const string& validOpcode : validOpcodes) {
        if (opcode == validOpcode) {
            return true;
        }
    }
    return false;
}