CC = /usr/bin/gcc
CCFLAGS = -O3
LDFLAGS = -lm

all: mmc 

# $@ -> Filename representing the target
# $^ filenames of all the prerequesites spearated by spaces
# Linking
mmc: main.o mm.o
	$(CC) -o $@ $^ $(LDFLAGS)

# $< file name of the first prerequesite (mm.c in this case)
mm.o: mm.c
	$(CC) -Wall -c $(CCFLAGS) $<

main.o: main.c
	$(CC) -Wall -c $(CCFLAGS) $<

# Tidy up
clean:
	rm *.o
	rm mmc 
