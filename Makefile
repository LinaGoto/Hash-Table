CC	= g++
CFLAGS	= -Wall -O0 -g

all : linkedlist.exe
	./linkedlist.exe

linkedlist.exe : main.o node.o student.o
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp node.h student.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f *~ *.o *.exe

