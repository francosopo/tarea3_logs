parte_uno: utils.o
	gcc -Wall -pedantic -std=c99 -g -o ./algoritmo_uno/build/parte_uno -I ./algoritmo_uno/include -I ./utils/include ./algoritmo_uno/src/alg1.c utils.o 

parte_dos:
	gcc -Wall -pedantic -std=c99 -g -o ./algoritmo_dos/build/parte_dos -I ./algoritmo_dos/include ./algoritmo_dos/src/alg2.c 

parte_tres:
	gcc -Wall -pedantic -std=c99 -g -o ./algoritmo_tres/build/parte_tres -I ./algoritmo_tres/include ./algoritmo_tres/src/alg3.c

utils.o:
	gcc -Wall -pedantic -std=c99 -c -I ./utils/include ./utils/src/utils.c

#libutils.a: utils.o
#	ar rcs libutils.a utils.o

.PHONY: parte_uno parte_dos parte_tres