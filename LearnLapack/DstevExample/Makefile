CC = g++
LPKLIB = -L/usr/lib

tridiageig: routine.cpp
	$(CC) routine.cpp -llapack $(LPKLIB) -o $@
	
	
clean: tridiageig
	rm tridiageig
