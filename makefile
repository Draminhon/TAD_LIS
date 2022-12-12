all:
	gcc -c main.c fila.c
	gcc -o mac main.o fila.o
run:
	./mac