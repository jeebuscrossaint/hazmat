# Compiler and flags
CC = tcc
CFLAGS = -O3 -b -g -Wall -std=c11

# Target and sources
TARGET = hazmat
SOURCES = main.c init.c shred.c  # List all your (additional) source files here
OBJECTS = $(SOURCES:.c=.o)

# Installation paths
PREFIX = /usr/local
BINDIR = $(PREFIX)/bin