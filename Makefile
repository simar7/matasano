CC = gcc
CFLAGS = -g -Wall
SRC_DIR = src
BUILD_DIR = bin

c1: $(SRC_DIR)/set1/c1.c
	$(CC) $(CFLAGS) $(SRC_DIR)/set1/c1.c -o $(BUILD_DIR)/set1/c1

clean:
	$(RM) bin/*
