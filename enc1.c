#include<stdio.h>
#include<string.h>
char a[20],k[20];
int main()
{char c[20];int i,j=0;
printf("Enter the string");
scanf("%s",a);
printf("Enter the key");
scanf("%s",k);
for(i=0;i<strlen(a);i++)
c[i]=((a[i]-97)+(k[j++%strlen(k)]-97))%26+97;
printf("Encrypted :%s",c);
for(i=0;i<strlen(a);i++)
c[i]=((c[i]-97)-(k[j++%strlen(k)]-97))%26+97;
printf("Decrypted:%s",c);

}


