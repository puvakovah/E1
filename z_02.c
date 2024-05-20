#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct{
     int velkost;
     int *mnozina;
     int pocitadlo;
}MNOZINA;

void vypis_mnozin(int *m, int n)
{
     for(int i=0; i<n ; i++)
     {
          printf( " %d ", *(m + i));
     }
     printf("\n");
}

int *generator_mnozin(int n) {
     int *m = (int*) malloc (n * sizeof(int));
    for (int i = 0; i < n; i++) {
        m[i] = rand() % 101; // Generovanie od 0 po 100
    }
    return m;
}


MNOZINA *prienik(int *m1, int *m2, int velkost_m1, int velkost_m2)
{
     MNOZINA *m = (MNOZINA*) malloc (sizeof(MNOZINA));
     m->velkost=0;
     m->mnozina = (int*)malloc(velkost_m1 * sizeof(int));
     m->pocitadlo=0;
     int i = 0, j = 0;
     while (i < velkost_m1 && j < velkost_m2) 
     {
          m->pocitadlo++;
          if (m1[i] < m2[j]) 
          {
               i++;
          } 
          else if (m2[j] < m1[i]) 
          {
               j++;
          } 
          else 
          {
          m->mnozina[m->velkost++] = m1[i];
               i++;
               j++;
          } 
     }

     return m;
}

MNOZINA *zjednotenie(int *m1, int *m2, int velkost_m1, int velkost_m2)
{    
     MNOZINA *m = (MNOZINA*) malloc (sizeof(MNOZINA));
     m->velkost=0;
     m->mnozina = (int*)malloc((velkost_m1+velkost_m2) * sizeof(int));
     m->pocitadlo=0;
     int i = 0, j = 0;
     while (i < velkost_m1 && j < velkost_m2) 
     {
          m->pocitadlo++;
          if (m1[i] < m2[j]) {
               m->mnozina[m->velkost++] = m1[i];
               i++;
          } 
          else if (m2[j] < m1[i]) {
               m->mnozina[m->velkost++] = m2[j];
               j++;
          } 
          else {
               m->mnozina[m->velkost++] = m1[i];
               i++;
               j++;
          }
          
     }

     while (i < velkost_m1) {
          m->mnozina[m->velkost++] = m1[i++];
          m->pocitadlo++;
     }

     while (j < velkost_m2) {
          m->mnozina[m->velkost++] = m2[j++];
          m->pocitadlo++;
     }

    return m;
}


int main()
{
     srand(time(NULL));

     int velkosti[] = {10,20,30,40,50};
     int pocet_experimentov = 20;
     int n = sizeof(velkosti) / sizeof(velkosti[0]); 


    for (int i = 0; i < n; i++)
     {
          int suma_operacii_zjednotenia = 0;
          int suma_operacii_prieniku = 0;
          int velkost = velkosti[i];

          for(int j = 0; j < pocet_experimentov; j++)
          {
               int *m1 = generator_mnozin(velkost);
               int *m2 = generator_mnozin(velkost);

               MNOZINA *prienik_m ;
               MNOZINA *zjednotenie_m ;

               prienik_m = prienik(m1, m2, velkost,velkost);
               zjednotenie_m = zjednotenie(m1, m2, velkost,velkost);

               suma_operacii_prieniku += prienik_m->pocitadlo;
               suma_operacii_zjednotenia += zjednotenie_m->pocitadlo;

               free(m1);
               free(m2);
               free(prienik_m->mnozina);
               free(prienik_m);
               free(zjednotenie_m->mnozina);
               free(zjednotenie_m);

          }

          double priemer_operacii_prieniku = (double)suma_operacii_prieniku / pocet_experimentov;
          double priemer_operacii_zjednotenia = (double)suma_operacii_zjednotenia / pocet_experimentov;

          printf("Velkost mnoziny: %d\n", velkost);
          printf("Priemerny pocet operacii prieniku: %.2f\n", priemer_operacii_prieniku);
          printf("Priemerny pocet operacii zjednotenia: %.2f\n", priemer_operacii_zjednotenia);
     }
     return 0;
}