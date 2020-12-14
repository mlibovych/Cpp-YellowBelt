#include <algorithm>
#include <utility>
#include <string>
#include <iostream>
#include <deque>

using namespace std;

int main() { 
    deque<string> res;
    int x, N, edit;
    string operation, last_operation;

    cin >> x;
    res.push_back(to_string(x));
    for (cin >> N; N > 0; N--) {
        cin >> operation >> edit;
        if ((last_operation == "-" || last_operation == "+") && (operation == "*" || operation == "/")) {
            res.push_front("(");
            res.push_back(")");
        }
        res.push_back(" ");
        res.push_back(operation);
        res.push_back(" ");
        res.push_back(to_string(edit));
        last_operation = operation;
    }
    for (const auto& it : res) {
        cout << it;
    }
    cout << endl;
    return 0;
}