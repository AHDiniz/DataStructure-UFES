# TAD Fila usando pilha

progfila: main.o fila.o pilha.o
	gcc -o progfila main.o fila.o pilha.o

main.o: main.c fila.o pilha.o
	gcc -c main.c pilha.o fila.o

fila.o: fila.c fila.h pilha.o
	gcc -c fila.c pilha.o

pilha.o: pilha.c
	gcc -c pilha.c

clean:
	rm *.o