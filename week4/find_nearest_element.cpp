#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

set<int>::const_iterator FindNearestElement(const set<int>& numbers,int border) {
    const auto right = numbers.lower_bound(border);
    if (right == numbers.begin()) {
        return right;
    }
    const auto left = prev(right);
    if (right == numbers.end()) {
        return left;
    }
    const bool is_left = (border - *left <= *right - border);
    return is_left ? left : right;
}
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел

// int main() {
//   set<int> numbers = {1, 4, 6};
//   cout <<
//       *FindNearestElement(numbers, 0) << " " <<
//       *FindNearestElement(numbers, 3) << " " <<
//       *FindNearestElement(numbers, 5) << " " <<
//       *FindNearestElement(numbers, 6) << " " <<
//       *FindNearestElement(numbers, 100) << endl;
      
//   set<int> empty_set;
  
//   cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
//   return 0;
// }