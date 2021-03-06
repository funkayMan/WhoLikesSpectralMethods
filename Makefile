
CFLAGS=
CC=g++
LINK=-lm
UTILITY=
FP = SourceCode/
# This is the directory to link to for LAPACK.
# It is likely that this directory will need to be changed.
LPKLIB = -L/usr/lib
# This is the linking command for LAPACK's fortran library, this will
# probably also need to be changed.
LPKLINK = -llapack

.cpp.o:	
	@echo 'Compiling $<'
	$(CC) $(CFLAGS) -c $<

TheMain: $(FP)LegendreQuad.cpp LegendreQuad.o TheMain.o
	$(CC) $(CFLAGS) $(LPKLINK) $(LPKLIB) -o $@ $@.o LegendreQuad.o $(LINK) $(UTILITY)

LegendreQuad.o: 
	$(CC) $(CFLAGS) -c $(FP)LegendreQuad.cpp $(LPKLIB) $(LPKLINK) -o LegendreQuad.o

TheMain.o:
	$(CC) $(CFLAGS) -c $(FP)TheMain.cpp $(LPKLIB) $(LPKLINK) -o TheMain.o

clean:	
	rm -f TheMain *.o *~
