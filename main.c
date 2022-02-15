#include "libs/matrix.h"

matrix mulMatrices(matrix m1, matrix m2) {
    matrix c= getMemMatrix(m1.nRows, m1.nCols);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            c.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++)
                c.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }
    }
    return (matrix)c;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2,
                    5, 5, 1,
                    2, 1, 2
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m1);

    outputMatrix(m1);

    return 0;
}
