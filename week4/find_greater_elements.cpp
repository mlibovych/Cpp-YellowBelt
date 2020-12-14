#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
    vector<T> res;

    for (auto it = elements.begin (); it != elements.end() ; it++) {
        if (*it > border) {
            res.push_back(*it);
        }
    }
    return res;
}

// int main() {
//   for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, -5234567)) {
//     cout << x << " ";
//   }
//   cout << endl;
  
//   string to_find = "Python";
//   cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
//   return 0;
// }