OBJS = ConnListener.o Bot.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall -lgloox -lpthread $(DEBUG)

bot : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o bot

ConnListener.o : ConnListener.h ConnListener.cpp
	$(CC) $(CFLAGS) ConnListener.cpp

Bot.o : Bot.h Bot.cpp ConnListener.h
	$(CC) $(CFLAGS) Bot.cpp

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o *~ bot
