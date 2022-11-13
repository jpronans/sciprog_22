// Checks if a matrix is a magic square.
// A magic square is an n-sided matrix whose sum of values for each
// row, column, main and secondary diagonals equals to n(n^2 + 1)/2.
// The function takes as input a matrix 'square' and its side length 'n'
// and outputs 0 if 'n' is negative or 'square' is NOT a magic square;
// otherwise, outputs a non-zero value
#include <time.h>
#undef MYTIMER

int isMagicSquare(int ** square, const int n) {

    // Eliminate the case where 'n' is negative
    if(n < 0) {
        return 0;
    }

#ifdef MYTIMER
    time_t tst, tend;
    clock_t cst, cend;
    tst= time(0);
    cst= clock();
    int count=0;
    for(count=0; count<1000000000; count++){
#endif
    // M is the sum of every row, column,
    // and the main and secondary diagonals
    int M = (n * (n*n + 1))/2;

    int i, j;
    // Checking that every row and column add up to M
    for(i = 0; i < n; i++) {
        int rowSum = 0;
        int colSum = 0;
        for(j = 0; j < n; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if(rowSum != M || colSum != M) {
            return 0;
        }
    }

    // Checking that the main and secondary
    // diagonals each add up to M
    int diagSum = 0;
    int secDiagSum = 0;
    for(i = 0; i < n; i++) {
        diagSum += square[i][i];
        secDiagSum += square[i][n-i-1];
    }
    if(diagSum != M || secDiagSum != M) {
        return 0;
    }
#ifdef MYTIMER
    }

    tend = time(0);
    cend = clock();
    printf("elapsed: %lf\n", difftime(tend, tst));
    printf("elapsed: %ld\n", cend-cst);
#endif
    // If passed all checks, it is a magic square
    return 1;
}

