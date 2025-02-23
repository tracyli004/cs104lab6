#include <iostream>
#include "mathfuncs.h"

using namespace std;

void printHelp() {
    cout << "help documentation\n"
         << "  add <num1> <num2>   - Adds two numbers\n"
         << "  sub <num1> <num2>   - Subtracts two numbers\n"
         << "  mul <num1> <num2>   - Multiplies two numbers\n"
         << "  div <num1> <num2>   - Divides two numbers\n"
         << "  quit                - Exit the program\n";
}

void processCommand(const string &command) {
    double num1, num2;
    
    if (command == "help") {
        printHelp();
    } 
    else if (command == "add" || command == "sub" || command == "mul" || command == "div") {
        if (!(cin >> num1 >> num2)) {
            cout << "Invalid input. Please enter two numbers." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return;
        }

        try {
            if (command == "add") cout << add(num1, num2) << endl;
            else if (command == "sub") cout << subtract(num1, num2) << endl;
            else if (command == "mul") cout << multiply(num1, num2) << endl;
            else if (command == "div") cout << divide(num1, num2) << endl;
        } catch (const runtime_error &e) {
            cout << e.what() << endl;
        }
    } 
    else {
        cout << "unknown command" << endl;
    }
}

int main() {
    const string EXIT = "quit";
    string command;

    do {
        cout << "calc: ";
        cin >> command;
        if (command != EXIT) {
            processCommand(command);
        }
    } while (command != EXIT);

    return 0;
}
