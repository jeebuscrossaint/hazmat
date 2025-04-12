CC = tcc
CFLAGS = -O3 -g -Wall -s -Os -fno-stack-protector -Wunsupported -Wwrite-strings -Werror -bench -Iinclude
RELEASE_FLAGS = -O3 -Wall -s -Os -fno-stack-protector -Wunsupported -Wwrite-strings -Werror -Iinclude
LDFLAGS = -lssl -lcrypto -lcjson

# Target and sources
TARGET = hazmat
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

# Installation paths
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin
