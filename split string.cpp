#include <iostream> 
#include <string>
#include <vector>

using namespace std;

vector<string> split(string target, string delimiter);

int main() {
    string inputString = "hello world do be do ";
    string delimiter = " ";

    vector<string> result = split(inputString, delimiter);

    cout << "Split strings:" << endl;
    for (const string& str : result) {
        cout << str << endl;
    }

    return 0;
}

vector<string> split(string target, string delimiter) {
    vector<string> result;
    size_t pos = 0;

    while ((pos = target.find(delimiter)) != string::npos) {
        result.push_back(target.substr(0, pos));
        target.erase(0, pos + delimiter.length()); 
    }

    result.push_back(target); 
    return result;
}
