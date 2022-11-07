CFLAGS= -Wall -pedantic -std=c99 -g
INCLUDE_FLAGS = -I ./utils/include
UTILS = utils.o
BUILD_DIRECTORY= build

clean:
	rmdir ./algoritmo_uno/$(BUILD_DIRECTORY)

# Compilar Parte Uno
cpu: $(UTILS)
	gcc $(CFLAGS) -o ./algoritmo_uno/$(BUILD_DIRECTORY)/parte_uno -I ./algoritmo_uno/include $(INCLUDE_FLAGS) ./algoritmo_uno/src/alg1.c $(UTILS)

# Ejecutar Parte Uno Windows
epuw: cpu
	./algoritmo_uno/$(BUILD_DIRECTORY)/parte_uno.exe

# Ejectuar Parte Uno linux
epu: cpu
	./algoritmo_uno/$(BUILD_DIRECTORY)/parte_uno

# Compilar Parte Dos
cpd: $(UTILS)
	gcc $(CFLAGS) -o ./algoritmo_dos/$(BUILD_DIRECTORY)/parte_dos -I ./algoritmo_dos/include $(INCLUDE_FLAGS) ./algoritmo_dos/src/alg2.c $(UTILS)

# Ejecutar Parte Dos Windows
epdw: cpd
	./algoritmo_dos/$(BUILD_DIRECTORY)/parte_dos.exe

# Ejecutar Parte Dos linux
epd: cpd
	./algoritmo_dos/$(BUILD_DIRECTORY)/parte_dos

# Compilar Parte Tres
cpt: $(UTILS)
	gcc $(CFLAGS) -o ./algoritmo_tres/$(BUILD_DIRECTORY)/parte_tres -I ./algoritmo_tres/include  $(INCLUDE_FLAGS) ./algoritmo_tres/src/alg3.c $(UTILS)

# Ejecutar Parte Tres Windows
eptw: cpt
	./algoritmo_tres/$(BUILD_DIRECTORY)/parte_tres.exe

# Ejecutar Parte Tres linux
ept: cpt
	./algoritmo_tres/$(BUILD_DIRECTORY)/parte_tres

$(UTILS):
	gcc $(CFLAGS) -c $(INCLUDE_FLAGS) ./utils/src/utils.c 

.PHONY: cpu epu epuw cpd epd epdw cpt ept eptw