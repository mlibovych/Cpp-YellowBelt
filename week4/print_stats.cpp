#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

void PrintStats(vector<Person> persons) {
    cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
    auto gender = partition(persons.begin(), persons.end(), [](const Person& person) {
        return person.gender == Gender::FEMALE;
    });
    cout << "Median age for females = " << ComputeMedianAge(persons.begin(), gender) << endl;
    cout << "Median age for males = " << ComputeMedianAge(gender, persons.end()) << endl;
    auto fem_work = partition(persons.begin(), gender, [](const Person& person) {
        return person.is_employed;
    });
    cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), fem_work) << endl;
    cout << "Median age for unemployed females = " << ComputeMedianAge(fem_work, gender) << endl;
    auto male_work = partition(gender, persons.end(), [](const Person& person) {
        return person.is_employed == 1;
    });
    cout << "Median age for employed males = " << ComputeMedianAge(gender, male_work) << endl;
    cout << "Median age for unemployed males = " << ComputeMedianAge(male_work, persons.end()) << endl;
}

int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}