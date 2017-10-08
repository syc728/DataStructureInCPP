# Makefile for LinkedList

CC = g++
TARGET = linkedlist
OBJS = linkedlist.o
CPPFLAGS = -std=c++11 -c -Wall

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
node.o linkedlist.o: 
	$(CC) $(CPPFLAGS) linkedlist.cpp linkedlist.h node.h

clean:
	rm -rf *o *gch $(TARGET) 
