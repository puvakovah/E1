#include <stdio.h>
#define N 4
#define M 5

void vypis_mnozin(int m[])
{
     for(int i=0; i<100 ; i++)
     {
          printf( " %d ",m[i]);
     }
}

int prienik(int m1[], int m2[], int velkost_m1, int velkost_m2)
{
     int P=0;
     int m[M];

     for(int i=0; i<velkost_m1 ; i++)
     {
          for(int j=0; j<velkost_m2;j++)
          {
               if(m1[i] == m2[j])
               {
                    m[P++] = m2[j];
               }
          }    
     }
     
}

void zjednotenie(int m1[], int m2[], int velkost_m1, int velkost_m2)
{
     int P=0;
     int m[M];


     for(int i=0; i<velkost_m1 ; i++)
     {
          m[P++] = m1[i];   
     }

     for(int i=0; i<velkost_m2 ; i++)
     {
          m[P++] = m2[i];   
     }

}

int main()
{
     int a[N]={1,2,3,4},b[M]={2,2,4,6,8},m[100];
     
     m[100]=prienik(a,b,N,M);
     for(int i=0;i<100;i++)
     vypis_mnozin(m);
     //zjednotenie(a,b,N,M);
     
     return 0;
}