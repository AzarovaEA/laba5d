#include "libs/matrix.h"

bool isUnique(long long *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i] == a[i - 1])
            return false;

    return true;
}

long long getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long arrayOfAmounts[m.nRows];

    for (int i = 0; i < m.nRows; i++)
        arrayOfAmounts[i] = getSum(m.values[i], m.nCols);

    if (isUnique(arrayOfAmounts, m.nRows))
        transposeSquareMatrix(m);
}

int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 2,
                    3, 4, 3,
                    3, 6, 0
            },
            3, 3
    );

    transposeIfMatrixHasNotEqualSumOfRows(m1);

    outputMatrix(m1);

    return 0;
}
