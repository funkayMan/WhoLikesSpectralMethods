
CFLAGS=
CC=g++
LINK=-lm
UTILITY=


.cpp.o:	
	@echo 'Compiling $<'
	$(CC) $(CFLAGS) -c $<

woopwoop: LegendreQuad.cpp LegendreQuad.o woopwoop.o
	$(CC) $(CFLAGS) -o $@ $@.o LegendreQuad.o $(LINK) $(UTILITY)

woopwoop.o:	woopwoop.cpp
	$(CC) $(CFLAGS) -c woopwoop.cpp

clean:	
	rm -f woopwoop *.o *~
