scanner: main.c scan.c
	gcc -o scanner -g main.c scan.c
	
test: main.c scan.c tests.c
	make scanner
	gcc -o tester -g tests.c
	./tester

clean:
	rm -f scanner *.o
	rm -f tester *.o