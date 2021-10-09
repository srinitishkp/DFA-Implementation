        #include"lexHdr.h"
int getIndex(char* sigma,char ip)
{
    for(int i=0;i<strlen(sigma);i++)
        if(*(sigma+i)==ip)
            return i;
    return -1;        
}
void dash()
{
    printf("\n---------------------------------------------------------------------------------\n");    
}
int accState(int* accStates,int cs,int n)
{
    for(int i=0;i<n;i++)
        if(accStates[i]==cs)
            return 1;
    return 0;        
}