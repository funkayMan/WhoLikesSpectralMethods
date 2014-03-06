
CFLAGS=
CC=g++
LINK=-lm
UTILITY=
FP = SourceCode/
# This is the directory to link to for LAPACK.
# It is likely that this directory will need to be changed.
LIB = -L/usr/lib
# This is the linking command for LAPACK's fortran library, this will
# probably also need to be changed.
LPKLINK = -llapack
BLASLINK = -lblas
.cpp.o:	
	@echo 'Compiling $<'
	$(CC) $(CFLAGS) -c $<

TheMain: $(FP)LegendreQuad.cpp LegendreQuad.o BuildMassAndStiffness.o TheMain.o MatrixOperations.o
	$(CC) $(CFLAGS) -o  $@ $@.o $(LINK) LegendreQuad.o BuildMassAndStiffness.o MatrixOperations.o $(UTILITY) $(LPKLINK) $(BLASLINK) $(LIB) 

LegendreQuad.o: 
	$(CC) $(CFLAGS) -c $(FP)LegendreQuad.cpp $(LIB) $(LPKLINK) $(BLASLINK) -o LegendreQuad.o
	
BuildMassAndStiffness.o: 
	$(CC) $(CFLAGS) -c $(FP)BuildMassAndStiffness.cpp $(LIB) $(LPKLINK) $(BLASLINK) -o BuildMassAndStiffness.o

MatrixOperations.o: 
	$(CC) $(CFLAGS) -c $(FP)MatrixOperations.cpp $(LIB) $(LPKLINK) $(BLASLINK) -o MatrixOperations.o
	
TheMain.o:
	$(CC) $(CFLAGS) -c $(FP)TheMain.cpp $(LIB) $(LPKLINK) -o TheMain.o

clean:	
	rm -f TheMain *.o *~
