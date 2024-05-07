#Commands to make and test Lexer
scanner: Lexer/mainLex.c scan.c
	gcc -o scanner -g Lexer/mainLex.c scan.c
	
lexTester: Lexer/mainLex.c scan.c Lexer/lexTester.c
	make scanner
	gcc -o lexTester -g Lexer/lexTester.c
	./lexTester
###################################################

#Commands to make and test parser
parser: Parser/mainParse.c tree.c expr.c interp.c scan.c
	gcc -o parser -g expr.c interp.c Parser/mainParse.c scan.c tree.c

clean:
	rm -f scanner *.o
	rm -f lexTester *.o

	rm -f parser *.o