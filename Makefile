compn: cgn.c expr.c gen.c interp.c main.c scan.c tree.c misc.c stmt.c
	cc -o compn -g cgn.c expr.c gen.c interp.c main.c scan.c tree.c misc.c stmt.c

clean:
	rm -f comp1 compn *.o *.s out

testn: compn
	./compn test1
	nasm -f elf64 out.s
	cc -no-pie -o out out.o
	./out