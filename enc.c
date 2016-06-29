#include<stdio.h>
#include<string.h>
char a[20];
int main()
{char c[20];int i,x;
printf("Enter the string");
scanf("%s",a);
for(i=0;i<strlen(a);i++)
c[i]=(a[i]-97+3)%26+97;

printf("Encrypted string :%s",c);
for(i=0;i<strlen(a);i++)
{x=(c[i]-97-3);// printf("%d",x);
if(x<0)
{do
{x=x+26;printf("%d",x);
} 
while(x<0);
c[i]=x+97;
}
else
c[i]=(c[i]-97-3)%26+97;}
printf("Decrypted string :%s",c);

}


