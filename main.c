#include <stdio.h>
#include "libs/matrix.h"

int main() {
    matrix *m = getMemArrayOfMatrices(2, 3, 2);

    inputMatrices(m, 2);

    outputMatrices(m, 2);

    freeMemMatrices(m, 2);

    return 0;
}
