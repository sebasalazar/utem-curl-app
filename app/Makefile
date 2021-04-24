CC=gcc
CFLAGS=-Wall -g3
LDFLAGS=-lm -lssl -lcrypto -lcurl -lz
OBJECTOS=comunicacion.o
DEL=rm -fr

comunicacion.o: comunicacion.h comunicacion.c
	$(CC) $(CFLAGS) -c comunicacion.c

main: main.c $(OBJECTOS)
	$(CC) $(CFLAGS) -o app main.c $(OBJECTOS) $(LDFLAGS)

clean:
	$(DEL) *.o app bin/

.PHONY: dist
dist: clean main
	mkdir -p bin
	cp -r app bin/
	