# Compilar

Para compilar cada algoritmo se debe crear un directorio /build/ dentro de cada carpeta de los algoritmos, esto para que el Makefile funcione bien. 

Cada instrucción del Makefile toma en cuenta las iniciales de lo que se quiere hacer.

Compilar Parte Uno Windows: cpuw
```sh
make cpuw #Compila la parte uno  en windows correspondiente al algoritmo uno
```

Compilar Parte Uno linux: cpu
```sh
make cpu #Compila la parte uno en linux correspondiente al algoritmo uno
```

Compilar Parte Dos Windows: cpdw
```sh
make cpdw #Compila la parte dos en windows correspondiente al algoritmo dos
```

Compilar Parte Dos Linux: cpd
```sh
make cpd #Compila la parte dos en linux correspondiente al algoritmo dos
```

Compilar Parte Tres Windows: cptw
```sh
make cptw #Compila la parte tres en windows correspondiente al algoritmo tres
```

Compilar Parte Tres Linux: cpt
```sh
make cpt #Compila la parte tres en linux correspondiente al algoritmo tres
```

# Ejecutar

Para ejecutar los algoritmos se toma en cuenta las iniciales de cada acción

Ejecutar Parte Uno: epu
```sh
make epu # Ejecuta la parte uno en linux, correspondiente al algoritmo uno

make epuw # Ejecuta la parte uno en windows,correspondiente al algoritmo uno
```

Ejecutar Parte Dos: epd
```sh
make epd # Ejecuta la parte dos en linux, correspondiente al algoritmo dos

make epdw # Ejecuta la parte dos en windows,correspondiente al algoritmo dos
```

Ejecutar Parte Tres: ept
```sh
make ept # Ejecuta la parte tres en linux, correspondiente al algoritmo tres

make eptw # Ejecuta la parte tres en windows, correspondiente al algoritmo tres
```

# Depurar

Para depurar algún binario, se debe escribir el comando de make apropiado para cada acción. Se debe ejecutar los comandos para compilar previamente respecto al sistema en el que se encuentran

Los comandos están escritos tomando en cuenta las iniciales de cada acción.

Depurar Parte Uno Windows
```sh
make dpuw
```

Depurar Parte Uno linux
```sh
make dpu
```

Depurar Parte Dos Windows
```sh
make dpdw
```

Depurar Parte Dos linux
```sh
make dpd
```

Depurar Parte Tres Windows
```sh
make dptw
```

Depurar Parte Tres linux
```sh
make dpt
```