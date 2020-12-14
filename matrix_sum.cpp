#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

class Matrix {
    int rows, cols;
    vector <vector <int>> matrix;
public:
    Matrix () {
        rows = 0;
        cols = 0;
        matrix.resize(0);
    }
    Matrix (int num_rows, int num_cols) {
        Reset(num_rows, num_cols);
    }
    void Reset (int num_rows, int num_cols) {
        if (num_rows < 0 || num_cols < 0) {
            throw out_of_range("ff");
        }
        if (num_rows == 0 || num_cols == 0) {
            num_rows = 0;
            num_cols = 0;
        }
        rows = num_rows;
        cols = num_cols;
        matrix.resize(num_rows);
        for (auto& row : matrix) {
            row.assign(num_cols, 0);
        }
    }
    int At (int row, int col) const {
        if (row >= GetNumRows() || col >= GetNumColumns() ||
            row < 0 || col < 0) {
            throw out_of_range("ff");
        }
        return matrix[row][col];
    }
    int& At (int row, int col) {
        if (row >= GetNumRows() || col >= GetNumColumns() ||
            row < 0 || col < 0) {
            throw out_of_range("ff");
        }
        return matrix[row][col];
    }
    int GetNumRows (void) const {
        return rows;
    }
    int GetNumColumns (void) const {
        return cols;
    }
};

ostream& operator<<(ostream& stream, const Matrix& matrix) {
     if(stream) {
        stream << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
        for (int i = 0; i < matrix.GetNumRows(); i++) {
            for (int j = 0; j < matrix.GetNumColumns(); j++) {
                stream << matrix.At(i, j);
                if (j < matrix.GetNumColumns() - 1) {
                    stream << " ";
                }
                else {
                    stream << endl;
                }
            }
        }
    }
    
    return stream;
}

istream& operator>>(istream& stream, Matrix& matrix) {
    int rows, cols, value;

    if(stream) {
        stream >> rows >> cols;
        matrix = Matrix(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                stream >> value;
                matrix.At(i, j) = value;
            }
        }
    }
    
    return stream;
}

bool operator== (const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetNumColumns() != rhs.GetNumColumns() || 
        lhs.GetNumRows() != rhs.GetNumRows()) {
            return 0;
    }
    for (int i = 0; i < lhs.GetNumRows(); i++) {
        for (int j = 0; j < lhs.GetNumColumns(); j++) {
            if (lhs.At(i, j) != rhs.At(i, j)) {
                return 0;
            }
        }
    }
    return 1;
}

Matrix operator+ (const Matrix& lhs, const Matrix& rhs) {
    Matrix res;

    if (lhs.GetNumColumns() != rhs.GetNumColumns() || 
        lhs.GetNumRows() != rhs.GetNumRows()) {
        throw invalid_argument("invalid size");
    }
    res.Reset(lhs.GetNumRows(), lhs.GetNumColumns());
    for (int i = 0; i < res.GetNumRows(); i++) {
        for (int j = 0; j < res.GetNumColumns(); j++) {
            res.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }
    return res;
}

int main() {
    Matrix one;
    Matrix two;

    // cin >> one >> two;
    one.Reset(0, 0);
    two.Reset(0, 3);
    cout << one + two << endl;
    return 0;
}
