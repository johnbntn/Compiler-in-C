scanner: mainLex.c scan.c
	gcc -o scanner -g mainLex.c scan.c
	
lexTester: mainLex.c scan.c lexTester.c
	make scanner
	gcc -o lexTester -g lexTester.c
	./lexTester

clean:
	rm -f scanner *.o
	rm -f lexTester *.o