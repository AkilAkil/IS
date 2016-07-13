#include<stdio.h>
#include<string.h>
char a[10];char t[9],tab[9][9];int in=0;
void swap(char *x,char *y)
{char tem;
tem=*x;*x=*y;*y=tem;
}
void bin(char x)
{int c=x,i=0;
while(c!=0)
{t[i++]=c%2;
c=c/2;}
//t[8]='\0';
for(i=7;i>=0;i--)
tab[in][i]=t[i];
in++;

 }
int main()
{int j,k,l;char *p;
printf("I/p");
scanf("%s",a);
for(j=0;j<strlen(a);j++)
bin(a[j]);
//for(j=7;j>=0;j--)
//printf("%d",t[j]);
for(k=0;k<strlen(a);k++)
{for(j=7;j>=0;j--)
printf("%d",tab[k][j]);
printf("\n");
}//strcpy(tab[0],t);

for(k=1;k<=7;k+=2)
for(l=0;l<strlen(a)/2;l++)
{//tab[l][k]=tab[7-l][k]+tab[l][k]-(tab[7-l][k]=tab[l][k]);
swap(&tab[l][k],&tab[7-l][k]);
}
printf("\n");
for(k=0;k<strlen(a);k++)
{for(j=7;j>=0;j--)
printf("%d",tab[k][j]);
printf("\n");
}









}
