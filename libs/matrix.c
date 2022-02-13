//
// Created by User on 13.02.2022.
//

#include "matrix.h"

// возвращает размещённую в динамической памяти
// матрицу размером nRows, nCols
matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof (matrix)* nMatrices);
    for ( int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

//void freeMemMatrix(matrix m ) {
//
//}