CC=g++
CFLAGS=-c -Wall -std=c++11
LFLAGS=
PROGS= server
OBJS= Server.o Nav.o ReadAudio.o

all: server client
	Server

Server.o: Server.cpp
	@$(CC) $(CFLAGS) Server.cpp

Server: Server.o Nav.o ReadAudio.o
	@$(CC) Server.o Nav.o ReadAudio.o -o server $(LFLAGS)

Client.o: Client.cpp


Nav.o: Nav.cpp
	@$(CC) $(CFLAGS) Nav.cpp

ReadAudio.o: ReadAudio.cpp
	@$(CC) $(CFLAGS) ReadAudio.cpp

clean:
	@rm $(PROGS)
	@rm $(OBJS)