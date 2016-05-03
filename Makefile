CC = gcc
CFLAGS = -g -Wall
OPENSSL_CFLAGS = -lssl -lcrypto
SRC_DIR = src
BUILD_DIR = bin
INCLUDE_DIR = /usr/local/ssl/include
LIB_DIR = /usr/local/ssl/lib

c1: $(SRC_DIR)/set1/c1.c
	$(CC) $(CFLAGS) $(SRC_DIR)/set1/c1.c -o $(BUILD_DIR)/set1/c1 $(OPENSSL_CFLAGS) -I$(INCLUDE_DIR) -L$(LIB_DIR)  

clean:
	rm -rf $(BUILD_DIR)/set1/*
