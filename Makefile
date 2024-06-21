SRCN= cgn.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c

jlcc: $(SRCN) assemble.c
	gcc -o jlcc -g $(SRCN)
	gcc -o asm -g assemble.c

clean:
	rm -f jlcc *.o *.s out asm

tester: jlcc Tests/tester.c
	gcc -o tester -g Tests/tester.c