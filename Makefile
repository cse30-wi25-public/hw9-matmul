CC = gcc
OBJS = main.o
WARN = -Wall -Wextra -Wformat-security
DEBUG = -g
CFLAGS = -I. -std=gnu17 $(DEBUG) $(WARN) -O0
LIBS =

.PHONY: clean

all: $(OBJS)
	$(CC) $(CFLAGS) -DIJK -o matmul_ijk matmul.c $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) -DIKJ -o matmul_ikj matmul.c $(OBJS) $(LIBS)

clean:
	rm -f $(OBJS) matmul_ijk matmul_ikj
