scanner: main.c scan.c
	gcc -o scanner -g main.c scan.c
	chmod +r InputTests

clean:
	rm -f scanner *.o