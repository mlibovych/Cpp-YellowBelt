#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

bool IsPalindrom(const string& str) {
  // Ð’Ñ‹ Ð¼Ð¾Ð¶ÐµÑ‚Ðµ Ð²ÑÑ‚Ð°Ð²Ð»ÑÑ‚ÑŒ ÑÑŽÐ´Ð° Ñ€Ð°Ð·Ð»Ð¸Ñ‡Ð½Ñ‹Ðµ Ñ€ÐµÐ°Ð»Ð¸Ð·Ð°Ñ†Ð¸Ð¸ Ñ„ÑƒÐ½ÐºÑ†Ð¸Ð¸,
  // Ñ‡Ñ‚Ð¾Ð±Ñ‹ Ð¿Ñ€Ð¾Ð²ÐµÑ€Ð¸Ñ‚ÑŒ, Ñ‡Ñ‚Ð¾ Ð²Ð°ÑˆÐ¸ Ñ‚ÐµÑÑ‚Ñ‹ Ð¿Ñ€Ð¾Ð¿ÑƒÑÐºÐ°ÑŽÑ‚ ÐºÐ¾Ñ€Ñ€ÐµÐºÑ‚Ð½Ñ‹Ð¹ ÐºÐ¾Ð´
  // Ð¸ Ð»Ð¾Ð²ÑÑ‚ Ð½ÐµÐºÐ¾Ñ€Ñ€ÐµÐºÑ‚Ð½Ñ‹Ð¹
}

void Test1 () {
    Assert (IsPalindrom("AmA"), "yes");
    Assert (!IsPalindrom("Am1"), "no");
}

void Test2 () {
    Assert (IsPalindrom("a"), "yes 1");
    Assert (IsPalindrom("aa"), "yes 2");
    Assert (IsPalindrom("aaa"), "yes 3");
}

void Test3 () {
    AssertEqual (IsPalindrom("av"), false);
}

void Test4 () {
    AssertEqual (IsPalindrom(""), true);
}

void Test5 () {
    AssertEqual (IsPalindrom("  rrr "), false);
}

int main() {
  TestRunner runner;
  
  runner.RunTest(Test1, "Test1");
  runner.RunTest(Test2, "Test2");
  runner.RunTest(Test3, "Test3");
  runner.RunTest(Test4, "Test4");
  runner.RunTest(Test5, "Test5");
  return 0;
}