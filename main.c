#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>


/*
 * @authors
 * Yuri Attanasio N97/000259
 * Danilo Ciano   N97/000260
 *
 *
 * Il programma calcola la somma di n numeri generati in modo randomico.
 * Complessità di tempo T(n) = n-1
 *
 * Input:
 * @param n : la quantità di numeri da sommare
 * @param maxRandValue: il valore intero massimo che il numero random può assumere
 *
 * N.B. se argv[1] e argv[2] non sono forniti in fase di esecuzione allora
 * verranno assunti valori di default: n = 10000000 e maxRandValue = 1000
 *
 *
 * Output:
 * @param sum = la somma dei numeri
 * @param D = La durata dell'esecuzione della somma (in microsecondi e secondi)
 * @param SP = La Sustained Performance calcolata come D/T(n) -
 * The algorithm T(n) = n-1 (Sum of n numbers)
 *
 *
 */


int main(int argc, char* argv[]) {

    /* Definizione delle variabili */
    int maxRandValue=0,Tn=0;
    long int n;
    long sum = 0;
    int i = 0;
    struct timeval startTime,finishTime;
    long int durationMS;
    long double durationS,SP;
    int *numToSum;


    /* Controllo sugli argomenti forniti in input dall'utente */
    if(argc > 3) {
        printf("Too many arguments provided");
        exit;
    }
    else if (argc==1) {
        n = 10000000;
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

    Tn=n-1;

    /* Inizializzazione del seme per la generazione di numeri random*/
    srand((unsigned)time(NULL));

    /* Allocazione array e riempimento con numeri random */
    numToSum = (int*) malloc (sizeof(int) * n);
    for(i=0;i<n;i++){
        numToSum[i]=rand() % maxRandValue +1;
    }


    gettimeofday(&startTime,0); // Inizio calcolo del tempo di esecuzione

    /* Effettuo la somma */
    for (i=0;i<n;i++){
        sum+=numToSum[i];
    }

    gettimeofday(&finishTime,0); // Fine calcolo del tempo di esecuzione
    durationMS = ((finishTime.tv_sec - startTime.tv_sec) * 1000000) +
            finishTime.tv_usec - startTime.tv_usec; // Calcolo la durata dell'op. somma in microsecondi
    durationS = ((long double)durationMS)/1000000; // Calcolo la durata dell'op. somma in secondi
    printf("\nLa somma degli n numeri è: %li\n",sum);
    printf("\nLa durata in microsecondi dell'operazione di somma è: %li\n",durationMS);
    printf("\nLa durata in secondi dell'operazione di somma è: %Lf\n",durationS);
    SP = Tn / durationS; // Calcolo la Sustained Performance
    printf("\nLa Sustained Performance è: %LF\n",SP);
    free(numToSum); // Libero l'array

}