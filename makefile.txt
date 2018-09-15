CFLAGS = -Wall -g -ansi -O2
OBJS1 = main_bst.o bst.o list.o aux.o
OBJS2 = primegap.o main_primegap.o timing.o

programs = bst primegap

all : $(programs) 

bst: $(OBJS1)	
	$(CC) -o $@ $?

primegap: $(OBJS2)	
	$(CC) -o $@ $? -lgmp


clean:
	rm -rf $(OBJS1)  $(OBJS2) $(programs) *~ 
