#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
#include <memory>

using namespace std;

vector<string> SplitStringByChar(string str, char c);

class Date {
    int year, month, day;
public:
    Date (string str) {
        stringstream ss;
        istringstream input (str);
        
        if (!(input >> year)) {
            ss << "Wrong date format: " << str;
            throw runtime_error(ss.str());
        }
        if (input.peek() != '-') {
            ss << "Wrong date format: " << str;
            throw runtime_error(ss.str());
        }
        input.ignore(1);
        if (!(input >> month)) {
            ss << "Wrong date format: " << str;
            throw runtime_error(ss.str());
        }
        
        if (input.peek() != '-') {
            ss << "Wrong date format: " << str;
            throw runtime_error(ss.str());
        }
        input.ignore(1);
        if (!(input >> day)) {
            ss << "Wrong date format: " << str;
            throw runtime_error(ss.str());
        }
        if (input.peek() != EOF) {
            ss << "Wrong date format: " << str;
            throw runtime_error(ss.str());
        }
        if (month < 1 || month > 12) {
            ss << "Month value is invalid: " << month;
            throw runtime_error(ss.str());
        }
        if (day < 1 || day > 31) {
            ss << "Day value is invalid: " << day;
            throw runtime_error(ss.str());
        }
    }
    Date (int year_, int month_, int day_) : year(year_), month(month_), day(day_) {

    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }
};

bool operator<(const Date& lhs, const Date& rhs);

bool operator<=(const Date& lhs, const Date& rhs);

bool operator>(const Date& lhs, const Date& rhs);

bool operator>=(const Date& lhs, const Date& rhs);

bool operator==(const Date& lhs, const Date& rhs);

bool operator!=(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& stream,const Date& date);

Date ParseDate(istream& stream);
