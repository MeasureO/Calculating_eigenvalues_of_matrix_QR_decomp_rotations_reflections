#pragma once
#include <iostream>
#include <cmath>
#include "matrix.h"

double vector_norm(std::vector<double> &v)
{
    double s = 0;
    for (int i = 0; i < v.size(); i++)
    {
        s += v[i] * v[i];
    }

    s = sqrt(s);
    return s;
}

Matrix with_reflections_to_quasi_triangular(Matrix matrix, int size)
{
    for (int k = 1; k < size; k++)
    {
        // std::vector<double> x_k(size - k - 1);
        // for(int i = 0; i < x_k.size(); i++)
        // {
        //     x_k[i] =
        // }
        std::vector<double> x(size - k);
        std::vector<double> a(size - k);
        for (int i = k; i < size; i++)
        {
            a[i] = matrix(i, k - 1);
            printf("%10.3e", a[i]);
            printf(" ");
        }
        printf("norm: ");
        printf("%10.3e", vector_norm(a));
        for (int i = 0; i < size - k; i++)
        {
            if (i == 0)
            {

                x[i] = a[i]; // - vector_norm(a, size - k);
            }
            else
            {
                x[i] = a[i]; // - vector_norm(a) * 0;
            }
        }
        x.clear();
        x.shrink_to_fit();
        a.clear();
        a.shrink_to_fit();
        printf("\n");
    }
    // double x_norm = vector_norm(x);
    // for (int i = 0; i < size - k; i++)
    // {
    //     x[i] = x[i] / x_norm;
    //     printf("%10.3e", x[i]);
    //     printf(" ");
    // }

    return matrix;
}
