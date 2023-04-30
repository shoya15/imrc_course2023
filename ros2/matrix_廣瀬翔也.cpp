#include <iostream>
#include <vector>
#include <string>
#include <cmath>

#include <iomanip>
#include <chrono>
#include <random>

struct Matrix
{
public:
    // コンストラクタ
    Matrix();
    Matrix(int rows, int cols);

    // 変換コンストラクタ
    Matrix(std::vector<std::vector<double>> matrix);

    // デストラクタ
    virtual ~Matrix();

    // 変換関数
    operator std::vector<std::vector<double>>();

    // 演算子オーバーロード
    friend Matrix operator+(Matrix matrix1, Matrix matrix2);
    friend Matrix operator-(Matrix matrix1, Matrix matrix2);
    friend Matrix operator*(Matrix matrix1, Matrix matrix2);
    friend Matrix operator*(double x, Matrix matrix);
    friend Matrix operator/(Matrix matrix, double x);

    size_t rows();                // 行数
    size_t cols();                // 列数
    double &at(int row, int col); // 要素へのアクセスメソッド
    Matrix unit();                // 単位行列
    Matrix transpose();           // 転置行列
    double determinant();         // 行列式
    Matrix inverse();             // 逆行列
    std::string toString();

private:
    std::vector<std::vector<double>> data; // データ構造
};

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "input ./a.out [matrix_size]" << std::endl;
    }

    std::cout << std::fixed << std::setprecision(10);
    std::srand(std::time(nullptr));

    const size_t &size = std::atoi(argv[1]);
    Matrix matrix1(std::atoi(argv[1]), size);
    Matrix matrix2(std::atoi(argv[1]), size);

    std::chrono::high_resolution_clock::time_point start, end;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matrix1.at(i, j) = std::rand() % 10;
            matrix2.at(i, j) = std::rand() % 10;
        }
    }
    std::cout << "行列1: " << matrix1.toString() <<std::endl;
    std::cout << "行列2: " << matrix2.toString() <<std::endl;
    std::cout << std::endl;

    // std::cout << "和      : " << (matrix1 + matrix2).toString() << std::endl;
    // std::cout << "差      : " << (matrix1 - matrix2).toString() << std::endl;
    // std::cout << "行列積  : " << (matrix1 * matrix2).toString() << std::endl;
    // std::cout << "値との積: " << (100 * matrix1).toString() << std::endl;
    // std::cout << "除算    : " << (matrix1 / 100).toString() << std::endl;
    // std::cout << "転置行列: " << matrix1.transpose().toString() << std::endl;
    // std::cout << "行列式  : " << matrix1.determinant() << std::endl;
    // std::cout << "逆行列  : " << matrix1.inverse().toString() << std::endl;
    std::cout << "単位行列1 : " << matrix1.unit().toString() << std::endl;
}

// コンストラクタ
Matrix::Matrix() {}
Matrix::Matrix(int rows, int cols)
{
    std::vector<std::vector<double>> matrix(rows, std::vector<double>(cols));
    data = matrix;
}

// // 変換コンストラクタ
Matrix::Matrix(std::vector<std::vector<double>> matrix)
{
    data = matrix;
}

// デストラクタ
Matrix::~Matrix(){}

// // 変換関数
Matrix::operator std::vector<std::vector<double>>()
{
    return data;
}

// 演算子オーバーロード
Matrix operator+(Matrix matrix1, Matrix matrix2)
{
    Matrix result = matrix1;
    for(int i = 0; i < matrix1.rows(); i++){
        for(int j = 0; j < matrix1.cols(); j++){
            result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }
    return result;
}
Matrix operator-(Matrix matrix1, Matrix matrix2)
{
    Matrix result = matrix1;
    for(int i = 0; i < matrix1.rows(); i++){
        for(int j = 0; j < matrix1.cols(); j++){
            result.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        }
    }
    return result;
}
Matrix operator*(Matrix matrix1, Matrix matrix2)
{
    Matrix result = matrix1;
    for(int i = 0; i < matrix1.rows(); i++){
        for(int j = 0; j < matrix2.cols(); j++){
            result.data[i][j] = 0;
            for(int k = 0; k < matrix1.cols(); k++)
            result.data[i][j] += matrix1.data[i][k] * matrix2.data[k][j];
        }
    }
    return result;
}
Matrix operator*(double x, Matrix matrix)
{
    for(int i = 0; i < matrix.rows(); i++){
        for(int j = 0; j < matrix.cols(); j++){
            matrix.data[i][j] *= x;
        }
    }
    return matrix;
}
Matrix operator/(Matrix matrix, double x)
{
    for(int i = 0; i < matrix.rows(); i++){
        for(int j = 0; j < matrix.cols(); j++){
            matrix.data[i][j] /= x;
        }
    }
    return matrix;
}

// 行数
size_t Matrix::rows()
{
    return data.size();
}

// 列数
size_t Matrix::cols()
{
    return data[0].size();
}

// 要素へのアクセスメソッド
double &Matrix::at(int row, int col)
{
    return data[row][col];
}

// 単位行列
Matrix Matrix::unit()
{
    std::vector<std::vector<double>> vec(this->rows(), std::vector<double>(this->cols(), 0));
    for (int i = 0; i < this->rows(); i++)
    {
        for (int j = 0; j < this->cols(); j++)
        {
            if (i == j)
            {
                vec[i][j] = 1;
            }
        }
    }
    return vec;
}

// 転置行列
Matrix Matrix::transpose()
{
    std::vector<std::vector<double>> trans_vec = data;
    for (int i = 0; i < trans_vec.size(); i++)
    {
        for (int j = 0; j < trans_vec[0].size(); j++)
        {
            trans_vec[j][i] = data[i][j];
        }
    }
    return trans_vec;
}

// 行列式
double Matrix::determinant()
{
    std::vector<std::vector<double>> vec = data;
    for(int i = 0; i < this->rows(); i++){
        for(int j = 0; j < this->cols(); j++){
            if(i < j)
            {
                double buf = vec[j][i] / vec[i][i];
                for(int k = 0; k < this->cols(); k++){
                    vec[j][k] -= vec[i][k] * buf;
                }
            }
        }
    }

    double result = 1;
    for(int i = 0; i < this->rows(); i++){
        result *= vec[i][i];
    }
    return result;
}

// 逆行列
Matrix Matrix::inverse()
{
    std::vector<std::vector<double>> vec = data;
    std::vector<std::vector<double>> inv_vec = ((Matrix)vec).unit();

    for (int i = 0; i < vec.size(); i++)
    {
        double t = 1 / vec[i][i];
        for (int j = 0; j < vec.size(); j++)
        {
            vec[i][j] *= t;
            inv_vec[i][j] *= t;
        }

        for (int j = 0; j < vec.size(); j++)
        {
            if (i != j)
            {
                double t = vec[j][i];
                for (int k = 0; k < vec.size(); k++)
                {
                    vec[j][k] -= vec[i][k] * t;
                    inv_vec[j][k] -= inv_vec[i][k] * t;
                }
            }
        }
    }
    return inv_vec;
}

std::string Matrix::toString()
{
    std::string ret = "[";
    for (int i = 0, rows = this->rows(); i < rows; i++)
    {
        ret += "[";
        for (int j = 0, cols = this->cols(); j < cols; j++)
        {
            ret += std::to_string(this->at(i, j)) + ", ";
        }
        ret[ret.size() - 2] = ']';
    }
    ret += "]";
    return ret;
}