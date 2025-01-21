# config.mk
CC = tcc
CFLAGS = -O3 -g -Wall -s -Os -fno-stack-protector -Wunsupported -Wwrite-strings -Werror -b
LDFLAGS = -lssl -lcrypto -lcjson

# Target and sources
TARGET = hazmat
SOURCES = main.c init.c shred.c master.c help.c
OBJECTS = $(SOURCES:.c=.o)

# Installation paths
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin