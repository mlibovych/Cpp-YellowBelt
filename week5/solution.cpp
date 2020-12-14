#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Person {
public:
    const string Name, Type;

    Person(string name, string type) : Name(name), Type(type) {

    }

    virtual void Walk(string destination) {
        cout << GetTypeAndName() << " walks to: " << destination << endl;
    }

    string GetTypeAndName () {
        stringstream ss;

        ss << Type << ": " << Name;
        return ss.str();
    }
};

class Student : public Person {
public:
    const string FavouriteSong;

    Student(string name, string favouriteSong) : Person(name, "Student"), FavouriteSong(favouriteSong) {

    }

    void Learn() {
        cout << GetTypeAndName() << " learns" << endl;
    }

    void Walk(string destination) override {
        Person :: Walk(destination);
        SingSong();
    }

    void SingSong() {
        cout << GetTypeAndName() << " sings a song: " << FavouriteSong << endl;
    }
};

class Teacher : public Person {
public:
    const string Subject;

    Teacher(string name, string subject) : Person(name, "Teacher"), Subject(subject) {
    
    }

    void Teach() {
        cout << GetTypeAndName() << " teaches: " << Subject << endl;
    }

    void Walk(string destination) override {
        cout << GetTypeAndName() << " walks to: " << destination << endl;
    }
};


class Policeman : public Person {
public:

    Policeman(string name) : Person(name, "Policeman") {
        
    }

    void Check(Person& person) {
        cout << GetTypeAndName() << " checks " << person.Type << ". " << person.Type << "'s name is: " << person.Name << endl;
    }
};

void VisitPlaces(Person &person, vector<string> places) {
    for (auto p : places) {
        person.Walk(p);
    }
}

// void VisitPlaces(Teacher t, vector<string> places) {
//     for (auto p : places) {
//         t.Walk(p);
//     }
// }

// void VisitPlaces(Student s, vector<string> places) {
//     for (auto p : places) {
//         s.Walk(p);
//     }
// }

// void VisitPlaces(Policeman pol, vector<string> places) {
//     for (auto p : places) {
//         pol.Walk(p);
//     }
// }


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
