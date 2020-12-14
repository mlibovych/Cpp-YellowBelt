#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
    vector<string> res;
    auto first = s.begin();
    auto second = find(first, s.end(), ' ');
    
    while(1) {
      string word = {first, second};

      res.push_back(word);
      if (second == s.end()) {
        break;
      }
      first = second + 1;
      second = find(first, s.end(), ' ');
    }
    return res;
}

int main() {
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}