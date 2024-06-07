SRCN= cgn.c decl.c expr.c gen.c main.c misc.c scan.c stmt.c sym.c tree.c

compn: $(SRCN)
	cc -o compn -g $(SRCN)

clean:
	rm -f comp1 compn *.o *.s out

testn: compn input02
	./compn input02
	nasm -f elf64 out.s
	cc -no-pie -o out out.o
	./out