compn: cgn.c expr.c gen.c interp.c main.c scan.c tree.c
	cc -o compn -g cgn.c expr.c gen.c interp.c main.c scan.c tree.c

clean:
	rm -f comp1 compn *.o *.s out

testn: compn
	./compn parseTest1_stdInput
	nasm -f elf64 out.s
	cc -no-pie -o out out.o
	./out