stack.o: nmath.c
	gcc -c nmath.c

driver.o: driver.c
	gcc -c driver.c

driver: nmath.o driver.o
	gcc nmath.o driver.o -o driver

clean:
	rm -f *.o
	rm -f *~
