
CFLAGS=
CC=g++
LINK=-lm
UTILITY=
FP = SourceCode/


.cpp.o:	
	@echo 'Compiling $<'
	$(CC) $(CFLAGS) -c $<

woopwoop: $(FP)LegendreQuad.cpp LegendreQuad.o woopwoop.o
	$(CC) $(CFLAGS) -o $@ $@.o LegendreQuad.o $(LINK) $(UTILITY)

woopwoop.o:	woopwoop.cpp
	$(CC) $(CFLAGS) -c $(FP)woopwoop.cpp

clean:	
	rm -f woopwoop *.o *~
