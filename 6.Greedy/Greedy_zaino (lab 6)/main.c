#include <stdio.h>
#include <stdlib.h>

typedef struct {
char nome[30];
int peso;
int valore;
int pspec
}obj;

int main()
{
    printf("Inserisci il peso massimo P: ");
    int Pmax=0;
    scanf("%d",&Pmax);

    printf("\nInserisci il numro di oggetti da prendere in esame: ");
    int N=0;
    scanf("%d",&N);

    obj *oggetti=malloc(N*sizeof(obj));

	int i;
    for(i=0; i<N; i++)
    {
        printf("\nInserisci il nome del %d oggetto: ",i+1);
        scanf("%s",oggetti[i].nome);
        printf("\nInserisci il peso del %d oggetto: ",i+1);
        scanf("%d",&oggetti[i].peso);
        printf("\nInserisci il valore del %d oggetto: ",i+1);
        scanf("%d",&oggetti[i].valore);
        oggetti[i].pspec=oggetti[i].valore/oggetti[i].peso;
    }

    obj tmp;

   //Bubble sort (ordine decrescente)
   int j;
   for(i=0; i<N-1; i++)
   {
        for(j=0; j<N-1-i; j++)
        {
            if(oggetti[j].pspec<oggetti[j+1].pspec)
            {
                tmp=oggetti[j];
                oggetti[j]=oggetti[j+1];
                oggetti[j+1]=tmp;

            }
        }
   }

   int sumP=0;
   int valP=0;
   int flag=0;
  

   while(sumP<Pmax&&flag==0)
   {
        if(sumP<Pmax)
        {
            sumP=sumP+oggetti[i].peso;
            valP=valP+oggetti[i].valore;

        }
        if(sumP>Pmax)
        {
            flag=1;
            sumP=sumP-oggetti[i].peso;
            valP=valP-oggetti[i].valore;
        }


        i++;
   }

   printf("\nIl peso che si avvicina di piu' senza sforare e': %d, con valore %d",sumP,valP);


    return 0;
}
