CC = g++
CFLAGS = -g

all: Main

composer.o:	composer.h composer.cpp
	$(CC) $(CFLAGS) -c composer.cpp

database.o:	database.h database.cpp
	$(CC) $(CFLAGS) -c database.cpp

API.o:	API.h API.cpp
	$(CC) $(CFLAGS) -c API.cpp

Main:	composer.o database.o API.o
	$(CC) $(CFLAGS) composer.o database.o API.o Main.cpp -o ComposerDB

clean:
	rm -f core *.o *~
