#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <cstdint>
using namespace std;

void PrintVector(const vector<int64_t>& v) {
    for (int i : v) {
        cout << i << ' ';
    }
    cout << endl;
}

void GetAvg(int64_t& avg, const int& N, const vector<int64_t>& v) {
    avg = 0;
    for (int i : v) {
        avg += i;
    }
    avg /= N;
}

void GetDays(int& count, const int& avg, const vector<int64_t>& v1, vector<int64_t>& v2) {
    int i = 0;

    count = 0;
    for (int s : v1) {
        if (s > avg) {
            count++;
            v2.push_back(i);
        }
        i++;
    }
    cout << count << endl;
}

int main () {
    int N, tmp, count;
    int64_t avg;
    vector<int64_t> temperature, new_temperature;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        temperature.push_back(tmp);
    }
    GetAvg(avg, N, temperature);
    GetDays(count, avg, temperature, new_temperature);
    PrintVector(new_temperature);
    return 0;
}