#include "libs/matrix.h"

void test_swapRows_twoMatricesEqual_matrix1And2AfterReplacingRows1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    3, 4, 3,
                    3, 6, 0
            },
            3, 3
    );
    swapRows(m1, 0, 1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 4, 3,
                    1, 1, 2,
                    3, 6, 0
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_swapColumns_twoMatricesEqual_matrix1And2AfterReplacingColumns1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    3, 4, 3,
                    3, 6, 0
            },
            3, 3
    );
    swapColumns(m1, 0, 1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    4, 3, 3,
                    6, 3, 0
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    3, 4, 3,
                    3, 6, 0
            },
            3, 3
    );

    assert(isSquareMatrix(m1) == 1);

    freeMemMatrix(m1);
}

void test_is_No_SquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    3, 4, 3
            },
            2, 3
    );

    assert(!isSquareMatrix(m1) == 1);

    freeMemMatrix(m1);
}

void test_isEMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3
    );

    assert(isEMatrix(m1) == 1);

    freeMemMatrix(m1);
}

void test_is_No_EMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3
    );

    assert(!isEMatrix(m1) == 1);

    freeMemMatrix(m1);
}

void test_insertionSortRowsMatrixByRowCriteria_getMax() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 4, 3, 6,
                    7, 5, 5, 5, 8,
                    5, 3, 4, 3, 5
            },
            3, 5
    );
    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    5, 3, 4, 3, 5,
                    3, 5, 4, 3, 6,
                    7, 5, 5, 5, 8
            },
            3, 5
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_isSymmetricMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 3, 2,
                    3, 4, 6,
                    2, 6, 0
            },
            3, 3
    );

    assert(isSymmetricMatrix(m1) == 1);

    freeMemMatrix(m1);
}

void test_isSymmetricMatrix_NoSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 3, 2,
                    2, 6, 0
            },
            2, 3
    );

    assert(isSymmetricMatrix(m1) == 0);

    freeMemMatrix(m1);
}

void test_is_No_SymmetricMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 3, 8,
                    3, 4, 6,
                    2, 6, 0
            },
            3, 3
    );

    assert(isSymmetricMatrix(m1) == 0);

    freeMemMatrix(m1);
}

void test_predicate_FunctionsForMatrices() {
    test_isSquareMatrix();
    test_is_No_SquareMatrix();
    test_isEMatrix();
    test_is_No_EMatrix();
    test_isSymmetricMatrix();
    test_isSymmetricMatrix_NoSquareMatrix();
    test_is_No_SymmetricMatrix();
}

void test_transposeSquareMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 3, 8,
                    5, 4, 6,
                    2, 6, 0
            },
            3, 3
    );

    transposeSquareMatrix(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 5, 2,
                    3, 4, 6,
                    8, 6, 0
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_transposeSquareMatrix_false() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 3, 8,
                    5, 4, 6,
                    2, 6, 0
            },
            3, 3
    );

    transposeSquareMatrix(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 3, 8,
                    5, 4, 6,
                    2, 6, 0
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 0);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_getMinValuePos_EqualToi2j1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    8, 3, 8,
                    5, 4, 6,
                    2, 0, 6
            },
            3, 3
    );

    position a;
    a.rowIndex = 2;
    a.colIndex = 1;

    position b = getMinValuePos(m1);

    assert(a.rowIndex == b.rowIndex);
    assert(a.colIndex == b.colIndex);

    freeMemMatrix(m1);
}

void test_getMinValuePos_EqualToi0j0() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1
            },
            3, 3
    );

    position a;
    a.rowIndex = 0;
    a.colIndex = 0;

    position b = getMinValuePos(m1);

    assert(a.rowIndex == b.rowIndex);
    assert(a.colIndex == b.colIndex);

    freeMemMatrix(m1);
}

void test_getMaxValuePos_EqualToi0j2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    6, 3, 8,
                    5, 4, 6,
                    2, 0, 6
            },
            3, 3
    );

    position a;
    a.rowIndex = 0;
    a.colIndex = 2;

    position b = getMaxValuePos(m1);

    assert(a.rowIndex == b.rowIndex);
    assert(a.colIndex == b.colIndex);

    freeMemMatrix(m1);
}

