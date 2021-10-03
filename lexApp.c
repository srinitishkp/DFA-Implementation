#include"lexHdr.h"
int main()
{
  int ip_size,noOfStates,noOfSym,i,j,ch;
  dash();
  printf("\nEnter the no. of States:");
  scanf("%d",&noOfStates);
  int * Q=malloc(noOfStates*sizeof(int));
  for(i=0;i<noOfStates;i++)
    Q[i]=i;
  dash();   
  printf("Enter the no. of Symbols:");
  scanf("%d",&noOfSym);
  char *symbols=malloc(noOfSym*sizeof(char));
  dash();
  printf("\nEnter the symbols:");
  scanf("%s",symbols);
  int **trans_tab=malloc(noOfStates*sizeof(int *));
  for(i=0;i<noOfStates;i++)
    trans_tab[i]=malloc(noOfSym*sizeof(int));
  dash();
  printf("\nEnter transistion table elements:");
  int temp;
  for(i=0;i<noOfStates;i++)
  {
    for(j=0;j<noOfSym ;j++)
    {
      printf("\ntrans(q%d,%c)",i,*(symbols+j));
      scanf("%d",&temp);
      if(temp<noOfStates)
        trans_tab[i][j]=temp;
      else
      {
        printf("\nEnter valid state");
        j--;
      }
    }
  }
  int initialState,noOfAcc;
  dash();
  printf("Enter the initial state:");
  scanf("%d",&initialState);
  dash();
  printf("Enter the no. of Accepting states:");
  scanf("%d",&noOfAcc);
  int *accStates=malloc(noOfAcc*sizeof(int));
  dash();
  printf("\nEnter the accepting state numbers:");
  for(i=0;i<noOfAcc;i++)
  {
    scanf("%d",&accStates[i]);
    if(temp<noOfStates)
        trans_tab[i][j]=temp;
      else
      {
        printf("\nEnter valid state");
        i--;
      }
  }
  dash();
  printf("\nTransistion Table:\nState\t");
  for(i=0;i<noOfSym;i++)
    printf("%c\t",symbols[i]);
  for(i=0;i<noOfStates;i++)
  {
    printf("\n");
    if(i==initialState)
      printf("-->");
    if(accState(accStates,i,noOfAcc))
      printf("*");
    printf("q%d\t",i);
    for(j=0;j<noOfSym;j++)
    {
      printf("q%d\t",trans_tab[i][j]);
    }
  }     
  dash(); 
  printf("Enter size of input string:");
  scanf("%d",&ip_size);
  char * input=malloc(ip_size*sizeof(char));
  dash();
  printf("\nEnter the input string:\n");
  scanf("%s",input);
  int currentstate=initialState;
  int pos=0;
  int fp=0;
  dash();
  while(1)
  {
    printf("q%d--->",currentstate);
    pos=getIndex(symbols,*(input+fp));
    if(pos!=-1)
    {
      currentstate=trans_tab[currentstate][pos];
      fp+=1;
    }
    else
    {
      break;
    }
  }
  if(fp==strlen(input)&&accState(accStates,currentstate,noOfAcc))
  {
    printf("Accepted.\n");
  }
  else
  {
    printf("Rejected.\n");
  }    
  free(trans_tab);
  free(symbols);
  free(input);
  free(accStates);
  free(Q);
}