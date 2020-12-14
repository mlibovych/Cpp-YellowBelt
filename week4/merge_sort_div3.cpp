#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    if (range_end - range_begin < 3) {
        return;
    }
    vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto first = elements.begin() + elements.size() / 3;
    auto second = first + elements.size() / 3;
    MergeSort(elements.begin(), first);
    MergeSort(first, second);
    MergeSort(second, elements.end());
    vector<typename RandomIt::value_type> tmp;
    merge(elements.begin(), first, first, second, back_inserter(tmp));
    merge(tmp.begin(), tmp.end(), second, elements.end(), range_begin);
}

// int main() {
//     vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
//     MergeSort(begin(v), end(v));
//     for (int x : v) {
//         cout << x << " ";
//     }
//     cout << endl;
//     return 0;
// }