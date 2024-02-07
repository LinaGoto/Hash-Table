CC	= g++
CFLAGS	= -Wall -O0 -g

.PHONY: dummy

all : linkedlist.exe scripts.txt
	./linkedlist.exe < scripts.txt

linkedlist.exe : main.o node.o student.o
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp node.h student.h
	$(CC) $(CFLAGS) -c -o $@ $<

scripts.txt : genstudent.exe Makefile
	./genstudent.exe 1500 > $@

genstudent.exe : genstudent.cpp
	$(CC) $(CFLAGS) -o $@ $^

dummy :

clean :
	rm -f *~ *.o *.exe scripts.txt
