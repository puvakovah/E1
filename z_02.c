#include <stdio.h>
#define N 4
#define M 5

void vypis_mnozin(int m[], int velkost_m)
{
     for(int i=0; i<velkost_m ; i++)
     {
          printf("%d\t",m[i]);

     }
}
void prienik(int m1[], int m2[], int velkost_m1, int velkost_m2)
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
     vypis_mnozin(m,P);
}
int main()
{
     int a[N]={1,2,3,4},b[M]={2,2,4,6,8};
     
     prienik(a,b,N,M);
     
     return 0;
}