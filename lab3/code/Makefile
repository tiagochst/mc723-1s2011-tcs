CC = gcc
CFLAGS =  -g -ggdb
LIBS = -lm

OBJS_SEQ =  create.o  

EXEC_SEQ = create

all:
	make seq

seq: $(OBJS_SEQ)
	$(CC) $(CFLAGS) $(OBJS_SEQ) $(LIBS) -o $(EXEC_SEQ)

run: all
	./$(EXEC) $(ATB)

$(OBJS): %.o: %.c
	$(CC) -c $(CFLAGS) $<
clean:
	rm -f $(OBJS_SEQ) $(EXEC_SEQ) *~

reset: clean
	rm -f $(FILES)
