/*
・メインプログラム内でエラー処理を入れることはしない
・クラスについてもテンプレートにすることができる
・直接データ構造をいじる
・Doxygen
*/
#include <iostream>
#include <vector>
#include <string>
#include<cmath>

#include <iomanip>
#include <chrono>
#include <random>

struct Matrix
{
public:
    // コンストラクタ
    Matrix();
    Matrix(int rows, int cols);

    // デストラクタ
    virtual ~Matrix();

    // 変換関数
    operator std::vector<std::vector<double>>();

    // 参照型になっていない
    // 演算子オーバーロード
    Matrix operator+=(Matrix matrix);
    Matrix operator-=(Matrix matrix);
    Matrix operator*=(Matrix matrix);            // N行N列どうしの積
    Matrix operator*=(const double x);
    Matrix operator/=(const double x);
    Matrix operator+(const Matrix matrix) const;
    Matrix operator-(const Matrix matrix) const;
    Matrix operator*(Matrix matrix);             // P行Q列とQ行R列の積
    Matrix operator*(const double x) const;
    Matrix operator/(const double x) const;

    size_t rows();                               // 行数
    size_t cols();                               // 列数
    const double &at(int row, int col) const;    // 要素へのアクセスメソッド
    double &at(int row, int col);
    static Matrix unit(int rows, int cols);      // 単位行列
    Matrix transpose();                          // 転置行列
    double determinant();                        // 行列式
    Matrix inverse();                            // 逆行列
    std::string toString();

private:
    std::vector<std::vector<double>> data;       // データ構造
};

int main(int argc, char **argv)
{
    if(argc < 4)
    {
        std::cout << "input ./a.out [matrix_size]" << std::endl;
    }

    std::cout << std::fixed << std::setprecision(10);
    std::srand(std::time(nullptr));

    const size_t &size1 = std::atoi(argv[1]);
    const size_t &size2_rows = std::atoi(argv[2]);
    const size_t &size2_cols = std::atoi(argv[3]);
    Matrix matrix1(size1, size1);
    Matrix matrix2(size2_rows, size2_cols);

    std::chrono::high_resolution_clock::time_point start, end;
    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < size1; i++){
        for(int j = 0; j < size1; j++){
            matrix1.at(i, j) = std::rand() % 10;
        }
    }
    for(int i = 0; i < size2_rows; i++){
        for(int j = 0; j < size2_cols; j++){
            matrix2.at(i, j) = std::rand() % 10;
        }
    }
    std::cout << "行列1: " << matrix1.toString() <<std::endl;
    std::cout << "行列2: " << matrix2.toString() <<std::endl;
    std::cout << std::endl;

    if(matrix1.rows() == matrix2.rows() && matrix1.cols() == matrix2.cols())
    {
        std::cout << "和      : " << (matrix1 + matrix2).toString() << std::endl;
        std::cout << "差      : " << (matrix1 - matrix2).toString() << std::endl;
    }else
    {
        std::cout << "Error   : 行列1と行列2の行数・列数が異なるため和と差を計算できません。" << std::endl;
    }

    if(matrix1.rows() == matrix2.rows() && matrix1.cols() == matrix2.cols())
    {
        Matrix result = matrix1;
        result *= matrix2;
        std::cout << "行列積  : " << result.toString() << std::endl;
    }else if(matrix1.cols() == matrix2.rows())
    {
        std::cout << "行列積  : " << (matrix1 * matrix2).toString() << std::endl;
    }else
    {
        std::cout << "Error   : 行列1の列数と行列2の行数が異なるため積を計算できません。" << std::endl;
    }

    std::cout << "値との積: " << (matrix1 * 100).toString() << std::endl;
    std::cout << "除算    : " << (matrix1 / 100).toString() << std::endl;
    std::cout << "転置行列: " << matrix1.transpose().toString() << std::endl;
    double det = matrix1.determinant();
    std::cout << "行列式  : " << det << std::endl;
    
    if(det == 0)
    {
        std::cout << "Error   : 行列1には逆行列が存在しません。" << std::endl;
    }else
    {
        std::cout << "逆行列  : " << matrix1.inverse().toString() << std::endl;
    }
}

// コンストラクタ
Matrix::Matrix() {}
Matrix::Matrix(int rows, int cols)
{
    std::vector<std::vector<double>> data(rows, std::vector<double>(cols));
}

// デストラクタ
Matrix::~Matrix(){}

// 変換関数
Matrix::operator std::vector<std::vector<double>>()
{
    return data;
}

