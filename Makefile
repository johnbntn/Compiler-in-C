SRCN= cgn.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c

jlcc: $(SRCN)
	gcc -o jlcc -g $(SRCN)
	gcc -o asm -g assemble.c

clean:
	rm -f jlcc *.o *.s out asm

testn: compn input02
	./compn input02
	nasm -f elf64 out.s
	gcc -no-pie -o out out.o
	./out

tester: jlcc Tests/tester.c
	gcc -o tester -g Tests/tester.c