CC=gcc
KLIENT=gniazda
SERWER=serverstud


all: klient serwer

klient: ${KLIENT}.c
	$(CC) ${KLIENT}.c -o ${KLIENT}

serwer: ${SERWER}.c
	$(CC) ${SERWER}.c -o ${SERWER}

clean:
	rm -f ${KLIENT} ${SERWER}
