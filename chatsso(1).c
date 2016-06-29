//Chat Server Side Operation
#define BUFFER_SIZE 256
#include<stdio.h>
#include <sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<strings.h>
void com_client(int sockfd)
{
	char snd[BUFFER_SIZE];
	char rcv[BUFFER_SIZE];
	int bytes_rcv;
	for(;;)
	{
		bzero(rcv,BUFFER_SIZE);
		read(sockfd,rcv,sizeof(rcv));
		bytes_rcv=strlen(rcv);
		printf("\n bytes received =%d bytes \n data received from client:%s",bytes_rcv-1,rcv);
		bzero(snd,BUFFER_SIZE);
		printf("enter the data \n");
		fgets(snd,255,stdin);
		write(sockfd,snd,sizeof(snd));
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
	server.sin_port=htons(4000);
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

