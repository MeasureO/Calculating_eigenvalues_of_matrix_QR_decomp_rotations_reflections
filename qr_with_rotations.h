#pragma once
#include <iostream>
#include <cmath>
#include <vector>
#include "matrix.h"

Matrix qr_rotations(Matrix matrix, int size)
{

    Matrix Q;
    Q = Matrix(size);
    Matrix R;
    R = Matrix(size);
    Matrix T;
    T = Matrix(size);
    double cosa;
    double sina;
    Matrix Ts;
    Ts = Matrix(size);
    to_identity(Ts, size);
    // std::cout << Ts;
    // std::cout << "-------------------------------------------\n";
    for (int j = 0; j < 3; j++)
    {
        matrix = with_reflections_to_quasi_triangular(matrix, size);
        std::cout << "quasi triangular\n";
        // std::cout << matrix;
        print_matrix(matrix, size, size);
        for (int k = 0; k < size - 1; k++)
        {
            std::cout << k + 1 << "step of rotation\n";
            to_identity(T, size);
            double cosa = matrix(k, k) / sqrt(matrix(k, k) * matrix(k, k) + matrix(k + 1, k) * matrix(k + 1, k));
            double sina = -matrix(k + 1, k) / sqrt(matrix(k, k) * matrix(k, k) + matrix(k + 1, k) * matrix(k + 1, k));
            T(k, k) = cosa;
            T(k, k + 1) = -sina;
            T(k + 1, k) = sina;
            T(k + 1, k + 1) = cosa;
            std::cout << "T matrix\n";
            // std::cout << T;
            print_matrix(T, size, size);
            std::cout << "------------------------------------" << std::endl;
            Ts = multiplication(T, Ts, size);
            std::cout << "Ts matrix\n";
            // std::cout << Ts;
            print_matrix(Ts, size, size);
            std::cout << "------------------------------------" << std::endl;
            matrix = multiplication(T, matrix, size);
            std::cout << "A_k\n";
            // std::cout << matrix;
            print_matrix(matrix, size, size);
            std::cout << "------------------------------------" << std::endl;
        }
        Q = transpose(Ts, size);
        R = matrix;
        matrix = multiplication(R, Q, size);
        std::cout << "A_(k+1)\n";
        // std::cout << matrix;
        print_matrix(matrix, size, size);
        std::cout << "------------------------------------" << std::endl;
    }
    std::cout << "**************************************************************\n";
    std::cout << matrix;
}
