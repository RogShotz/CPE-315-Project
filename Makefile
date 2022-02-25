CC = g++
CPPFLAGS = -wall -g

OBJS = main.o
SRCS = main.cpp

all: copystorm


copystorm: $(OBJS)
	$(CC) $(CPPFLAGS) -o copystorm $(OBJS)

main.o:	$(SRCS)
	$(CC) $(CPPFLAGS) -c main.cpp


clean:
	rm copystorm, *.o