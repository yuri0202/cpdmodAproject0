#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


/*
 *
 * The program calculates the sum of n randomly generated numbers and shows The algorithm's execution time
 * and its Sp calculated as T(n) / D .. fix
 *
 * argv[1] = n : n numbers to sum
 * argv[2] = maxRandValue : The max integer value for the random number to generate
 *
 * If argv[1] and argv[2] are not supplied, n will be equals to 1000000 and
 * maxRandValue will be equals to 1000
 *
 *
 * The algorithm T(n) = n-1 (Sum of n numbers)
 *
 *
 */
int main(int argc, char* argv[]) {
    /* Variables definition*/
    int n=0, maxRandValue=0;
    long sum = 0;
    int i = 0;
    struct timeval startTime,startFinish;
    long int duration;
    int *numToSum;


    /* Checks argument supplied */
    if(argc > 3) {
        printf("Too many arguments provided");
        exit;
    }
    else if (argc==1) {
        n = 1000000;
        maxRandValue=1000;
    }
    else if (argc==2) {
        n=atoi(argv[1]);
        maxRandValue=1000;
    }
    else if (argc==3) {
        n=atoi(argv[1]);
        maxRandValue=atoi(argv[2]);
    }

    /* Initializes a random number generator according to current time */
    srand((unsigned)time(NULL));

    /* Allocate the array and fill with random numbers */
    numToSum = (int*) malloc (sizeof(int) * n);
    for(i=0;i<n;i++){
        numToSum[i]=rand() % maxRandValue +1;
    }

    gettimeofday(&startTime,0); // The time counter starts

    /* Compute the sum */
    for (i=0;i<n;i++){
        sum+=numToSum[i];
    }






}