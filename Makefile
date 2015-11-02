CFLAGS=-Wall -Werror -O2

all: pact

pact: pact.o
	$(CC) -o pact pact.o

clean:
	rm -f pact *.o
