#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

template <typename T>
class Matrix {
private:
    T** data;
    int rows, cols;

    void allocateMemory() {
        data = new T * [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
        }
    }

    void freeMemory() {
        if (data != nullptr) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
        }
    }

public:
    Matrix(int rows = 2, int cols = 2) : rows(rows), cols(cols) {
        allocateMemory();
    }

    ~Matrix() {
        freeMemory();
    }

    void input() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void fillRandom() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = rand() % 100;
            }
        }
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << setw(5) << data[i][j];
            }
            cout << endl;
        }
    }

    T findMin() const {
        T minVal = data[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] < minVal) {
                    minVal = data[i][j];
                }
            }
        }
        return minVal;
    }

    T findMax() const {
        T maxVal = data[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (data[i][j] > maxVal) {
                    maxVal = data[i][j];
                }
            }
        }
        return maxVal;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix operator/(const T& scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] / scalar;
            }
        }
        return result;
    }
};

int main() {
    Matrix<int> mat1(3, 3);
    Matrix<int> mat2(3, 3);

    mat1.fillRandom();
    mat2.fillRandom();

    cout << "Matrix 1:\n";
    mat1.display();

    cout << "Matrix 2:\n";
    mat2.display();

    Matrix<int> sum = mat1 + mat2;
    cout << "Sum:\n";
    sum.display();

    Matrix<int> diff = mat1 - mat2;
    cout << "Difference:\n";
    diff.display();

    cout << "Max in Matrix 1: " << mat1.findMax() << endl;
    cout << "Min in Matrix 1: " << mat1.findMin() << endl;

    return 0;
}
