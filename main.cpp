#include <iostream>
#include <vector>
#include <iostream>
#include "matrix.h"
#include "function.h"
#include <cmath>
#include <chrono>
using namespace std;

void print_matrix(Matrix matrix, int n, int l)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << printf("%10.3e", matrix(i, j));
        }
        // printf("%10.3e", matrix._b[i]);
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    Matrix matrix;
    if (atoi(argv[3]) == 0)
    {
        freopen(argv[4], "r", stdin); // перенаправить стандартный поток вывода в файл
        matrix = Matrix(atoi(argv[1]));
        std::cin >> matrix;
        fclose(stdin);
    }
    if (atoi(argv[3]) != 0)
    {
        matrix = Matrix(atoi(argv[1]));
        int n = matrix.getSize();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix(i, j) = func(atoi(argv[3]), n, i, j);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j += 2)
            {
                matrix._b[i] += matrix(i, j);
            }
        }
    }
    print_matrix(matrix, atoi(argv[1]), atoi(argv[2]));
    std::vector<double> x;
    x.resize(atoi(argv[1]));
    // freopen("CON","w",stdout);
    //  std::cout << matrix;
    //  std::cout << "----------------------------------------------------------------" << std::endl;
    //  std::cout << "-----------------------" << endl;
    //  matrix.colSwap(1, 2);
    //  std::cout << "After columns 1 and 2 swap: " << endl;
    //  std::cout << matrix;
    //  std::cout << "-----------------------" << endl;
    //  std::cout << "After rows 1 and 2 of right_bottom_submatrix swap: " << endl;
    //  matrix.rowSwap(1, 2, 2);
    //  std::cout << matrix;
    //  std::cout << "-----------------------" << endl;
    //  for (int i = 0; i < atoi(argv[1]); i++)
    //  {
    //      std::cout << "Submatrix max: " << matrix.maxElem(matrix.getSize() - i).first << " " << matrix.maxElem(matrix.getSize() - i).second << endl;
    //  }
    // std::cout << "Submatrix max: " << matrix.maxElem(matrix.getSize()).first << " " << matrix.maxElem(matrix.getSize()).second << endl;
    // std::cout << matrix.getSize();
    for (int i = 0; i < argc; i++)
    {
        cout << "Command line parameter:" << argv[i] << endl;
    }
    // std::chrono::time_point<std::chrono::system_clock> start, end;
    // start = std::chrono::system_clock::now();
    // std::vector<double> solution = jordan_solver(atoi(argv[1]), matrix, matrix._b, x);
    // end = std::chrono::system_clock::now();
    // std::chrono::duration<double> elapsed_seconds = end - start;
    // std::vector<double> exact_solution;
    // exact_solution.resize(atoi(argv[1]));
    // for (int i = 0; i < atoi(argv[1]); i += 2)
    // {
    //     exact_solution[i] = 1;
    // }
    // std::vector<double> residual(atoi(argv[1]));
    // for (int i = 0; i < atoi(argv[1]); i++)
    // {
    //     residual[i] = matrix._b[i];
    // }
    // for (int i = 0; i < atoi(argv[1]); i++)
    // {
    //     for (int j = 0; j < atoi(argv[1]); j++)
    //     {
    //         residual[i] -= matrix(i, j) * solution[j];
    //     }
    // }
    // double b_norm = 0;
    // double residual_norm = 0;
    // for (double x : matrix._b)
    // {
    //     b_norm += x * x;
    // }
    // b_norm = sqrt(b_norm);
    // for (double y : residual)
    // {
    //     residual_norm += y * y;
    // }
    // residual_norm = sqrt(residual_norm);

    // std::cout << "Норма невязки = " << scientific << residual_norm / b_norm << std::endl;
    // std::vector<double> error(atoi(argv[1]));
    // for (int i = 0; i < atoi(argv[1]); i++)
    // {
    //     error[i] = solution[i] - exact_solution[i];
    // }
    // double error_norm = 0;
    // for (double z : error)
    // {
    //     error_norm += z * z;
    // }
    // error_norm = sqrt(error_norm);
    // std::cout << "Норма погрешности = " << scientific << error_norm << std::endl;
    // std::cout << "Время решения системы = " << elapsed_seconds.count() << std::endl;
    // //cout << matrix;
    return 0;
}