void test_functionsForMatrices() {
    test_swapRows_twoMatricesEqual_matrix1And2AfterReplacingRows1();
    test_swapColumns_twoMatricesEqual_matrix1And2AfterReplacingColumns1();
    test_insertionSortRowsMatrixByRowCriteria_getMax();
    test_transposeSquareMatrix();
    test_transposeSquareMatrix_false();
    test_getMinValuePos_EqualToi2j1();
    test_getMaxValuePos_EqualToi0j2();
    test_getMinValuePos_EqualToi0j0();
}

void test_taskNumber1() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 9, 3,
                    9, 0, 5,
                    3, 5, 3
            },
            3, 3
    );

    position minIndex = getMinValuePos(m1);
    position maxIndex = getMaxValuePos(m1);
    swapRows(m1, minIndex.rowIndex, maxIndex.rowIndex);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    9, 0, 5,
                    1, 9, 3,
                    3, 5, 3
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_taskNumber2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3
            },
            3, 3
    );

    sortRowsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2));
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_taskNumber3() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3
            },
            3, 6
    );

    sortColsByMinElement(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    5, 2, 3, 3, 3, 4,
                    5, 1, 2, 2, 7, 8,
                    1, 4, 6, 8, 3, 4
            },
            3, 6
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_taskNumber4_one() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2,
                    5, 5, 1,
                    2, 1, 2
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    38, 42, 15,
                    42, 51, 17,
                    15, 17, 9
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_taskNumber4_two_NoSymmetric() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 3,
                    5, 5, 1,
                    2, 1, 2
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m1);

    assert(isSymmetricMatrix(m1) == 0);

    freeMemMatrix(m1);
}

void test_tasks_1_4() {
    test_taskNumber1();
    test_taskNumber2();
    test_taskNumber3();
    test_taskNumber4_one();
    test_taskNumber4_two_NoSymmetric();
}

void test_taskNumber5_one() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    3, 4, 3,
                    3, 6, 0
            },
            3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 3, 3,
                    1, 4, 6,
                    2, 3, 0
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_taskNumber5_two() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    3, 4, 3,
                    3, 6, 1
            },
            3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    3, 4, 3,
                    3, 6, 1
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_taskNumber6() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, -5,
                    1, -2
            },
            2, 2
    );

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    2, -5,
                    1, -3
            },
            2, 2
    );

    assert(isMutuallyInverseMatrices(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_taskNumber7_one() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            },
            3, 4
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 20);

    freeMemMatrix(m1);
}

void test_taskNumber7_two() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    10, 2, 10, 10,
                    10, 3, 10, 3,
                    10, 2, 10, 2
            },
            3, 4
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 50);

    freeMemMatrix(m1);
}

void test_taskNumber8_MaxInTheMiddle() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2
            },
            3, 4
    );

    assert(getMinInArea(m1) == 5);

    freeMemMatrix(m1);
}

void test_taskNumber8_MaxOnTheLeftEdge() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    12, 1, 1, 2
            },
            3, 4
    );

    assert(getMinInArea(m1) == 3);

    freeMemMatrix(m1);
}


void test_taskNumber8_MaxInTheFirstRow() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 7, 12, 6,
                    3, 11, 8, 9,
                    2, 1, 1, 2
            },
            3, 4
    );

    assert(getMinInArea(m1) == 12);

    freeMemMatrix(m1);
}

void test_tasks_5_8() {
    test_taskNumber5_one();
    test_taskNumber5_two();
    test_taskNumber6();
    test_taskNumber7_one();
    test_taskNumber7_two();
    test_taskNumber8_MaxInTheMiddle();
    test_taskNumber8_MaxOnTheLeftEdge();
    test_taskNumber8_MaxInTheFirstRow();
}

float getDistance(int *a, int n) {
    float distance = 0;

    for (int i = 0; i < n; i++)
        distance += (float) (a[i] * a[i]);

    return sqrtf(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                           float (*criteria)(int *, int)) {
    float arrayRowsCriteria[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        arrayRowsCriteria[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        int j = i;
        float a = arrayRowsCriteria[i];
        while (j > 0 && arrayRowsCriteria[j - 1] > a) {
            swapUniversal(&arrayRowsCriteria[j - 1], &arrayRowsCriteria[j], sizeof(float));
            swapRows(m, j, j - 1);
            j--;
        }
        arrayRowsCriteria[j] = a;
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

void test_taskNumber9_one() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 6,
                    4, 5, 2,
                    1, 9, 0,
                    3, 2, 1
            },
            4, 3);

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 1,
                    4, 5, 2,
                    3, 5, 6,
                    1, 9, 0
            },
            4, 3);

    assert(twoMatricesEqual(m1, m2));
}

