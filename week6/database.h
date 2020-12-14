#pragma once

#include "date.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Database {
    map <Date, set<string>> events;
    map <Date, vector<string>> hrono_events;
public:
    void Add(const Date& date, const string& event);

    template <class Func>
    int RemoveIf(Func predicate) {
        int res = 0;

        for (auto& [key, value] : events) {
            auto value_ = value;
            for (const auto& data : value_) {
                if (predicate(key, data)) {
                    value.erase(data);
                }
            }
        }
        for (auto& [key, value] : hrono_events) {
            Date k = key;
            auto it = stable_partition(value.begin(), value.end(), [predicate, k](const string& data) {
                return (!predicate(k, data));
            });
            res += value.end() - it;
            value.erase(it, value.end());
        }
        auto hrono_events_ = hrono_events;
        for (auto [key, value] : hrono_events_) {
            if (!value.size()) {
                hrono_events.erase(key);
            }
        }
        return res;
    }
    
    template <class Func>
    vector <pair <Date, string>> FindIf (Func predicate) const {
        vector<pair<Date, string>> res;

        for (const auto& [key, value] : hrono_events) {
            for (const auto& event : value) {
                if (predicate(key, event)) {
                    res.push_back(make_pair(key, event));
                }
            }
        }
        return res;
    }

    void Print(ostream& s) const;

    string Last (const Date& date) const;
};

template <typename First, typename Second>
ostream& operator<<(ostream& stream, const pair<First, Second> p) {
    stream << p.first << ' ' << p.second;
    return stream;
}
