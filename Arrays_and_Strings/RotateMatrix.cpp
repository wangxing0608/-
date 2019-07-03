//
// Created by wangxing on 19-7-3.
//

// 1.7 旋转二维矩阵
// 给定一个NxN矩阵,矩阵每个元素为4bytes,对该执行矩阵旋转90度的操作


#include <iostream>

void helper_transpose(int **matrix, int N){
    for (int i=0;i<N;i++){
        for (int j=i+1;j<N;++j){
            if (i!=j) {
                std::swap(matrix[i][j], matrix[j][i])
            }
        }
    }
}

void helper_reverse(int *row, int N){
    for (int i=0;i<N/2;++i){
        std::swap(row[i], row[N-i-1])
    }
}