void test_taskNumber9_two() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
            },
            4, 2
    );

    sortByDistances(m1);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 3,
                    5, 4,
                    7, 1,
                    2, 7
            },
            4, 2);

    assert(twoMatricesEqual(m1, m2));
}

int cmp_long_long(const void *a, const void *b) {
    long long arg1 = *(const long long *) a;
    long long arg2 = *(const long long *) b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

// Возвращает количество уникальных элементов
// в массиве a, размера n
int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);

    int countUnique = 1;
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            countUnique++;

    return countUnique;
}

// Возвращает количество классов эквивалентных строк
// матрицы m (Строки считать эквивалентными,
// если равны суммы их элементов)
int countEqClassesByRowsSum(matrix m) {
    long long arrayEqualClasses[m.nRows];

    for (int i = 0; i < m.nRows; i++)
        arrayEqualClasses[i] = getSum(m.values[i], m.nCols);

    return countNUnique(arrayEqualClasses, m.nRows);
}

void test_taskNumber10() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
                    1, 6,
                    8, 0
            },
            6, 2
    );

    assert(countEqClassesByRowsSum(m1) == 3);

    freeMemMatrix(m1);
}

void test_taskNumber10_SumOfAllRowsIsDifferent() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 3,
                    2, 7, 4,
                    5, 4, 9,
                    4, 3, 0
            },
            4, 3
    );

    assert(countEqClassesByRowsSum(m1) == 4);

    freeMemMatrix(m1);
}

void test_taskNumber10_SumOfAllRowsIsTheSame() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 3,
                    2, 8, 1,
                    5, 4, 2,
                    2, 9, 0
            },
            4, 3
    );

    assert(countEqClassesByRowsSum(m1) == 1);

    freeMemMatrix(m1);
}

// Возвращает количество "особых" элементов матрицы m, считая элемент
// "особым", если он больше суммы остальных элементов своего столбца
int getNSpecialElement(matrix m) {
    int numberSpecial = 0;
    for (int j = 0; j < m.nCols; j++) {
        int specialElement = m.values[0][j];
        int sumInTheColumn = 0;
        for (int i = 1; i < m.nRows; i++) {
            if (m.values[i][j] > specialElement) {
                sumInTheColumn += specialElement;
                specialElement = m.values[i][j];
            } else
                sumInTheColumn += m.values[i][j];
        }
        if (specialElement > sumInTheColumn)
            numberSpecial++;
    }

    return numberSpecial;
}

void test_taskNumber11() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2
            },
            3, 4
    );

    assert(getNSpecialElement(m1) == 2);

    freeMemMatrix(m1);
}

void test_taskNumber11_thereAreNoSpecialElements() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 6,
                    3, 2, 1, 2
            },
            3, 4
    );

    assert(getNSpecialElement(m1) == 0);

    freeMemMatrix(m1);
}

// Заменяет предпоследнюю строку матрицы m размера n первым из
// столбцов, в котором находится минимальный элемент матрицы m
void swapPenultimateRow(matrix m, int n) {
    position min = getMinValuePos(m);
    int penultimateLine[m.nCols];

    for (int i = 0; i < m.nRows; i++)
        penultimateLine[i] = m.values[i][min.colIndex];

    for (int j = 0, indexArray = 0; indexArray < m.nCols; j++, indexArray++) {
        m.values[n - 2][j] = penultimateLine[indexArray];
    }
}

