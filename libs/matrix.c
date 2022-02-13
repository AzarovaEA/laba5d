#include "matrix.h"
#include <stdio.h>
#include "assert.h"

// возвращает размещённую в динамической памяти
// матрицу размером nRows, nCols
matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        printf("| ");
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("| \n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
        printf("\n");
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        int t = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = t;
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

// возвращает значение ’истина’, если матрицы
// m1 и m2 равны, ложь – в противном случае
bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return 0;

    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nRows; j++){
            if (m1.values[i] != m2. values[j])
                return 0;
        }
    }

    return 1;
}

bool isEMatrix(matrix m){
    if (!isSquareMatrix(m))
        return 0;

    for (int i = 0; i < m.nRows; i++){
        for(int j = 0; j< m.nCols; j++){
            if (i == j && m.values[i][j] != 1)
                return 0;
            if (i != j && m.values[i] [j] != 0)
                return 0;
        }
    }

    return 1;
}

