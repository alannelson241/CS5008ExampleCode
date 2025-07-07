# Makefile for Hashtables Code Alongs
CC = gcc
CFLAGS = -Wall

# hashtable target
HASH_TABLE_TARGET = hashtableTest.out
HASH_TABLE_SRCS = NeuHashtable.c HashtableMain.c

all: hashtable

hashtable: $(HASH_TABLE_TARGET)

$(HASH_TABLE_TARGET): $(HASH_TABLE_SRCS)
	$(CC) $(CFLAGS) -o $(HASH_TABLE_TARGET) $(HASH_TABLE_SRCS)



clean:
	rm -f *.out
