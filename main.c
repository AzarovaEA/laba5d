#include <stdio.h>
#include "libs/matrix.h"
#include "assert.h"

int main() {
    matrix m1 = getMemMatrix(3,3);

    inputMatrix(m1);

    printf("%d", isEMatrix(m1));

    return 0;
}
