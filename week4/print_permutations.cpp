#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() { 
    int num;
    vector<int> nums;

    cin >> num;
    while(num) {
        nums.push_back(num);
        num--;
    }
    // sort(nums.begin(), nums.end());
    do {
        for(const auto& it : nums) {
            cout << it << " ";
        }
        cout << endl;
    } while(prev_permutation(nums.begin(), nums.end()));
    return 0;
}