void test_taskNumber12_severalIdenticalMinimum() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1
            },
            3, 3
    );

    swapPenultimateRow(m1, 3);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1
            },
            3, 3
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_taskNumber12_minInTheThirdColumn() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 1, 4,
                    4, 5, 6, 5,
                    7, 8, 0, 7,
                    9, 3, 5, 1
            },
            4, 4
    );

    swapPenultimateRow(m1, 4);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 1, 4,
                    4, 5, 6, 5,
                    1, 6, 0, 5,
                    9, 3, 5, 1
            },
            4, 4
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_taskNumber12_minInTheLastColumn() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 6, 4,
                    4, 5, 6, 5,
                    7, 8, 2, 0,
                    9, 3, 1, 1
            },
            4, 4
    );

    swapPenultimateRow(m1, 4);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 2, 6, 4,
                    4, 5, 6, 5,
                    4, 5, 0, 1,
                    9, 3, 1, 1
            },
            4, 4
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_taskNumber12_size2x2() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2,
                    1, 1
            },
            2, 2
    );

    swapPenultimateRow(m1, 2);

    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 1,
                    1, 1
            },
            2, 2
    );

    assert(twoMatricesEqual(m1, m2) == 1);

    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

void test_tasks_9_12() {
    test_taskNumber9_one();
    test_taskNumber9_two();
    test_taskNumber10();
    test_taskNumber10_SumOfAllRowsIsDifferent();
    test_taskNumber10_SumOfAllRowsIsTheSame();
    test_taskNumber11();
    test_taskNumber11_thereAreNoSpecialElements();
    test_taskNumber12_severalIdenticalMinimum();
    test_taskNumber12_minInTheThirdColumn();
    test_taskNumber12_minInTheLastColumn();
    test_taskNumber12_size2x2();
}

// Возвращает 'истина', если массив a размера n отсортирован
// по не убыванию, в обратном случае вернуть 'ложь'
bool isNonDescendingSorted(const int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

// Возвращает 'истина', если в матрице m ряды отсортированы
// по не убыванию, в обратном случае вернуть 'ложь'
bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (isNonDescendingSorted(m.values[i], m.nCols) == 0)
            return false;
    return true;
}

// Возвращает матрицы ms, изначальное количество матриц nMatrix,
// имеющие наибольшее число нулевых строк
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int countNonDescendingRows = 0;
    for (int i = 0; i < nMatrix; i++) {
        if (hasAllNonDescendingRows(ms[i]))
            countNonDescendingRows++;
    }
    return countNonDescendingRows;
}

void test_taskNumber13_countOfNonDescIs2() {
    matrix *m1 = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9,
            },
            4,
            2, 2
    );

    assert(countNonDescendingRowsMatrices(m1, 4) == 2);

    freeMemMatrices(m1, 4);
}


void test_taskNumber13_countOfNonDescIs3() {
    matrix *m1 = createArrayOfMatrixFromArray(
            (int[]) {
                    1, 1, 5,
                    1, 1, 8,
                    4, 6, 7,

                    1, 6, 8,
                    2, 2, 4,
                    2, 5, 7,

                    5, 4, 2,
                    2, 3, 6,
                    3, 6, 8,

                    1, 3, 3,
                    7, 9, 9,
                    2, 4, 5
            },
            4,
            3, 3
    );

    assert(countNonDescendingRowsMatrices(m1, 4) == 3);

    freeMemMatrices(m1, 4);
}

void test_taskNumber13_countOfNonDescIs1() {
    matrix *m1 = createArrayOfMatrixFromArray(
            (int[]) {
                    1, 1, 1,
                    1, 1, 1,
                    1, 1, 1,

                    7, 6, 8,
                    2, 2, 4,
                    2, 5, 7,

                    5, 4, 2,
                    2, 3, 6,
                    3, 6, 8,

                    9, 3, 3,
                    7, 9, 9,
                    2, 4, 5
            },
            4,
            3, 3
    );

    assert(countNonDescendingRowsMatrices(m1, 4) == 1);

    freeMemMatrices(m1, 4);
}

void test_taskNumber13_theAreNoNonDescRowsMatrices() {
    matrix *m = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    4, 2,

                    5, 4,
                    2, 3,

                    5, 3,
                    7, 9,
            },
            4,
            2, 2
    );

    assert(countNonDescendingRowsMatrices(m, 4) == 0);

    freeMemMatrices(m, 4);
}

// Возвращает количество чисел массива a размера n,
// значение которых равно values
int countValues(const int *a, int n, int value) {
    int countNumbersEqualToValues = 0;

    for (int i = 0; i < n; i++)
        if (a[i] == value)
            countNumbersEqualToValues++;

    return countNumbersEqualToValues;
}

