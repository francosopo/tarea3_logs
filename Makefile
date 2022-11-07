CFLAGS= -Wall -pedantic -std=c99 -g
INCLUDE_FLAGS = -I ./utils/include
UTILS = utils.o
BUILD_DIRECTORY= build


# Compilar Parte Uno Windows
cpuw: $(UTILS)
	-mkdir .\algoritmo_uno\$(BUILD_DIRECTORY)
	gcc $(CFLAGS) -o ./algoritmo_uno/$(BUILD_DIRECTORY)/parte_uno -I ./algoritmo_uno/include $(INCLUDE_FLAGS) ./algoritmo_uno/src/alg1.c $(UTILS)

# Compilar Parte Uno Linux
cpu: $(UTILS)
	-mkdir ./algoritmo_uno/$(BUILD_DIRECTORY)
	gcc $(CFLAGS) -o ./algoritmo_uno/$(BUILD_DIRECTORY)/parte_uno -I ./algoritmo_uno/include $(INCLUDE_FLAGS) ./algoritmo_uno/src/alg1.c $(UTILS)
# Ejecutar Parte Uno Windows
epuw: cpuw
	./algoritmo_uno/$(BUILD_DIRECTORY)/parte_uno.exe

# Ejectuar Parte Uno linux
epu: cpu
	./algoritmo_uno/$(BUILD_DIRECTORY)/parte_uno

# Compilar Parte Dos Windows
cpdw: $(UTILS)
	-mkdir .\algoritmo_dos\$(BUILD_DIRECTORY)
	gcc $(CFLAGS) -o ./algoritmo_dos/$(BUILD_DIRECTORY)/parte_dos -I ./algoritmo_dos/include $(INCLUDE_FLAGS) ./algoritmo_dos/src/alg2.c $(UTILS)

# Compilar Parte Dos linux
cpd: $(UTILS)
	-mkdir ./algoritmo_dos/$(BUILD_DIRECTORY)
	gcc $(CFLAGS) -o ./algoritmo_dos/$(BUILD_DIRECTORY)/parte_dos -I ./algoritmo_dos/include $(INCLUDE_FLAGS) ./algoritmo_dos/src/alg2.c $(UTILS)

# Ejecutar Parte Dos Windows
epdw: cpdw
	./algoritmo_dos/$(BUILD_DIRECTORY)/parte_dos.exe

# Ejecutar Parte Dos linux
epd: cpd
	./algoritmo_dos/$(BUILD_DIRECTORY)/parte_dos

# Compilar Parte Tres Windows
cptw: $(UTILS)
	-mkdir .\algoritmo_tres\$(BUILD_DIRECTORY)
	gcc $(CFLAGS) -o ./algoritmo_tres/$(BUILD_DIRECTORY)/parte_tres -I ./algoritmo_tres/include  $(INCLUDE_FLAGS) ./algoritmo_tres/src/alg3.c $(UTILS)

cpt: $(UTILS)
	-mkdir ./algoritmo_tres/$(BUILD_DIRECTORY)
	gcc $(CFLAGS) -o ./algoritmo_tres/$(BUILD_DIRECTORY)/parte_tres -I ./algoritmo_tres/include  $(INCLUDE_FLAGS) ./algoritmo_tres/src/alg3.c $(UTILS)

# Ejecutar Parte Tres Windows
eptw: cptw
	./algoritmo_tres/$(BUILD_DIRECTORY)/parte_tres.exe

# Ejecutar Parte Tres linux
ept: cpt
	./algoritmo_tres/$(BUILD_DIRECTORY)/parte_tres

$(UTILS):
	gcc $(CFLAGS) -c $(INCLUDE_FLAGS) ./utils/src/utils.c 

clean:
	rm -f *.o
	rm -rf */build
.PHONY: cpuw cpu epu epuw cpdw cpd epd epdw cpt cptw ept eptw $(UTILS) clean_w