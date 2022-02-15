#include "libs/matrix.h"

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 1, 3,
                    7, 0, 5,
                    4, 5, 2,
            },
            3, 3
    );

    sortRowsByMinElement(m1);

    outputMatrix(m1);

    return 0;
}
