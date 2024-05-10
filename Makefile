parser: main.c tree.c expr.c interp.c scan.c
	gcc -o parser -g expr.c interp.c main.c scan.c tree.c

clean:
	rm -f parser *.o