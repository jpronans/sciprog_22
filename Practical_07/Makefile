CC = /usr/bin/gcc
CCFLAGS = -O3
LDFLAGS =

all: finde 

# $@ -> Filename representing the target
# $^ filenames of all the prerequesites spearated by spaces
# Linking
finde: main.o
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: main.c
	$(CC) -Wall -c $(CCFLAGS) $<

# Tidy up
clean:
	rm *.o
	rm finde 
