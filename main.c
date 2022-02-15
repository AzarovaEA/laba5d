#include "libs/matrix.h"

void test_isSymmetricMatrix1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 0, 5,
                    3, 5, 3,
            },
            3, 3
    );

    assert (isSymmetricMatrix(m) == 1);

    freeMemMatrix(m);
}

void test_isSymmetricMatrix2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    9, 0, 5,
                    3, 5, 3,
            },
            3, 3
    );

    assert (isSymmetricMatrix(m) == 0);

    freeMemMatrix(m);
}

void test() {
    test_isSymmetricMatrix1();
    test_isSymmetricMatrix2();
}

int main() {
    test();

    return 0;
}
