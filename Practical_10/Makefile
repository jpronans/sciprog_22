CC = /usr/bin/gcc
CCFLAGS = -O3
LDFLAGS = -lm

all: hanoi 

# $@ -> Filename representing the target
# $^ filenames of all the prerequesites spearated by spaces
# Linking
hanoi: main.o
	$(CC) -o $@ $^ $(LDFLAGS)

# $< file name of the first prerequesite (mm.c in this case)

main.o: main.c
	$(CC) -Wall -c $(CCFLAGS) $<

# Tidy up
clean:
	rm *.o
	rm hanoi
