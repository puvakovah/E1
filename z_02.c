#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include <unistd.h>

typedef struct{
int velkost;
int mnozina[15];
int pocitadlo;
}MNOZINA;

void vypis_mnozin(MNOZINA m)
{
     for(int i=0; i<m.velkost ; i++)
     {
          printf( " %d ", m.mnozina[i]);
     }
}

MNOZINA generator_mnozin(int n) 
{
     MNOZINA m;
    for (int i = 0; i < n; i++) {
        m.mnozina[i] = rand() % 101; // Generovanie od 0 po 100
    }
    return m;
}


MNOZINA prienik(MNOZINA m1,MNOZINA m2)
{
     MNOZINA m;
     m.velkost=0;
     m.pocitadlo=0;

     for(int i=0; i<m1.velkost ; i++)
     {
          for(int j=0; j<m2.velkost;j++)

          {
               if(m1.mnozina[i] == m2.mnozina[j])
               {
                    m.mnozina[m.velkost++] = m1.mnozina[i];  
                    break;
               }
           m.pocitadlo++; 
          }   
     } 
return m;
}

MNOZINA zjednotenie(MNOZINA m1, MNOZINA m2)
{    
     MNOZINA m;
     m.velkost=0;
     m.pocitadlo=0;
     for(int i=0; i<m1.velkost ; i++)
     {
          m.mnozina[m.velkost] = m1.mnozina[i];  
          m.velkost++; 
          m.pocitadlo++;
     }

     for(int i=0; i<m2.velkost ; i++)
     {
          m.mnozina[m.velkost] = m2.mnozina[i];   
          m.velkost++;
          m.pocitadlo++;
     }
     return m;
}

void zapis_do_suboru(MNOZINA m1, MNOZINA m2, MNOZINA operacia,FILE *f)
{
     MNOZINA m;
     m.velkost=0;
     m.pocitadlo=0;

     for(int i=0; i<m1.velkost ; i++)
     {
          for(int j=0; j<m2.velkost;j++)

          {
               if(m1.mnozina[i] == m2.mnozina[j])
               {
                    m.mnozina[m.velkost++] = m1.mnozina[i];  
                    break;
               }
           m.pocitadlo++; 
          } 
          fprintf(f,"%d\t%d\n",i,m.pocitadlo);  
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
   
     m1.velkost=10;
     m2.velkost=5;

     for (int i = 0; i < m1.velkost; i++) {
        m1.mnozina[i] = generator_mnozin(m1.velkost).mnozina[i];
     }
     for (int i = 0; i < m2.velkost; i++) {
        m2.mnozina[i] = generator_mnozin(m2.velkost).mnozina[i];
     }

     printf("m1 = {");
     vypis_mnozin(m1);
     printf("}\n");

     printf("m2 = {");
     vypis_mnozin(m2);
     printf("}\n");
     
     prienik_m=prienik(m1,m2);
     printf("prienik = {");
     vypis_mnozin(prienik_m);
     printf("}\n");

     zjednotenie_m=zjednotenie(m1,m2);
     printf("zjednotenie = {");
     vypis_mnozin(zjednotenie_m);
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

     zapis_do_suboru(m1,m2,prienik_m,f);

     fclose(f);
     return 0;
}