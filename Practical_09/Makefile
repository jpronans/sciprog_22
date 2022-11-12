CC = /usr/bin/gcc
CCFLAGS = -O3
LDFLAGS =

all: ms

# $@ -> Filename representing the target
# $^ filenames of all the prerequesites spearated by spaces
# Linking
ms: main.o # ms.o
	$(CC) -o $@ $^ $(LDFLAGS)

# $< file name of the first prerequesite (mm.c in this case)
#ms.o: mm.c
#	$(CC) -Wall -c $(CCFLAGS) $<

main.o: main.c
	$(CC) -Wall -c $(CCFLAGS) $<

# Tidy up
clean:
	rm *.o
	rm ms
