#include "libs/matrix.h"

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix c = mulMatrices(m1, m2);
    if (isEMatrix(c))
        return true;
    else
        return false;
}

int main() {
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

    printf("%d", isMutuallyInverseMatrices(m1, m2));

    return 0;
}
