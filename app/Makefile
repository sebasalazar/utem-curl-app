CC=gcc
CFLAGS=-Wall -g3
LDFLAGS=-lm -lssl -lcrypto -lcurl -lz -ljson-c
OBJECTOS=main.o comunicacion.o parseador.o
MKDIR=mkdir -p
DEL=rm -fr

all: $(OBJECTOS)
	$(MKDIR) bin
	$(CC) $(CFLAGS) -o bin/app $(OBJECTOS) $(LDFLAGS)

clean:
	$(DEL) *.o app bin/

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

comunicacion.o: comunicacion.h comunicacion.c
	$(CC) $(CFLAGS) -c comunicacion.c

parseador.o: parseador.h parseador.c
	$(CC) $(CFLAGS) -c parseador.c

.PHONY: all
