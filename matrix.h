#pragma once
#include <iostream>
#include <iomanip>
#include <string>
class Matrix
{
private:
    int _size;
    std::vector<double> _data;

public:
    std::vector<double> _b;
    // std::vector<std::string> variables;
    Matrix()
    {
        _size = 0;
    }

    Matrix(int size)
    {
        _size = size;
        _data.resize(size * size);
        _b.resize(size);
        // variables.resize(size);
        // for (int i = 0; i < size; i++)
        // {
        //     //variables[i] = std::to_string(i + 1);
        //     variables[i] = std::to_string(i + 1);
        // }
    }

    friend std::istream &operator>>(std::istream &is, Matrix &mt);
    friend std::ostream &operator<<(std::ostream &os, const Matrix &mt);

    const int getSize()
    {
        return _size;
    }
    double &operator()(int row, int col)
    {
        return _data[row * _size + col];
    }

    double operator()(int row, int col) const
    {
        return _data[row * _size + col];
    }
    // double& operator()(int row)
    // {
    //     double s = 0;
    //     for(int j = 0; j < _size; j += 2){
    //         s += _data[row * _size + j];
    //     }
    //     return s;
    // }

    // double operator()(int row) const
    // {
    //     double s = 0;
    //     for(int j = 0; j < _size; j += 2){
    //         s += _data[row * _size + j];
    //     }
    //     return s;
    // }
    void colSwap(int col1, int col2)
    {
        for (int i = 0; i < _size; i++)
        {
            std::swap(_data[i * _size + col1], _data[i * _size + col2]);
        }
    }
    void rowSwap(int row1, int row2, int submatrix_size)
    {
        std::swap_ranges(_data.begin() + row1 * _size + _size - submatrix_size,
                         _data.begin() + row1 * _size + _size,
                         _data.begin() + row2 * _size + _size - submatrix_size);
    }
    void bSwap(int row1, int row2)
    {
        std::swap(_b[row1], _b[row2]);
    }
    // void row_minus_row(int row1, int row2, int submatrix_size)
    // {
    //     std::swap_ranges(_data.begin() + row1 * _size + _size - submatrix_size,
    //                      _data.begin() + row1 * _size + _size,
    //                      _data.begin() + row2 * _size + _size - submatrix_size);
    // }
    std::pair<int, int> maxElem(int submatrix_size)
    {
        int i_max = 0;
        int j_max = 0;
        double current_max = 0;
        for (int i = _size - submatrix_size; i < _size; i++)
        {
            for (int j = _size - submatrix_size; j < _size; j++)
            {
                if (std::abs(_data[i * _size + j]) > std::abs(current_max))
                {
                    current_max = _data[i * _size + j];
                    i_max = i;
                    j_max = j;
                }
            }
        }
        return std::make_pair(i_max, j_max);
    }
    // int get_b(int i){
    //     int s = 0;
    //     for(int j = 0; j <= _size; j += 2){
    //         s += _data[i * _size + j];
    //     }
    //     return s;
    // }
};

std::istream &operator>>(std::istream &is, Matrix &mt)
{
    for (int i = 0; i < mt._size * mt._size; i++)
    {
        is >> mt._data[i];
    }
    for (int i = 0; i < mt._size; i++)
    {
        for (int j = 0; j < mt._size; j += 2)
        {
            mt._b[i] += mt._data[i * mt._size + j];
        }
    }
    return is;
}
std::ostream &operator<<(std::ostream &os, const Matrix &mt)
{
    // for (int i = 0; i < mt._size; i++)
    // {
    //     os << std::setw(10) << 'x' << mt.variables[i] << " ";
    // }
    // os << std::setw(10) << 'b' << std::endl;
    for (int i = 0; i < mt._size; i++)
    {
        for (int j = 0; j < mt._size; j++)
        {
            os << std::setw(10) << mt._data[i * mt._size + j] << " ";
        }
        os << std::setw(10) << mt._b[i] << std::endl;
        // os << mt(i);
    }
    return os;
}