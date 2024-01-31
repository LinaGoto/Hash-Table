CC	= g++
CFLAGS	= -Wall -O0 -g

.PHONY: dummy

all : linkedlist.exe scripts.txt
	./linkedlist.exe < scripts.txt

linkedlist.exe : main.o node.o student.o
	$(CC) $(CFLAGS) -o $@ $^

%.o : %.cpp node.h student.h
	$(CC) $(CFLAGS) -c -o $@ $<

scripts.txt : dummy
	cp /dev/null $@
	echo add >> $@
	echo Lina Goto >> $@
	echo 452215 >> $@
	echo 3.9 >> $@
	echo add >> $@
	echo Hibiki Goto >> $@
	echo 413343 >> $@
	echo 3.2 >> $@
	echo add >> $@
	echo Kazushige Goto >> $@
	echo 382413 >> $@
	echo 3.6 >> $@
	echo add >> $@
	echo Ellie Goto >> $@
	echo 463451 >> $@
	echo 3.8 >> $@
	echo print >> $@
	echo average >> $@
	echo del >> $@
	echo 123456 >> $@
	echo print >> $@
	echo del >> $@
	echo 382413 >> $@
	echo print >> $@
	echo del >> $@
	echo 452215 >> $@
	echo print >> $@
	echo average >> $@
	echo quit >> $@

dummy :

clean :
	rm -f *~ *.o *.exe scripts.txt
