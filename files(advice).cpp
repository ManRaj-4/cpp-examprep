#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inFile("advice.txt");
    string advice;

    // Read initial advice from file
    if (inFile) {
        getline(inFile, advice, '\0'); // Read until end-of-file character
    } else {
        cout << "No initial advice found. Please provide some." << endl;
    }

    inFile.close();

    cout << "Advice:\n" << advice ;

    cout << "Enter your advice (press Return twice to end):" << endl;

    // Read user's advice
    string userAdvice;
    string line;
    do {
        getline(cin, line);
        userAdvice += line + "\n";
    } while (line != ""); // End when two consecutive empty lines are entered

    // Write user's advice to file
    ofstream outFile("advice.txt");
    if (outFile) {
        outFile << userAdvice;
    } else {
        cerr << "Error: Could not write advice to file." << endl;
        return 1;
    }
    outFile.close();

    return 0;
}
