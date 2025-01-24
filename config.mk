# config.mk
CC = tcc
CFLAGS = -O3 -g -Wall -s -Os -fno-stack-protector -Wunsupported -Wwrite-strings -Werror -bench
RELEASE_FLAGS = -O3 -Wall -s -Os -fno-stack-protector -Wunsupported -Wwrite-strings -Werror
LDFLAGS = -lssl -lcrypto -lcjson

# Target and sources
TARGET = hazmat
SOURCES = main.c init.c shred.c master.c help.c random.c add.c
OBJECTS = $(SOURCES:.c=.o)

# Installation paths
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
