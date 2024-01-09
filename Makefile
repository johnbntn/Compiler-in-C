scanner: main.c scan.c
	gcc -g -o scanner main.c scan.c

clean:
	rm -f scanner *.o