// 演算子オーバーロード
Matrix Matrix::operator+=(Matrix matrix)
{
    for(int i = 0; i < this->rows(); i++){
        for(int j = 0; j < this->cols(); j++){
            this->data[i][j] += matrix.at(i, j);
        }
    }
    return *this;
}
Matrix Matrix::operator-=(Matrix matrix)
{
    for(int i = 0; i < this->rows(); i++){
        for(int j = 0; j < this->cols(); j++){
            this->data[i][j] -= matrix.at(i, j);
        }
    }
    return *this;
}
// 処理の重複
// N行N列どうしの積
Matrix Matrix::operator*=(Matrix matrix)
{
    Matrix result(this->rows(), this->cols());
    for(int i = 0; i < this->rows(); i++){
        for(int j = 0; j < this->cols(); j++){
            for(int k = 0; k < this->cols(); k++){
                result.at(i, j) += this->data[i][k] * matrix.at(k, j);
            }
        }
    }
    this->data = result;
    return *this;
}
Matrix Matrix::operator*=(const double x)
{   
    for(int i = 0; i < this->rows(); i++){
        for(int j = 0; j < this->cols(); j++){
            this->data[i][j] *= x;
        }
    }
    return *this;
}
Matrix Matrix::operator/=(const double x)
{   
    for(int i = 0; i < this->rows(); i++){
        for(int j = 0; j < this->cols(); j++){
            this->data[i][j] /= x;
        }
    }
    return *this;
}
Matrix Matrix::operator+(const Matrix matrix) const
{
    return Matrix(*this) += matrix;
}
Matrix Matrix::operator-(const Matrix matrix) const
{
    return Matrix(*this) -= matrix;
}
// ループの順番
// P行Q列とQ行R列の積
Matrix Matrix::operator*(Matrix matrix)
{
    Matrix result(this->rows(), matrix.cols());
    for(int i = 0; i < this->rows(); i++){
        for(int j = 0; j < matrix.cols(); j++){
            for(int k = 0; k < this->cols(); k++){
                result.at(i, j) += this->data[i][k] * matrix.at(k, j);
            }
        }
    }
    return result;
}
Matrix Matrix::operator*(const double x) const
{
    return Matrix(*this) *= x;
}
Matrix Matrix::operator/(const double x) const
{
    return Matrix(*this) /= x;
}

// 行数
size_t Matrix::rows()
{
    return data.size();
}

// 第一要素サイズが0の場合はコアダンプする->errorでるようにする
// 列数
size_t Matrix::cols()
{
    return data[0].size();
}

// 要素へのアクセスメソッド
const double &Matrix::at(int row, int col) const
{
    return data[row][col];
}
double &Matrix::at(int row, int col)
{
    return data[row][col];
}

// 単位行列
Matrix Matrix::unit(int rows, int cols)
{
    Matrix vec(rows, cols);
    for(int i = 0; i < rows; i++){
        vec.at(i, i) = 1;
    }
    return vec;
}

// 転置行列
Matrix Matrix::transpose()
{
    Matrix trans_vec(this->rows(), this->cols());
    for(int i = 0; i < trans_vec.rows(); i++){
        for(int j = 0; j < trans_vec.cols(); j++){
            trans_vec.at(j, i) = data[i][j];
        }
    }
    return trans_vec;
}

// 行列式
double Matrix::determinant()
{
    std::vector<std::vector<double>> matrix = data;
    double result = 1.0;

    for(int i = 0; i < this->rows(); i++){
        int max_row = i;
        for(int j = i + 1; j < this->cols(); j++){
            if(std::abs(matrix[j][i]) > std::abs(matrix[max_row][i]))
            {
                max_row = j;
            }
        }

        if(max_row != i)
        {
            std::swap(matrix[i], matrix[max_row]);
            result *= -1;
        }

        result *= matrix[i][i];
        if(result == 0)
        {
            return 0;
        }

        for(int j = i + 1; j < this->cols(); j++){
            double buf = matrix[j][i] / matrix[i][i];
            for(int k = i + 1; k < this->cols(); k++){
                matrix[j][k] -= buf * matrix[i][k];
            }
        }
    }
    return result;
}

// 逆行列
Matrix Matrix::inverse()
{
    std::vector<std::vector<double>> matrix = data;
    Matrix inv_vec = unit(this->rows(), this->cols());

    for(int i = 0; i < this->rows(); i++){
        if(matrix[i][i] == 0)
        {
            int max_row = i;
            for(int j = i + 1; j < this->cols(); j++){
                if(std::abs(matrix[j][i]) > std::abs(matrix[max_row][i]))
                {
                    max_row = j;
                }
            }

            if(max_row != i)
            {
                std::swap(matrix[i], matrix[max_row]);
            }
        }

        double pivot = matrix[i][i];
        for(int j = 0; j < this->cols(); j++){
            matrix[i][j] /= pivot;
            inv_vec.at(i, j) /= pivot;
        }

        for(int j = 0; j < this->cols(); j++){
            if(i != j)
            {
                double buf = matrix[j][i];
                for(int k = 0; k < this->cols(); k++){
                    matrix[j][k] -= matrix[i][k] * buf;
                    inv_vec.at(j, k) -= inv_vec.at(i, k) * buf;
                }
            }
        }
    }

    // -0を0に直す
    for(int i = 0; i < this->rows(); i++){
        for(int j = 0; j < this->cols(); j++){
            if(std::abs(inv_vec.at(i, j)) == 0)
            {
                inv_vec.at(i, j) = 0;
            }
        }
    }
    return inv_vec;
}

std::string Matrix::toString()
{
    std::string ret = "[";
    for(int i = 0, rows = this->rows(); i < rows; i++){
        ret += "[";
        for(int j = 0, cols = this->cols(); j < cols; j++){
            ret += std::to_string(this->at(i, j)) + ", ";
        }
        ret[ret.size() - 2] = ']';
    }
    ret += "]";
    return ret;
}