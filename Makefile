CC = g++ 

CFLAGS = -c

all: dumdum
dumdum: woopwoop.o LegendreQuad.o
	$(CC) woopwoop.o LegendreQuad.o -o dumdum

woopwoop.o: woopwoop.cpp
	$(CC) $(CFLAGS) woopwoop.cpp

LegendreQuad.o: LegendreQuad.cpp
	$(CC) $(CFLAGS) LegendreQuad.cpp

clean:
	rm -rf *o dumdum
