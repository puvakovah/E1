#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include <unistd.h>

typedef struct{
int velkost;
int mnozina[200];
int pocitadlo;
}MNOZINA;

void vypis_mnozin(int m[], int n)
{
     for(int i=0; i<n ; i++)
     {
          printf( " %d ", m[i]);
     }
}

MNOZINA generator_mnozin(int n) {
    MNOZINA m;
    m.velkost=n;
    for (int i = 0; i < m.velkost; i++) {
        m.mnozina[i] = rand() % 101; // Generovanie od 0 po 100
    }
    return m;
}

MNOZINA prienik(int m1[], int m2[], int velkost_m1, int velkost_m2)
{
     MNOZINA m;
     m.velkost=0;
     m.pocitadlo=0;

     for(int i=0; i<velkost_m1 ; i++)
     {
          for(int j=0; j<velkost_m2;j++)

          {
               if(m1[i] == m2[j])
               {
                    m.mnozina[m.velkost++] = m1[i];  
                    break;
               }
           m.pocitadlo++; 
          }   
     } 
return m;
}

MNOZINA zjednotenie(int m1[], int m2[], int velkost_m1, int velkost_m2)
{    
     MNOZINA m;
     m.velkost=0;
     m.pocitadlo=0;
     for(int i=0; i<velkost_m1 ; i++)
     {
          m.mnozina[m.velkost] = m1[i];  
          m.velkost++; 
          m.pocitadlo++;
     }

     int existuje;
     for(int i=0; i<velkost_m1 ; i++)
     {
          for(int j=0;j<=velkost_m2;j++)
          {
               if(m1[i]==m2[j])
               {
                    existuje=1;
                    break;
               }
               if(existuje!=1)
               {
                    m.mnozina[m.velkost++]=m2[j];
               }
          }
          m.pocitadlo++;
     }
     return m;
}


int main()
{
     srand(time(NULL));
     FILE*f;
    /* int* m1=generator_mnozin(5,1,10);
     int* m2=generator_mnozin(9,1,10);
     int* m_prieniku=prienik(m1,m2,5,9);
     int* m_zjednotenia=zjednotenie(m1,m2,5,9);*/
     MNOZINA m1, m2;
     MNOZINA zjednotenie_m, prienik_m;
   
     m1.velkost=50;
     m2.velkost=50;

     for (int i = 0; i < m1.velkost; i++) {
        m1.mnozina[i] = generator_mnozin(m1.velkost).mnozina[i];
     }
     for (int i = 0; i < m2.velkost; i++) {
        m2.mnozina[i] = generator_mnozin(m2.velkost).mnozina[i];
     }

     printf("m1 = {");
     vypis_mnozin(m1.mnozina,m1.velkost);
     printf("}\n");

     printf("m2 = {");
     vypis_mnozin(m2.mnozina,m2.velkost);
     printf("}\n");
     
     prienik_m=prienik(m1.mnozina,m2.mnozina,m1.velkost,m2.velkost);
     printf("prienik = {");
     vypis_mnozin(prienik_m.mnozina,prienik_m.velkost);
     printf("}\n");

     zjednotenie_m=zjednotenie(m1.mnozina,m2.mnozina,m1.velkost,m2.velkost);
     printf("zjednotenie = {");
     vypis_mnozin(zjednotenie_m.mnozina,zjednotenie_m.velkost);
     printf("}\n");

     printf("Pocet operacii prieniku: %d\n",prienik_m.pocitadlo);
     
     printf("Pocet operacii zjednotenia: %d\n",zjednotenie_m.pocitadlo);
     
     printf("Celkovy pocet operacii: %d\n",prienik_m.pocitadlo + zjednotenie_m.pocitadlo);

     f=fopen("vysledky.txt","w");



     if (f == NULL) 
     {
        printf("Error opening file!\n");
        return 1;
     }

     prienik_m.pocitadlo=0;
     zjednotenie_m.pocitadlo=0;
     for(int i=1;i<=20;i++)
     {
          prienik_m=prienik(m1.mnozina,m2.mnozina,i,i);
          prienik_m.pocitadlo++;
          zjednotenie_m=prienik(m1.mnozina,m2.mnozina,i,i);
          zjednotenie_m.pocitadlo++;
          fprintf(f,"%d\t%d\n",i,prienik_m.pocitadlo,zjednotenie_m.pocitadlo);
          prienik_m.pocitadlo=0;
          zjednotenie_m.pocitadlo=0;
     }

     fclose(f);
     return 0;
}