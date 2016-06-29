#include<stdio.h>
#include<string.h>
char a[20];
int main()
{char c[20];int i,j,x;
printf("Enter the string");
scanf("%s",a);
for(j=0;j<26;j++)
{for(i=0;i<strlen(a);i++)
{x=(a[i]-97-j);//printf("%d",x);
if(x<0)
{do
{x=x+26;//printf("%d",x);
} 
while(x<0);
c[i]=x+97;
}
else
c[i]=(a[i]-97-j)%26+97;}
printf("\nDecrypted string :%s",c);
}
}
