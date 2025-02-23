#include <iostream>
#include <string>
#include "randfuncs.h"
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

int main(int argc, char *argv[]) {
    const string EXIT = "quit";
    string command;


    do {
        cout << "calc: ";
        cout << "calc: ";
        cin >> command;
        if (command != EXIT) {
            processCommand(command);

        if ("help" == command) {
            cout << "Commands:\n";
            cout << "  help   - Show this help message";
            cout << "  coin   - Flip a coin (Heads or Tails)";
            cout << "  d6     - Roll a six-sided die";
            cout << "  d20    - Roll a twenty-sided die";
            cout << "  quit   - Exit the calculator";
        } else if ("coin" == command) {
            cout << "result: " << flipCoin() << endl;
        } else if ("d6" == command) {
            cout << "result: " << rollSixSidedDie() << endl;
        } else if ("d20" == command) {
            cout << "result: " << rollTwentySidedDie() << endl;
        } else if (EXIT != command) {
            cout << "unknown command, try typing 'help'";
        }
    } while (command != EXIT);

    } while (EXIT != command);

    return 0;
}