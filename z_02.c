#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include <unistd.h>

void vypis_mnozin(int M[], int n)
{
     for(int i=0; i<n ; i++)
     {
          printf( " %d ", M[i]);
     }
}

int* generator_mnozin(int n) {
    usleep(1000000);
    srand(time(NULL));

    int* M = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        M[i] = rand() % 101; // Generovanie od 0 po 100
    }

    return M;
}


int* prienik(int m1[], int m2[], int velkost_m1, int velkost_m2)
{
     int P=0;
     int* M = malloc((velkost_m1 + velkost_m2) * sizeof(int));

     for(int i=0; i<velkost_m1 ; i++)
     {
          for(int j=0; j<velkost_m2;j++)
          {
               if(m1[i] == m2[j])
               {
                    M[P++] = m1[i];
               }
          }      
} 
return M;
}

int* zjednotenie(int m1[], int m2[], int velkost_m1, int velkost_m2)
{
     int P=0;
     int* M = malloc((velkost_m1 + velkost_m2) * sizeof(int));


     for(int i=0; i<velkost_m1 ; i++)
     {
          M[P++] = m1[i];   
     }

     for(int i=0; i<velkost_m2 ; i++)
     {
          M[P++] = m2[i];   
     }
     return M;
}

int main()
{
     int r,n;
     printf("Zadaj 2 velkosti pola\n");
     scanf("%d%d",&n,&r);

     int* m1=generator_mnozin(n);
     int* m2=generator_mnozin(r);
     int* m_prieniku=prienik(m1,m2,n,r);
     int* m_zjednotenia=zjednotenie(m1,m2,n,r);
  
     printf("m1 = {");
     vypis_mnozin(m1,n);
     printf("}\n");

     printf("m2 = {");
     vypis_mnozin(m2,r);
     printf("}\n");
     
     printf("prienik = {");
     vypis_mnozin(m_prieniku,r);
     printf("}\n");

     printf("m2 = {");
     vypis_mnozin(m_zjednotenia,n+r);
     printf("}\n");

     free(m1);
    free(m2);
    free(m_prieniku);
    free(m_zjednotenia);
     return 0;
}