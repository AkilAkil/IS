//Chat Client Side Operation
#define BUFFER_SIZE 256
#include<stdio.h>
#include <sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<strings.h>
void com_server(int sockfd)
{
	char snd[BUFFER_SIZE];
	char rcv[BUFFER_SIZE];
	int bytes_rcv;
	for(;;)
	{
		bzero(snd,BUFFER_SIZE);//bzero is used to clear the snd buffer
		printf("enter the data \n");
		fgets(snd,255,stdin);
		write(sockfd,snd,sizeof(snd));
		read(sockfd,rcv,sizeof(rcv));
		bytes_rcv=strlen(rcv);
		printf("\n bytes received =%d bytes \n data received from server:%s",bytes_rcv-1,rcv);
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
	client.sin_port=htons(4000);
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
