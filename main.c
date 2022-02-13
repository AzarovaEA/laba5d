#include <stdio.h>
#include "libs/matrix.h"

int main() {
    matrix m = getMemMatrix(2,3);

    inputMatrix(m);
    outputMatrix(m);
    printf("\n");

    swapRows(m, 0, 1);
    swapColumns(m, 2, 1);

    outputMatrix(m);

    return 0;
}
