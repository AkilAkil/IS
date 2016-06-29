//Chat Client Side Operation
#define BUFFER_SIZE 256
#include<stdio.h>
#include <sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<strings.h>
void com_server(int sockfd)
{	char c[BUFFER_SIZE];
	char a[BUFFER_SIZE];
	char rcv[BUFFER_SIZE];
	int bytes_rcv,i,x;
	for(;;)
	{
		bzero(a,BUFFER_SIZE);//bzero is used to clear the snd buffer
		printf("\nenter the data \n");

		fgets(a,255,stdin);


for(i=0;i<strlen(a);i++)
c[i]=(a[i]-97+3)%26+97;

//printf("Encrypted string :%s",c);
/*for(i=0;i<strlen(a);i++)
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
//printf("%s",a);
*/

		write(sockfd,c,sizeof(c));
bzero(c,BUFFER_SIZE);

		read(sockfd,c,sizeof(c));
		bytes_rcv=strlen(rcv);

for(i=0;i<strlen(c);i++)
{x=(c[i]-97-3);// printf("%d",x);
if(x<0)
{do
{x=x+26;//printf("%d",x);
} 
while(x<0);
a[i]=x+97;
}
else
a[i]=(c[i]-97-3)%26+97;//printf("\n%s",a);
}a[i-1]='\0';
//printf("Decrypted string :");
//puts(a);


		printf("\n bytes received =%d bytes \n data received from server:%s",bytes_rcv-1,a);
		if(strncmp(rcv,"bye",3)==0)
		{
			bzero(rcv,BUFFER_SIZE);
			printf("\n connection closed ");
			break;//we use infite for loop so break is must
		}
	}
}
void main()
{
	int sd;
	struct sockaddr_in client;
	printf("tcp/ip client side operation \n");
	sd=socket(AF_INET,SOCK_STREAM,0);
	if(sd==-1)
		printf("could create the socket \n");
	printf("socket created \n");
	client.sin_family=AF_INET;//internet address family
	client.sin_addr.s_addr=inet_addr("127.0.0.1");
	client.sin_port=htons(4130);
	if(connect(sd,(struct sockaddr*)&client,sizeof(client))<0)
	{
		printf("coould not connected \n");
	}
	else
	{
		printf("connected \n");
		com_server(sd);
	}	
	close(sd);
}	
/*output
tcp/ip client side operation 
socket created 
connected 
enter the data 
vignesh

 bytes received =25 bytes 
 data received from server:you know,he is a good boy
enter the data 
ya you are right

 bytes received =13 bytes 
 data received from server:hmmmmmmmmmmmm
enter the data 
bye

 bytes received =3 bytes 
 data received from server:bye

 connection closed
*/
