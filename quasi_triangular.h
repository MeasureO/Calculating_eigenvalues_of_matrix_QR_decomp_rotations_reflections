#pragma once
#include <iostream>
#include <cmath>
#include "matrix.h"

double vector_norm(std::vector<double> v)
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
    Matrix U;
    U = Matrix(size);

    for (int k = 1; k < size - 1; k++)
    {
        std::vector<double> x;
        std::vector<double> a;
        // std::vector<double> x_k(size - k - 1);
        // for(int i = 0; i < x_k.size(); i++)
        // {
        //     x_k[i] =
        // }
        // x.resize(size - k);
        // a.resize(size - k);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                {
                    U(i, j) = 1;
                }
                else
                {
                    U(i, j) = 0;
                }
            }
        }
        for (int i = k; i < size; i++)
        {
            a.push_back(matrix(i, k - 1));
        }
        for (int i = 0; i < size - k; i++)
        {
            printf("%10.3e", a[i]);
            printf(" ");
        }
        printf("norm: ");
        printf("%10.3e", vector_norm(a));
        if (k != size - 1)
        {
            for (int i = 0; i < size - k; i++)
            {
                if (i == 0)
                {

                    x.push_back(a[i] - vector_norm(a) * 1);
                }
                else
                {
                    x.push_back(a[i] - vector_norm(a) * 0);
                }
            }
        }
        // else
        // {
        //     x.push_back(1);
        // }
        printf("\n");

        double x_norm = vector_norm(x);
        for (int i = 0; i < size - k; i++)
        {
            x[i] = x[i] / x_norm;
        }
        for (int i = 0; i < size - k; i++)
        {
            printf("%10.3e", x[i]);
        }
        printf("\n\n");

        for (int i = 0; i < size - k; i++)
        {
            for (int j = 0; j < size - k; j++)
            {
                if (i == j)
                {
                    U(i + k, j + k) = 1 - 2 * x[i] * x[j];
                }
                else
                {
                    U(i + k, j + k) = -2 * x[i] * x[j];
                }
            }
        }
        print_matrix(U, size, size);

        printf("---------------------------------------------------\n");
        matrix = multiplication(U, matrix, size);
        print_matrix(matrix, size, size);
        printf("--------------------------------------------\n");
        matrix = multiplication(matrix, U, size);
        print_matrix(matrix, size, size);
        printf("THE END OF STEP\n");
        printf("-----------------------------------------\n");

        x.clear();
        a.clear();
        printf("\n");
    }

    return matrix;
}
