/*Na komputerze o adresie internetowym 153.19.1.240 uruchomiony jest serwer 
 *  prostej funkcji arytmetycznej, który przez port UDP o numerze 5000 
 *  przyjmuje jedną liczbę całkowitą czterobajtową (int)
 *  i w odpowiedzi odsyła liczbę tego samego typu.*/

/*Napisać program klienta, który komunikuje się z tym serwerem i odgadnąć
 *  jaką funkcję oblicza serwer. (Odpowiedź należy umieścić w komentarzu na
 *  początku pliku ze źródłem zaimplementowanego klienta.)*/
/*Uwaga:*/
/*1. Należy pamiętać o przekształceniu danych i adresu do postaci sieciowej i na odwrót.*/
/*2. W przypadku, gdyby serwer nie był włączony (np. niespodziewany restart komputera sigma)
 * należy kontaktować się z drem inż. Jerzym Skurczyńskim.*/

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <signal.h>
#include <arpa/inet.h>
main(int argc, char* argv[]) {
	int s = socket(AF_INET, SOCK_DGRAM, 0);
	int buff;
   	struct sockaddr_in sock;
	bzero((char*) &sock, sizeof(sock));
	sock.sin_family = AF_INET;
	/*sock.sin_addr.s_addr = inet_addr("153.19.1.240");*/
	inet_aton("153.19.1.240", &sock.sin_addr);
	sock.sin_port = htons( (ushort) 5000);
	int dlugosc = sizeof(sock);
	printf("Łącze się z serwerem... \n");
	printf("Połączyłem się z serwerem.. \n");
	buff = atoi(argv[1]);
	printf("Buff to %d\n", buff);
	buff = htonl(buff);
	printf("Buff htonl to %d\n", buff);
	sleep(1);
	printf("Wysyłam bufor na serwer... \n");
	if (sendto(s, (char*) &buff, sizeof(int),0, (struct sockaddr *) &sock, dlugosc) == -1) {
		printf("Błąd przy wypisaniu pliku\n");
	}
	printf("Czekam na odpowiedź serwera... \n");
    recvfrom(s,(char *) &buff,sizeof(int),0,(struct sockaddr *) &sock,&dlugosc);
	buff = ntohl(buff);
	close(s);

	printf("Wynik to: %d\n", buff);
}
