# Compilar

Para compilar cada algoritmo se debe crear un directorio /build/ dentro de cada carpeta de los algoritmos, esto para que el Makefile funcione bien. 

Cada instrucción del Makefile toma en cuenta las iniciales de lo que se quiere hacer.

Compilar Parte Uno: cpu
```sh
make cpu #Compila la parte uno correspondiente al algoritmo uno
```

Compilar Parte Dos: cpd
```sh
make cpd #Compila la parte dos correspondiente al algoritmo dos
```

Compilar Parte Tres: cpt
```sh
make cpt #Compila la parte tres correspondiente al algoritmo tres
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