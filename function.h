#pragma once
#include <algorithm>
#include <cmath>
double func(int k, int n, int i, int j)
{
    if (k == 1)
    {
        return n - std::max(i, j) + 1;
    }
    if (k == 2)
    {
        return std::max(i, j);
    }
    if (k == 3)
    {
        return std::abs(i - j);
    }
    if (k == 4)
    {
        return 1.0 / (i + j - 1);
    }
    throw std::invalid_argument("Некорректное значение аргумента k!");
}