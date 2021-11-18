CC = gcc
CCFLAGS = -O3
LDFLAGS = -lm
#Comment lines

all: mmc

#linking 
mmc: main.o mm.o
	$(CC) -o $@ $^ $(LDFLAGS)
##$(CC) -o mmc main.o mm.o $(LDFLAGS)

#Compiling 
mm.o: mm.c
	$(CC) -c $(CCFLAGS) $<
##$(CC) -c $(CCFLAGS) mm.c

main.o: main.c
	$(CC) -c $(CCFLAGS) $<
##$(CC) -c $(CCFLAGS) main.c

clean:
	rm *.o
