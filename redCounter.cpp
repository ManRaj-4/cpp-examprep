#include <iostream>
#include <string>

using namespace std;

class Counter {
private:
    int maxCount;
    int count;

public:
    Counter(int max) : maxCount(max), count(0) {}

    void reset() {
        count = 0;
    }

    void incr1() {
        count = (count + 1) % (maxCount + 1); // Handle overflow within the counter
    }

    void incr10() {
        count = (count + 10) % (maxCount + 1);
    }

    void incr100() {
        count = (count + 100) % (maxCount + 1);
    }

    void incr1000() {
        count = (count + 1000) % (maxCount + 1);
    }

    bool overflow() {
        return count > maxCount;
    }

    void display() {
        // Format output as dollars and cents
        int dollars = count / 100;
        int cents = count % 100;

        cout << "$" << dollars / 10 << dollars % 10 << "." << cents / 10 << cents % 10 << endl;
    }
};

int main() {
    Counter groceryCounter(9999); 

    char key;
    int value;

    cout << "Grocery Counter Simulation" << endl;
    cout << "Keys: a = cents, s = dimes, d = dollars, f = tens of dollars, o = overflow" << endl;
    cout << "Enter key and value (e.g., 'a5' for 5 cents, 'd3' for 3 dollars):" << endl;

    do {
        cin >> key >> value;

        switch (key) {
            case 'a':
                for (int i = 0; i < value; ++i) {
                    groceryCounter.incr1();
                    if (groceryCounter.overflow()) {
                        cout << "** Overflow! **" << endl;
                        break;
                    }
                }
                break;
            case 's':
                for (int i = 0; i < value; ++i) {
                    groceryCounter.incr10();
                    if (groceryCounter.overflow()) {
                        cout << "** Overflow! **" << endl;
                        break;
                    }
                }
                break;
            case 'd':
                for (int i = 0; i < value; ++i) {
                    groceryCounter.incr100();
                    if (groceryCounter.overflow()) {
                        cout << "** Overflow! **" << endl;
                        break;
                    }
                }
                break;
            case 'f':
                for (int i = 0; i < value; ++i) {
                    groceryCounter.incr1000();
                    if (groceryCounter.overflow()) {
                        cout << "** Overflow! **" << endl;
                        break;
                    }
                }
                break;
            case 'o':
                if (groceryCounter.overflow()) {
                    cout << "** Overflow! **" << endl;
                } else {
                    cout << "** No Overflow **" << endl;
                }
                break;
            default:
                cout << "Invalid key. Please use 'a', 's', 'd', 'f', or 'o'." << endl;
                break;
        }

        groceryCounter.display();

    } while (key != 'q'); // Exit loop with 'q'

    return 0;
}
