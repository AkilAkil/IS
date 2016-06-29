//Chat Server Side Operation
#define BUFFER_SIZE 256
#include<stdio.h>
#include <sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<strings.h>
void com_client(int sockfd)
{	char c[BUFFER_SIZE];
	char a[BUFFER_SIZE];
	char rcv[BUFFER_SIZE];
	int bytes_rcv,i,x;
	for(;;)
	{
		bzero(rcv,BUFFER_SIZE);
		read(sockfd,c,sizeof(rcv));
		bytes_rcv=strlen(rcv);
		printf("\n bytes received =%d bytes \n",bytes_rcv-1);
		//bzero(c,BUFFER_SIZE);
		
//printf("%s",c);
/*for(i=0;i<strlen(a);i++)
c[i]=(a[i]-97+3)%26+97;

printf("Encrypted string :%s",c);*/
for(i=0;i<strlen(c);i++)
{x=(c[i]-97-3);// printf("%d",x);
if(x<0)
{do
{x=x+26;printf("%d",x);
} 
while(x<0);
a[i]=x+97;
}
else
a[i]=(c[i]-97-3)%26+97;//printf("\n%s",a);
}a[i-1]='\0';
printf("Decrypted string :");
puts(a);



bzero(a,BUFFER_SIZE);
printf("enter the data \n");
		fgets(a,255,stdin);
for(i=0;i<strlen(a);i++)
c[i]=(a[i]-97+3)%26+97;
c[i]='\0';

//printf("Encrypted string :%s",c);

		write(sockfd,c,sizeof(c));
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
	int sd,new_socket,c;
	struct sockaddr_in server,client;
	printf("\n tcp/ip server side operation \n");
	sd=socket(AF_INET,SOCK_STREAM,0);
	if(sd<0)
	{
		printf("could not create socket \n");
	}
	printf("Socket created \n");
	server.sin_family=AF_INET;//internet address family
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_port=htons(4130);
	//binding functions
	if(bind(sd,(struct sockaddr*)&server,sizeof(server))<0)
		printf("bind failed \n");
	printf("bind done \n");
	//listen
	listen(sd,5);
	printf("\n waiting for incomming connection \n");
	//accepting client connection
	c=sizeof(struct sockaddr_in);
	new_socket=accept(sd,(struct sockaddr*)&client,(socklen_t*)&c);
	if(new_socket<0)
		printf("accept failed \n");
	else
	{
		printf("connection accepted \n");
		com_client(new_socket);
	}
	close(new_socket);
	close(sd);
}
/*output
  tcp/ip server side operation 
Socket created 
bind done 

 waiting for incomming connection 
connection accepted 

 bytes received =7 bytes 
 data received from client:vignesh
enter the data 
you know,he is a good boy

 bytes received =16 bytes 
 data received from client:ya you are right
enter the data 
hmmmmmmmmmmmm

 bytes received =3 bytes 
 data received from client:bye
enter the data 
bye

 connection closed p

*/

