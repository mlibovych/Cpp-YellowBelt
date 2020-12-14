#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <memory>
#include <cmath>

using namespace std;

class Figure {
public :
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};

class Triangle : public Figure {
    int a, b, c;
public :
    Triangle(int a_, int b_, int c_) : a(a_), b(b_), c(c_) {

    }
    string Name() override {
        return "TRIANGLE";
    };
    double Perimeter() override {
        return a + b + c;
    };
    double Area() override {
        return sqrt((Perimeter() / 2) * (Perimeter() / 2 - a) * (Perimeter() / 2 - b) * (Perimeter() / 2 - c));
    };
};

class Circle : public Figure {
    int r;
public :
    Circle(int r_) : r(r_) {

    }
    string Name() override {
        return "CIRCLE";
    };
    double Perimeter() override {
        return 2 * 3.14 * r;
    };
    double Area() override {
        return 3.14 * pow(r, 2);
    };
};

class Rect : public Figure {
    int width, height;
public :
    Rect(int width_, int height_) : width(width_), height(height_) {

    }
    string Name() override {
        return "RECT";
    };
    double Perimeter() override {
        return width * 2 + height * 2;
    };
    double Area() override {
        return width * height;
    };
};

shared_ptr<Figure> CreateFigure (istringstream& stream) {
    string type;

    stream >> type >> ws;
    if (type == "RECT") {
        int width, height;

        stream >> width >> height;
        return make_shared<Rect>(width, height);
    }
    else if (type == "TRIANGLE") {
        int a, b, c;

        stream >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    }
    else if (type == "CIRCLE") {
        int r;

        stream >> r;
        return make_shared<Circle>(r);
    }

    return {};
}

int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}