parser: main.c tree.c expr.c interp.c scan.c
	gcc -o parser -g expr.c interp.c Parser/mainParse.c scan.c tree.c

clean:
	rm -f parser *.o