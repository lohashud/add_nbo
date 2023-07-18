#Makefile
all: add_nbo

add_nbo: add_nbo.o

add_nbo.o: add_nbo.cpp

clean:
	rm -f add_nbo
	rm -f *.o


