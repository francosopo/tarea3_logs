CFLAGS= -Wall -pedantic -std=c99 -g
INCLUDE_FLAGS = -I ./utils/include
UTILS = utils.o
BUILD_DIRECTORY= build

clean:
	rmdir ./algoritmo_uno/$(BUILD_DIRECTORY)

parte_uno: $(UTILS)
	gcc $(CFLAGS) -o ./algoritmo_uno/build/parte_uno -I ./algoritmo_uno/include $(INCLUDE_FLAGS) ./algoritmo_uno/src/alg1.c $(UTILS)

parte_dos: $(UTILS)
	gcc $(CFLAGS) -o ./algoritmo_dos/build/parte_dos -I ./algoritmo_dos/include $(INCLUDE_FLAGS) ./algoritmo_dos/src/alg2.c $(UTILS)

parte_tres: $(UTILS)
	gcc $(CFLAGS) -o ./algoritmo_tres/build/parte_tres -I ./algoritmo_tres/include  $(INCLUDE_FLAGS) ./algoritmo_tres/src/alg3.c $(UTILS)

$(UTILS):
	gcc $(CFLAGS) -c $(INCLUDE_FLAGS) ./utils/src/utils.c

.PHONY: parte_uno parte_dos parte_tres