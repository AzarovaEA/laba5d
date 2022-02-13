//
// Created by User on 13.02.2022.
//

#ifndef LABA5D_MATRIX_H
#define LABA5D_MATRIX_H

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows;    // количество рядов
    int nCols;    // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

matrix getMemMatrix(int nRows, int nCols);

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

#endif //LABA5D_MATRIX_H
