#include <stdio.h>
#include<time.h>
#include<stdlib.h>

void vypis_mnozin(int M[], int n)
{
     for(int i=0; i<n ; i++)
     {
          printf( " %d ",&M[i]);
     }
}

int* generator_mnozin(int n) {
    srand(time(NULL));

    int* M = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        M[i] = rand() % 101; // Generovanie od 0 po 100
    }
}


int prienik(int m1[], int m2[], int velkost_m1, int velkost_m2)
{
     int P=0;
     int M[P];

     for(int i=0; i<velkost_m1 ; i++)
     {
          for(int j=0; j<velkost_m2;j++)
          {
               if(m1[i] == m2[j])
               {
                    M[P++] = m2[j];
               }
          }    
     }
     
}

void zjednotenie(int m1[], int m2[], int velkost_m1, int velkost_m2)
{
     int P=0;
     int M[P];


     for(int i=0; i<velkost_m1 ; i++)
     {
          M[P++] = m1[i];   
     }

     for(int i=0; i<velkost_m2 ; i++)
     {
          M[P++] = m2[i];   
     }

}

int main()
{
     int n=6,m=8;
    int* m1=generator_mnozin(n);
    int* m2=generator_mnozin(m);
  
    printf("m1 = {");
    vypis_mnozin(m1,n);
    printf("}\n");
     printf("m2 = {");
    vypis_mnozin(m2,n);
    printf("}\n");
     
     return 0;
}