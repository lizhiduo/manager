CC=gcc
CFLAGS=

TAGET=test

SRCS=main.c dev_recv.c dev1_recv.c receive_manager.c

OBJS=$(SRCS:.c=.o)

$(TAGET) : $(OBJS)
	$(CC) -o $@ $^

clean:
	rm -rf $(TAGET) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -o $@ -c $<

