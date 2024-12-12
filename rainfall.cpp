#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to get month name from integer
string getMonthName(int month) {
    switch (month) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Invalid Month";
    }
}

int main() {
    // Average monthly rainfall
    vector<double> avgRainfall = { 3.1, 2.5, 3.8, 4.2, 4.8, 4.0, 3.5, 3.1, 3.0, 3.4, 3.7, 3.2 }; 

    // Get current month from user
    int currentMonth;
    cout << "Enter current month (1-12): ";
    cin >> currentMonth;

    // Input validation for current month
    while (currentMonth < 1 || currentMonth > 12) {
        cout << "Invalid month. Please enter a number between 1 and 12: ";
        cin >> currentMonth;
    }

    // Get actual rainfall for past 12 months
    vector<double> actualRainfall(12);
    cout << "Enter rainfall for the past 12 months:" << endl;
    for (int i = 0; i < 12; ++i) {
        int month = (currentMonth - 1 - i + 12) % 12 + 1; // Calculate past month
        cout << getMonthName(month) << ": ";
        cin >> actualRainfall[i];
    }

    // Calculate and print rainfall data
    cout << "\nRainfall Data:\n";
    cout << "Month\t\tRainfall\t\tDifference\n";
    cout << "-----------------------------------------\n";
    for (int i = 0; i < 12; ++i) {
        int month = (currentMonth - 1 - i + 12) % 12 + 1;
        double difference = actualRainfall[i] - avgRainfall[month - 1]; 
        cout << getMonthName(month) << "\t\t" << actualRainfall[i] << "\t\t";
        if (difference > 0) {
            cout << "+" << difference << " (Above Average)" << endl;
        } else if (difference < 0) {
            cout << difference << " (Below Average)" << endl;
        } else {
            cout << difference << " (Average)" << endl;
        }
    }

    return 0;
}
