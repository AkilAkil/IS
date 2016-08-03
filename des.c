#include<stdio.h>
#include<string.h>
char a[10];char t[9],tab[9][9],tab1[9][9],an[10][10],an1[10][10],ls[30];int in=0;
char cm[8]={8,16,19,21,30,32,36,46};
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
for(i1=0;i1<4;i1++)
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

if(l>6)
{k++;l=0;
}}}
printf("\nPt-2(28-Bit)\n");
for(i1=0;i1<4;i1++)
{for(j=0;j<7;j++)
printf("%d",an1[i1][j]);
printf("\n");}
k=0;
for(i1=0;i1<4;i1++)
{for(j=0;j<7;j++)
{ls[k++]=an[i1][j];
}}

l=ls[0];
//printf("%d",l);

for(j=0;j<k;j++)
ls[j]=ls[j+1];
ls[k]=l;k=0;
for(i1=0;i1<4;i1++)
for(j=0;j<7;j++)
an[i1][j]=ls[k++];
printf("\n");
for(i1=0;i1<4;i1++)
{for(j=0;j<7;j++)
printf("%d",an[i1][j]);
printf("\n");}
printf("\n");

k=0;
for(i1=0;i1<4;i1++)
{for(j=0;j<7;j++)
{ls[k++]=an1[i1][j];
}}

l=ls[0];
//printf("%d",l);

for(j=0;j<k;j++)
ls[j]=ls[j+1];
ls[k]=l;k=0;
for(i1=0;i1<4;i1++)
for(j=0;j<7;j++)
an1[i1][j]=ls[k++];
l=i1;
for(i1=0;i1<4;i1++)
{for(j=0;j<7;j++)
printf("%d",an1[i1][j]);
printf("\n");}

k=0;//Combine -56-Bit
for(i1=l;i1<8;i1++)
{for(j=0;j<7;j++)
{an[i1][j]=an1[k][j];
}k++;}
printf("\n");
for(i1=0;i1<8;i1++)
{for(j=0;j<7;j++)
printf("%d",an[i1][j]);
printf("\n");}
k=0;
for(i1=0;i1<8;i1++)
for(j=0;j<7;j++)
ls[k++]=an[i1][j];
i1=0;//56 Bit-->48-->Bit
for(j=0;j<k;j++)
{
if(j==cm[i1])
{
for(l=j;l<k;l++)
ls[l]=ls[l+1];
i1++;
}
}
printf("\n");
//for(j=0;j<k;j++)
//printf("  %d",ls[j]);

k=0;
for(i1=0;i1<7;i1++)
for(j=0;j<8;j++)
an1[i1][j]=ls[k++];
printf("48-Bit\n");
for(i1=0;i1<6;i1++)
{for(j=0;j<8;j++)

printf("%d",an1[i1][j]);
printf("\n");}

}