// Возвращает количество рядов матрицы m,
// в которых все числа равны нулю
int countZeroRows(matrix m) {
    int countZeroRowsInMatrix = 0;

    for (int i = 0; i < m.nRows; i++)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            countZeroRowsInMatrix++;

    return countZeroRowsInMatrix;
}

// Выводит матрицы ms, имеющие наибольшее число нулевых строк
// изначальное количество матриц nMatrix
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int *arrayIndexCountZeroRows = (int *) malloc(sizeof(int) * nMatrix);

    for (int i = 0; i < nMatrix; i++)
        arrayIndexCountZeroRows[i] = countZeroRows(ms[i]);

    int maxInArray = getMax(arrayIndexCountZeroRows, nMatrix);

    for (int i = 0; i < nMatrix; i++)
        if (maxInArray == 0) {
            printf("there are no matrices with zero rows");
            break;
        } else if (arrayIndexCountZeroRows[i] == maxInArray) {
            outputMatrix(ms[i]);
            printf("\n");
        }

    free(arrayIndexCountZeroRows);
}

void test_taskNumber14_functionCountZeroRows_3() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    7, 1, 4,
                    0, 0, 0,
                    5, 4, 8,
                    0, 0, 0,
                    0, 6, 1,
                    0, 0, 0
            },
            6, 3
    );

    assert(countZeroRows(m1) == 3);

    freeMemMatrix(m1);
}

void test_taskNumber14_functionCountZeroRows_0() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 6, 1,
                    0, 3, 0
            },
            3, 3
    );

    assert(countZeroRows(m1) == 0);

    freeMemMatrix(m1);
}

// Возвращает минимальное по модулю значение матрицы m
int getMinModuloValueInMatrix(matrix m) {
    int minValue = abs(m.values[0][0]);

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (abs(m.values[i][j]) < minValue)
                minValue = abs(m.values[i][j]);

    return minValue;
}

// Выводит матрицы ms с наименьшей нормой, изначальное количество матриц nMatrix.
// В качестве нормы матрицы взять максимум абсолютных величин её элементов
void printMatrixWithMinModule(matrix *ms, int nMatrix) {
    int *arrayIndexMinModule = (int *) malloc(sizeof(int) * nMatrix);

    for (int i = 0; i < nMatrix; i++)
        arrayIndexMinModule[i] = getMinModuloValueInMatrix(ms[i]);

    int minInArray = getMin(arrayIndexMinModule, nMatrix);

    for (int i = 0; i < nMatrix; i++)
        if (arrayIndexMinModule[i] == minInArray) {
            outputMatrix(ms[i]);
            printf("\n");
        }

    free(arrayIndexMinModule);
}

void test_taskNumber15_function_getMinModuloValueInMatrix() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    10, -3, 3,
                    30, -60, 10,
                    80, -80, 5
            },
            3, 3
    );

    assert(getMinModuloValueInMatrix(m1) == 3);

    freeMemMatrix(m1);
}

void test_taskNumber15_function_getMinModuloValueInMatrix_two() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    0, -80, -20,
                    0, -60, 0,
                    -80, 0, -20,
                    -90, 2, 30
            },
            4, 3
    );

    assert(getMinModuloValueInMatrix(m1) == 0);

    freeMemMatrix(m1);
}

void test_tasks_13_15() {
    test_taskNumber13_countOfNonDescIs2();
    test_taskNumber13_countOfNonDescIs3();
    test_taskNumber13_theAreNoNonDescRowsMatrices();
    test_taskNumber13_countOfNonDescIs1();
    test_taskNumber14_functionCountZeroRows_3();
    test_taskNumber14_functionCountZeroRows_0();
    test_taskNumber15_function_getMinModuloValueInMatrix();
    test_taskNumber15_function_getMinModuloValueInMatrix_two();
}

void test_allTasks() {
    test_tasks_1_4();
    test_tasks_5_8();
    test_tasks_9_12();
    test_tasks_13_15();
}

void test() {
    test_functionsForMatrices();
    test_predicate_FunctionsForMatrices();
    test_allTasks();
}

int main() {
    test();

    return 0;
}
