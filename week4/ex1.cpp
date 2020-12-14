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


int main() {
    const istream_iterator<string> start(cin);
    const istream_iterator<string> end;
    vector<string> strings(start, end);
    vector<string> more_strings(start, end);
}