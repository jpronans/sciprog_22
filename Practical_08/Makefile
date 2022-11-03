CC = /usr/bin/gcc
CCFLAGS = -O3
LDFLAGS =

all: gcda #gcdb 

# $@ -> Filename representing the target
# $^ filenames of all the prerequesites spearated by spaces
# Linking
gcda: gcda.o
	$(CC) -o $@ $^ $(LDFLAGS)

gcdb: gcdb.o
	$(CC) -o $@ $^ $(LDFLAGS)

gcda.o: gcda.c
	$(CC) -Wall -c $(CCFLAGS) $<

gcdb.o: gcdb.c
	$(CC) -Wall -c $(CCFLAGS) $<



# Tidy up
clean:
	rm *.o
	rm gcda gcdb
