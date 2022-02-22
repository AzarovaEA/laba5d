#ifndef LABA5D_MATRIX_H
#define LABA5D_MATRIX_H

#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <malloc.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows;    // количество рядов
    int nCols;    // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// размещает в динамической памяти матрицу
// размером nRows на nCols. Возвращает матрицу
matrix getMemMatrix(int nRows, int nCols);

// размещает в динамической памяти массив
// из nMatrices матриц размером nRows на nCols.
// Возвращает указатель на нулевую матрицу.
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// освобождает память, выделенную под
// хранение матрицы m
void freeMemMatrix(matrix m );

// освобождает память, выделенную под
// хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices);

// ввод матрицы m
void inputMatrix(matrix m);

// ввод массива из nMatrices матриц,
// хранящейся по адресу ms
void inputMatrices(matrix *ms, int nMatrices);

// вывод матрицы m
void outputMatrix(matrix m);

// вывод массива из nMatrices матриц,
// хранящейся по адресу ms
void outputMatrices(matrix *ms, int nMatrices);

// обмен строк с порядковыми
// номерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2);

// обмен колонок с порядковыми
// номерами j1 и j2 в матрице m
void swapColumns(matrix m, int j1, int j2);

// возвращает значение ’истина’, если
// матрица m является квадратной,
// ложь – в противном случае
bool isSquareMatrix(matrix m);

// возвращает значение ’истина’, если матрицы
// m1 и m2 равны, ложь – в противном случае
bool twoMatricesEqual(matrix m1, matrix m2);

// возвращает значение ’истина’, если матрица
// m является единичной, ложь – в противном случае
bool isEMatrix(matrix m);

// Обмен значений двух переменных по адресам a и b размера size
void swapUniversal(void *a, void *b, size_t size);

// выполняет сортировку вставками строк матрицы m
// по неубыванию значения функции criteria
// применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int));

// выполняет сортировку вставками
// столбцов матрицы m по неубыванию значения
// функции criteria применяемой для столбцов
void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, int));

// возвращает значение ’истина’, если
//матрица m является симметричной,
// ложь – в противном случае
bool isSymmetricMatrix(matrix m);

// транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix m);

// возвращает позицию минимального элемента матрицы m
position getMinValuePos(matrix m);

// возвращает позицию максимального элемента матрицы m
position getMaxValuePos(matrix m);

// возвращает матрицу, размера nRows на nCols, построенного
// из элементов массива a, размещенную в динамической памяти
matrix createMatrixFromArray(const int *a, int nRows , int nCols);

// возвращает указатель на нулевую матрицу массива
// из nMatrices матриц, размещенных в динамической памяти,
// построенных из элементов массива a
matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices, int nRows, int nCols);

// Возвращает минимальный элемент массива а, размера n
int getMin(int *a, int n);

// Упорядочивает столбцы матрицы по неубыванию
// минимальных элементов столбцов
void sortColsByMinElement(matrix m);

// Возвращает максимальный элемент массива а, размера n
int getMax(int *a, int n);

// Упорядочивает строки матрицы m по неубыванию
// наибольших элементов строк
void sortRowsByMinElement(matrix m);

// Произведение двух матриц m1 и m2
matrix mulMatrices(matrix m1, matrix m2);

// Если данная квадратная матрица m симметрична,
// то заменяет m ее квадратом
void getSquareOfMatrixIfSymmetric(matrix *m);

// Если две матрицы m1 и m2 взаимно обратны,
// то вернуть 'истина', иначе - 'ложь'
bool isMutuallyInverseMatrices(matrix m1, matrix m2);

// Если все элементы массива a, размера n различны,
// то вернуть 'истина', иначе - 'ложь'
bool isUnique(long long *a, int n);

// Возвращает сумму элементов массива a, размера n
long long getSum(int *a, int n);

// Транспонирует матрицу, если среди сумм элементов
// строк матрицы m нет равных
void transposeIfMatrixHasNotEqualSumOfRows(matrix m);

// Возвращает сумму максимальных элементов
// всех псевдодиагоналей матрицы m
long long findSumOfMaxesOfPseudoDiagonal(matrix m);

// Возвращает минимальный элемент матрицы m, в области от максимального
// элемента с расширением границ при подъеме на один ряд,
// если максимальный элемент в верхнем ряду - вернуть максимум
int getMinInArea(matrix m);

#endif //LABA5D_MATRIX_H
