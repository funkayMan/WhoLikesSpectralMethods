CC=g++
CFLAG = -c
LINK = -lm 

MadeFile: funkayMain.cpp moo.o goo.o
	$(CC) funkayMain.cpp -o $@ moo.o goo.o $(LINK)
	
moo.o: moo.cpp goo.o 
	$(CC) $(CFLAG) moo.cpp -o $@ $(LINK)
		
goo.o: goo.cpp
	$(CC) $(CFLAG) goo.cpp -o $@ 

clean:	
	rm -f MadeFile *.o *~
