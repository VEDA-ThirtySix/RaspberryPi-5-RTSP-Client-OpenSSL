CC = gcc
CFLAGS = -Wall -g -I. -I/usr/include/json-c
LDFLAGS = -ljson-c -lsqlite3 -lpthread

all: usrReceiver

usrReceiver: main.o user_server.o database.o
	$(CC) $(CFLAGS) -o usrReceiver main.o user_server.o database.o $(LDFLAGS)

main.o: main.c user_server.h
	$(CC) $(CFLAGS) -c main.c

user_server.o: user_server.c user_server.h
	$(CC) $(CFLAGS) -c user_server.c

database.o: database.c user_server.h
	$(CC) $(CFLAGS) -c database.c

clean:
	rm -f *.o usrReceiver
