#include <stdio.h>
#include <stdafx.h>
#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT "8000"
#define MAX_CONNECTION 1000

//struktura:
/*Client 
	socket()
	Bind()
	connect()

----------------------
write()    |  read()
send ()    |  recv()
sendto()   |  recvfrom()
writev()   |  readv()
sendmsg()  |  recvmsg()

-----------------------








*/
//Begin*
//*Socket*
int create_socket(const char *);
int main ()
{
	return 0;
}

int creat_soket(const char *apstrPort)
{
	int sock;
	struct addrinfo c;
	struct addrinfo *servinfo;
	struct addrinfo *p;
	
	memset(&hints,0, sizeof (hitts)); //î÷èñòèòü ïàìÿòü ïî äàííîìó àäðóñó 


	hints.ai_family   = Af_UNSPEC;
	hints.ai_socktype = SOCk_STREAM;
	hints.ai_flags    = AI_PaSSIVE;  //для нахождение айпи
	

	int r;
	if (r=getaddrinfo(NULL, apstrPOrt, &hints,servinfo));
	if (r !=0)

	{
		fprintf(stderr,"error getaddrinfo()\n" );
		return-1;
	}

	for(p = servinfo; p != NULL; p= p->ai_next)
	{
		sock = soket (p->ai_socketype, p->ai_protocol);
		if(sock ==-1)
			continue;


		if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof (int)) ==-1)
		{
			fprint(stderr,"error setsockopt\n")
			close(sock);
			freeaddrinfo(servinfo);
			retur -2;

		}

		// END Socket;


		//Begin Bind
		 if (bind(sock,p->ai_addr, p-ai_addrlen) ==-1)
		 {
		 	close(sock);
		 	continue;
		 }
	}

	freeaddrinfo(servinfo);// all done with this structure

	if(p ==NULL)
	{
		fprint(stderr,"failed to find address\n");
		return -3;
	}

	if (listen(sock,MAX_CONNECTION) ==-1)
	{
		

	}

	return 0
}