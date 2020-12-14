#include "database.h"

void Database::Add(const Date& date, const string& event) {
    if (!events[date].count(event)) {
        events[date].insert(event);
        hrono_events[date].push_back(event);
    }
}

string Database::Last (const Date& date) const {
    stringstream ss;
    auto it = hrono_events.upper_bound(date);

    if (it == hrono_events.begin()) {
        ss << "No entries";
    }
    else {
        it--;
        ss << it->first << " " << *it->second.rbegin();
    }
    return ss.str();
}

void Database::Print(ostream& s) const {
    for (const auto& [key , value] : hrono_events) {
        for (const auto& event : value) {
            s << key;
            s << ' ' << event << endl;
        }
    }
}