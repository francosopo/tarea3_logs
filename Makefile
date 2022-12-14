CFLAGS= -Wall -pedantic -std=c99 -g -O
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
epuw:
	./algoritmo_uno/$(BUILD_DIRECTORY)/parte_uno.exe

# Ejectuar Parte Uno linux
epu:
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
epdw:
	./algoritmo_dos/$(BUILD_DIRECTORY)/parte_dos.exe

# Ejecutar Parte Dos linux
epd:
	./algoritmo_dos/$(BUILD_DIRECTORY)/parte_dos

# Compilar Parte Tres Windows
cptw: $(UTILS)
	-mkdir .\algoritmo_tres\$(BUILD_DIRECTORY)
	gcc $(CFLAGS) -o ./algoritmo_tres/$(BUILD_DIRECTORY)/parte_tres -I ./algoritmo_tres/include  $(INCLUDE_FLAGS) ./algoritmo_tres/src/alg3.c $(UTILS)

cpt: $(UTILS)
	-mkdir ./algoritmo_tres/$(BUILD_DIRECTORY)
	gcc $(CFLAGS) -o ./algoritmo_tres/$(BUILD_DIRECTORY)/parte_tres -I ./algoritmo_tres/include  $(INCLUDE_FLAGS) ./algoritmo_tres/src/alg3.c $(UTILS) -lm

# Ejecutar Parte Tres Windows
eptw:
	./algoritmo_tres/$(BUILD_DIRECTORY)/parte_tres.exe

# Ejecutar Parte Tres linux
ept:
	./algoritmo_tres/$(BUILD_DIRECTORY)/parte_tres

$(UTILS):
	gcc $(CFLAGS) -c $(INCLUDE_FLAGS) ./utils/src/utils.c 

# Debuggear Parte Uno Windows
dpuw:
	gdb .\algoritmo_uno\build\parte_uno.exe

# Debuggear Parte Uno linux
dpu:
	gdb ./algoritmo_uno/build/parte_uno

# Debuggear Parte Dos Windows
dpdw:
	gdb .\algoritmo_dos\build\parte_dos.exe

# Debuggear Parte Dos linux
dpd:
	gdb ./algoritmo_dos/build/parte_dos

# Debuggear Parte Tres Windows
dptw:
	gdb .\algoritmo_tres\build\parte_tres.exe

# Debuggear Parte Uno linux
dpt:
	gdb ./algoritmo_tres/build/parte_tres

clean:
	rm -f *.o
	rm -rf */build
.PHONY: cpuw cpu epu epuw cpdw cpd epd epdw cpt cptw ept eptw $(UTILS) clean_w