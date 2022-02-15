#include "libs/matrix.h"

int getMin(int *a, int n){
    int min = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] < min)
            min = a[i];

    return min;
}

void sortColsByMinElement(matrix m){
    insertionSortColsMatrixByColCriteria(m, getMin);
}

int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3
            },
            3, 6
    );
    sortColsByMinElement(m1);

    outputMatrix(m1);

    return 0;
}
