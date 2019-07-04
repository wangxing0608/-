//
// Created by wangxing on 19-7-3.
//

// 1.7 原地旋转二维矩阵
// 给定一个NxN矩阵,矩阵每个元素为4bytes,对该执行矩阵旋转90度的操作


#include <iostream>
#include <jmorecfg.h>

// 矩阵转置
void helper_transpose(int **matrix, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i != j)
                std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}

// 翻转行向量
void helper_reverse(int *row, int N)
{
    for (int i = 0; i < N/2; i++)
    {
        std::swap(row[i], row[N-i-1]);
    }
}

// 方法1：先转置矩阵,再翻转矩阵中的每一行
void rotateMatrix1(int **matrix, int N)
{
    // 转置矩阵
    helper_transpose(matrix, N);
    // 翻转矩阵中的每一行
    for (int i = 0; i < N; i++)
    {
        helper_reverse(matrix[i], N);
    }

}

// 方法2: 逐个交换矩阵中每一对元素
void rotateMatrix2(int **matrix, int N)
{
    for (int i = 0; i < N/2; i++)
    {
        for (int j = i; j < N-i-1; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][N-i-1];
            matrix[j][N-i-1] = matrix[N-i-1][j-i-1];
            matrix[N-i-1][N-j-1] = matrix[N-j-1][i];
            matrix[N-j-1][i] = temp;
        }
    }
}

// 显示矩阵
void printMatrix(int **matrix, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << matrix[i][j] <<" ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int N;
    std::cout<< "Enter N for NxN matrix:";
    std::cin >> N;
    int ** matrix = new int *[N];
    for (int i = 0; i < N; i++)
    {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    std::cout << "Rotated matrix by 90 (clockwise:)\n";
    rotateMatrix1(matrix, N);
    printMatrix(matrix, N);

    std::cout << "Rotated matrix again by 90 (clockwise)\n";
    rotateMatrix2(matrix, N);
    printMatrix(matrix, N);
    return 0;
}


