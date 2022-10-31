CC = /usr/bin/gcc
CCFLAGS = -O3
LDFLAGS =

all: finde practical7b

# $@ -> Filename representing the target
# $^ filenames of all the prerequesites spearated by spaces
# Linking
finde: practical7a.o
	$(CC) -o $@ $^ $(LDFLAGS)

practical7b: practical7b.o
	$(CC) -o $@ $^ $(LDFLAGS)

practical7a.o: practical7a.c
	$(CC) -Wall -c $(CCFLAGS) $<

practical7b.o: practical7b.c
	$(CC) -Wall -c $(CCFLAGS) $<



# Tidy up
clean:
	rm *.o
	rm finde practical7b 
