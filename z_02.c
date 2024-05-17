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
}

MNOZINA *generator_mnozin(int n) {
     MNOZINA *m = (MNOZINA*) malloc (n * sizeof(MNOZINA));
     m->mnozina = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        m->mnozina[i] = rand() % 101; // Generovanie od 0 po 100
    }
    return m;
}

MNOZINA *prienik(int *m1, int *m2, int velkost_m1, int velkost_m2)
{
     MNOZINA *m = (MNOZINA*) malloc (sizeof(MNOZINA));
     m->velkost=0;
     m->mnozina = (int*)malloc((velkost_m1 < velkost_m2 ? velkost_m1 : velkost_m2) * sizeof(int));
     m->pocitadlo=0;
     int i = 0, j = 0;
     while (i < velkost_m1 && j < velkost_m2) 
     {
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
          m->pocitadlo++;
     }

     return m;
}

MNOZINA *zjednotenie(int *m1, int *m2, int velkost_m1, int velkost_m2)
{    
     MNOZINA *m = (MNOZINA*) malloc (sizeof(MNOZINA));
     m->velkost=0;
     m->mnozina = (int*)malloc((velkost_m1 < velkost_m2 ? velkost_m1 : velkost_m2) * sizeof(int));
     m->pocitadlo=0;
     int i = 0, j = 0;
     while (i < velkost_m1 && j < velkost_m2) {
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
          m->pocitadlo++;
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
     FILE*f;

     /*
     MNOZINA m1,m2;

     m1.velkost=50;
     m2.velkost=50;

     MNOZINA *m1_generovane = generator_mnozin(m1.velkost);
     MNOZINA *m2_generovane = generator_mnozin(m2.velkost);   
     MNOZINA *zjednotenie_m, *prienik_m;

     for (int i = 0; i < m1.velkost; i++)
     {
          m1.mnozina[i] = m1_generovane->mnozina[i];
     }

     for (int i = 0; i < m2.velkost; i++) 
     {
          m2.mnozina[i] = m2_generovane->mnozina[i];
     }

     printf("m1 = {");
     vypis_mnozin(m1.mnozina,m1.velkost);
     printf("}\n");

     printf("m2 = {");
     vypis_mnozin(m2.mnozina,m2.velkost);
     printf("}\n");
     
     prienik_m = prienik(m1.mnozina,m2.mnozina,m1.velkost,m2.velkost);
     printf("prienik = {");
     vypis_mnozin(prienik_m->mnozina,prienik_m->velkost);
     printf("}\n");

     zjednotenie_m = zjednotenie(m1.mnozina,m2.mnozina,m1.velkost,m2.velkost);
     printf("zjednotenie = {");
     vypis_mnozin(zjednotenie_m->mnozina,zjednotenie_m->velkost);
     printf("}\n");

     printf("Pocet operacii prieniku: %d\n",prienik_m->pocitadlo);
     
     printf("Pocet operacii zjednotenia: %d\n",zjednotenie_m->pocitadlo);
     
     printf("Celkovy pocet operacii: %d\n",prienik_m->pocitadlo + zjednotenie_m->pocitadlo);
     */

     int velkosti[] = {10,20,30,40,50};
     int pocet_experimentov = 20;
     int n = sizeof(velkosti) / sizeof(velkosti[0]); 

     f=fopen("vysledky.txt","w");

    for (int i = 0; i < n; i++)
     {
          int suma_operacii_zjednotenia = 0;
          int suma_operacii_prieniku = 0;

          for (int j = 0; j < pocet_experimentov; j++)
          {
               MNOZINA *m1 = generator_mnozin(velkosti[i]);
               MNOZINA *m2 = generator_mnozin(velkosti[i]);
               MNOZINA *prienik_m = prienik(m1->mnozina, m2->mnozina, m1->velkost, m2->velkost);
               MNOZINA *zjednotenie_m = zjednotenie(m1->mnozina, m2->mnozina, m1->velkost, m2->velkost);

               suma_operacii_prieniku += prienik_m->pocitadlo;
               suma_operacii_zjednotenia += zjednotenie_m->pocitadlo;

               free(m1);
               free(m2);
               free(prienik_m);
               free(zjednotenie_m);
          }

          double priemer_operacii_prieniku = (double)suma_operacii_prieniku / pocet_experimentov;
          double priemer_operacii_zjednotenia = (double)suma_operacii_zjednotenia / pocet_experimentov;

          printf("Velkost mnoziny: %d\n", velkosti[i]);
          printf("Priemerny pocet operacii prieniku: %.2f\n", priemer_operacii_prieniku);
          printf("Priemerny pocet operacii zjednotenia: %.2f\n", priemer_operacii_zjednotenia);
     }
     /*
     if (f == NULL) 
     {
        printf("Error opening file!\n");
        return 1;
     }

     prienik_m->pocitadlo=0;
     zjednotenie_m->pocitadlo=0;
     for(int i=1;i<=20;i++)
     {
          prienik_m=prienik(m1.mnozina,m2.mnozina,i,i);
          prienik_m->pocitadlo++;
          zjednotenie_m=prienik(m1.mnozina,m2.mnozina,i,i);
          zjednotenie_m->pocitadlo++;
          fprintf(f,"%d\t%d\n",i,prienik_m->pocitadlo,zjednotenie_m->pocitadlo);
          prienik_m->pocitadlo=0;
          zjednotenie_m->pocitadlo=0;
     }
     */

     fclose(f);
     return 0;
}