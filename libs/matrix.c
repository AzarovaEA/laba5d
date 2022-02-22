#include "matrix.h"

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        printf("| ");
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("| \n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
        printf("\n");
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        int t = m.values[i][j1];
        m.values[i][j1] = m.values[i][j2];
        m.values[i][j2] = t;
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    for (int i = 0; i < m1.nRows; i++)
        if (memicmp(m1.values[i], m2.values[i], sizeof(int) * m1.nCols))
            return false;

    return true;
}

bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (i == j && m.values[i][j] != 1)
                return false;
            if (i != j && m.values[i][j] != 0)
                return false;
        }
    }

    return true;
}

void swapUniversal(void *a, void *b, size_t size) {
    char *pa = a;
    char *pb = b;
    for (size_t i = 0; i < size; i++) {
        char t = *pa;
        *pa = *pb;
        *pb = t;
        pa++;
        pb++;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int arrayRowsCriteria[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        arrayRowsCriteria[i] = criteria(m.values[i], m.nCols);

    for (int i = 1; i < m.nRows; i++) {
        int j = i;
        int a = arrayRowsCriteria[i];
        while (j > 0 && arrayRowsCriteria[j - 1] > a) {
            swapUniversal(&arrayRowsCriteria[j - 1], &arrayRowsCriteria[j], sizeof(int));
            swapRows(m, j, j - 1);
            j--;
        }
        arrayRowsCriteria[j] = a;
    }
}

void insertionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int *, int)) {
    int arrayColsCriteria[m.nCols];
    for (int j = 0; j < m.nCols; j++) {
        int arrayColsElement[m.nRows];
        for (int i = 0; i < m.nRows; i++)
            arrayColsElement[i] = m.values[i][j];
        arrayColsCriteria[j] = criteria(arrayColsElement, m.nRows);
    }

    for (int i = 1; i < m.nCols; i++) {
        int j = i;
        int a = arrayColsCriteria[i];
        while (j > 0 && arrayColsCriteria[j - 1] > a) {
            arrayColsCriteria[j] = arrayColsCriteria[j - 1];
            swapColumns(m, j, j - 1);
            j--;
        }
        arrayColsCriteria[j] = a;
    }
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;

    if (m.nRows == 1)
        return true;

    for (int i = 0; i < m.nRows; i++) {
        for (int j = i + 1; j < m.nCols; j++) {
            if (m.values[i][j] != m.values[j][i])
                return false;
        }
    }

    return true;
}

void transposeSquareMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = i + 1; j < m.nCols; j++)
            swapUniversal(&m.values[i][j], &m.values[j][i], sizeof(int));
    }
}

position getMinValuePos(matrix m) {
    int minValue = m.values[0][0];
    position minPos = {0, 0};

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] < minValue) {
                minValue = m.values[i][j];
                minPos.rowIndex = i;
                minPos.colIndex = j;
            }

    }

    return minPos;
}

position getMaxValuePos(matrix m) {
    int maxValue = m.values[0][0];
    position maxPos = {0, 0};

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > maxValue) {
                maxValue = m.values[i][j];
                maxPos.rowIndex = i;
                maxPos.colIndex = j;
            }
    }

    return maxPos;
}

matrix createMatrixFromArray(const int *a, int nRows, int nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values,
                                     int nMatrices, int nRows, int nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);

    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

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

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] < min)
            min = a[i];

    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

matrix mulMatrices(matrix m1, matrix m2) {
    matrix c = getMemMatrix(m1.nRows, m1.nCols);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            c.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++)
                c.values[i][j] += m1.values[i][k] * m2.values[k][j];
        }
    }
    return (matrix) c;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(*m))
        *m = mulMatrices(*m, *m);
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix c = mulMatrices(m1, m2);
    int a = isEMatrix(c);
    freeMemMatrix(c);
    if (a)
        return true;
    else
        return false;
}

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

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int sizeOfPseudoDiagonal = m.nCols + m.nRows - 1;
    int *arrayMaxesOfPseudoDiagonal = (int *) malloc(sizeOfPseudoDiagonal * sizeof(int));
    for (int i = 0; i < sizeOfPseudoDiagonal; i++)
        arrayMaxesOfPseudoDiagonal[i] = INT_MIN;

    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++) {
            int k = j + m.nRows - 1 - i;
            if (m.values[i][j] > arrayMaxesOfPseudoDiagonal[k])
                arrayMaxesOfPseudoDiagonal[k] = m.values[i][j];
        }

    arrayMaxesOfPseudoDiagonal[m.nRows - 1] = 0;

    long long sum = getSum(arrayMaxesOfPseudoDiagonal, sizeOfPseudoDiagonal);
    free(arrayMaxesOfPseudoDiagonal);

    return sum;
}

int getMinInArea(matrix m) {
    position maxValue = getMaxValuePos(m);
    if (maxValue.rowIndex == 0)
        return m.values[maxValue.rowIndex][maxValue.colIndex];

    int minElement = m.values[maxValue.rowIndex][maxValue.colIndex];

    int left, right;
    for (int k = maxValue.rowIndex - 1; k >= 0; k--) {
        left = maxValue.colIndex - 1 >= 0 ? maxValue.colIndex - 1 : maxValue.colIndex;
        right = maxValue.colIndex + 1 < m.nCols ? maxValue.colIndex + 1 : maxValue.colIndex;
        while (left <= right) {
            if (m.values[k][right] < minElement)
                minElement = m.values[k][right];
            right--;
        }
    }

    return minElement;
}



