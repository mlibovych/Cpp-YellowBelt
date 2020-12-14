#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

template<typename Key, typename Value> Value& GetRefStrict (map<Key, Value>& m, const Key& k);

template<typename Key, typename Value> Value& GetRefStrict (map<Key, Value>& m, const Key& k) {
    if (!m.count(k)) {
        throw runtime_error("element is apsent");
    }
    return m[k];
}


int main () {
    map<int, string> m = {{1, "value"}};
    string& item = GetRefStrict(m, 1);
    item = "newvalue5";
    cout << m[1] << endl;
    return 0;
}