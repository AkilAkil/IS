#include<stdio.h>
#include<string.h>
char a[10];char t[9],tab[9][9],tab1[9][9],an[10][10],an1[10][10];int in=0;
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
{int j,k,l,i1;
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
}i1=0;l=0;
for(k=0;k<strlen(a);k++)
{for(j=7;j>=0;j--)
tab1[i1][l++]=tab[k][j];
i1++;l=0;}
k=0;l=0;
for(i1=0;i1<3;i1++)
{for(j=7;j>=0;j--)
{an[k][l++]=tab1[j][i1];
if(l>6)
{k++;l=0;}
}
}
printf("\nPt-1(28-Bit)\n");
for(i1=0;i1<4;i1++)
{for(j=0;j<7;j++)
printf("%d",an[i1][j]);
printf("\n");}
k=0;l=0;

for(i1=6;i1>=3;i1--)
{for(j=7;j>=0;j--)
{if(i1==3&&j==7) j=3;
an1[k][l++]=tab1[j][i1];
//printf("\t%d",an1[k][l-1]);

if(l>6)
{k++;l=0;
}}}
printf("\nPt-2(28-Bit)\n");
for(i1=0;i1<4;i1++)
{for(j=0;j<7;j++)
printf("%d",an1[i1][j]);
printf("\n");}
}
