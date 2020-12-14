#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename V> vector<V> operator * (const vector<V>& v1, const vector<V>& v2);
template <typename First, typename Second> pair<First, Second> operator * (const pair<First, Second> p1, const pair<First, Second> p2);
template <typename Key, typename Value> map<Key, Value> operator * (const map<Key, Value>& m1, const map<Key, Value>& m2);
template <typename T> T Sqr (T x);

template <typename V> vector<V> operator * (const vector<V>& v1, const vector<V>& v2) {
    vector <V> res;

    for (int i = 0; i < min (v1.size(), v2.size()); i++) {
        res.push_back(v1[i] * v2[i]);
    }
    return res;
}

template <typename First, typename Second> pair<First, Second> operator * (const pair<First, Second> p1, const pair<First, Second> p2) {
    First first = p1.first * p2.first;
    Second second = p1.second * p2.second;

    return make_pair(first, second);
}

template <typename Key, typename Value> map<Key, Value> operator * (const map<Key, Value>& m1, const map<Key, Value>& m2) {
    map<Key, Value> res;

    for (const auto& [key, value] : m1) {
        res[key] = value * value;
    }
    return res;
}

template <typename T> T Sqr (T x) {
    return  x * x;
}


// template<typename T>
// T Sqr(T value);

// // Для вектора
// template<typename T>
// vector<T> Sqr(const vector<T>& value);

// // Для словаря
// template<typename K, typename V>
// map<K, V> Sqr(const map<K, V>& value);

// // Для пары
// template<typename K, typename V>
// pair<K, V> Sqr(const pair<K, V>& value);

// // Теперь реализуем их в соответствии с заданием
// template<typename T>
// T Sqr(T value) {
//   return value * value;
// }

// template<typename T>
// vector<T> Sqr(const vector<T>& value) {
//   vector<T> result;
//   for (const T& x : value) {
//     // Здесь важно, что вместо x * x вызывается функция Sqr:
//     // это позволяет возводить в квадрат составные объекты
//     result.push_back(Sqr(x));
//   }

//   return result;
// }

// template<typename K, typename V>
// map<K, V> Sqr(const map<K, V>& value) {
//   map<K, V> result;
//   for (const auto& element : value) {
//     result[element.first] = Sqr(element.second);
//   }
//   return result;
// }

// template<typename K, typename V>
// pair<K, V> Sqr(const pair<K, V>& value) {
//   return {Sqr(value.first), Sqr(value.second)};
// }