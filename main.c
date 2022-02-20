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
}

void test_functionsForMatrices() {
    test_swapRows_twoMatricesEqual_matrix1And2AfterReplacingRows1();
    test_swapColumns_twoMatricesEqual_matrix1And2AfterReplacingColumns1();
    test_insertionSortRowsMatrixByRowCriteria_getMax();
    test_transposeSquareMatrix();
    test_transposeSquareMatrix_false();
    test_getMinValuePos_EqualToi2j1();
    test_getMaxValuePos_EqualToi0j2();
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
}

void test_taskNumber7() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            },
            3, 4
    );

    assert(findSumOfMaxesOfPseudoDiagonal(m1) == 20);
}

void test_tasks() {
    test_taskNumber1();
    test_taskNumber2();
    test_taskNumber3();
    test_taskNumber4_one();
    test_taskNumber4_two_NoSymmetric();
    test_taskNumber5_one();
    test_taskNumber5_two();
    test_taskNumber6();
    test_taskNumber7();
}

void test() {
    test_functionsForMatrices();
    test_predicate_FunctionsForMatrices();
    test_tasks();
}

int main() {
    test();

    return 0;
}
