#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include <unistd.h>

typedef struct{
int velkost;
int mnozina[15];
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
    for (int i = 0; i < m.velkost; i++) {
        m.mnozina[m.velkost] = rand() % 101; // Generovanie od 0 po 100
    }
    return m;
}


MNOZINA prienik(int m1[], int m2[], int velkost_m1, int velkost_m2)
{
     MNOZINA m;

     for(int i=0; i<velkost_m1 ; i++)
     {
          for(int j=0; j<velkost_m2;j++)
          {
               if(m1[i] == m2[j])
               {
                    m.mnozina[m.velkost] = m1[i];
                    m.velkost++;
               }
          }      
} 
return m;
}

MNOZINA zjednotenie(int m1[], int m2[], int velkost_m1, int velkost_m2)
{    
     MNOZINA m;
     for(int i=0; i<velkost_m1 ; i++)
     {
          m.mnozina[m.velkost] = m1[i];  
          m.velkost++; 
     }

     for(int i=0; i<velkost_m2 ; i++)
     {
          m.mnozina[m.velkost] = m2[i];   
          m.velkost++;
     }
     return m;
}

int main()
{
     srand(time(NULL));

    /* int* m1=generator_mnozin(5,1,10);
     int* m2=generator_mnozin(9,1,10);
     int* m_prieniku=prienik(m1,m2,5,9);
     int* m_zjednotenia=zjednotenie(m1,m2,5,9);*/
     MNOZINA m1, m2;
     MNOZINA zjednotenie_m, prienik_m;
  
     m1.velkost=10;
     m2.velkost=5;

     m1.mnozina=generator_mnozin(m1.velkost);
     m2.mnozina=generator_mnozin(m2.velkost);

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

     return 0;
}