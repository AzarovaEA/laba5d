#include "libs/matrix.h"

void taskNumber1(matrix m){
    position minIndex = getMinValuePos(m);
    position maxIndex = getMaxValuePos(m);
    swapRows(m, minIndex.rowIndex, maxIndex.rowIndex);
}

int main() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 9, 3,
                    9, 0, 5,
                    3, 5, 3,
            },
            3, 3
    );

    taskNumber1(m1);

    outputMatrix(m1);

    return 0;
}
