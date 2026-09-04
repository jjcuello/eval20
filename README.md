# Programas en C y C++ - Programacion No Numerica I

Coleccion de siete ejercicios desarrollados en lenguajes C y C++ para el curso
de Programacion No Numerica I del Instituto Universitario Santiago Marino.

## Estructura del proyecto

```text
01_inventario_piezas/
    main.c
    inventario.txt
02_estadisticas_calificaciones/
    main.c
    reporte_calificaciones.txt
03_inversion_arreglo/
    main.c
    estadisticas_arreglo.txt
04_cadenas_texto/
    main.c
    resultado_cadena.txt
05_arreglo_promedio/
    main.c
06_gestion_calificaciones/
    main.cpp
07_matriz_dinamica/
    main.cpp
```

## Requisitos

- Compilador compatible con C99 o posterior.
- Compilador compatible con C++.
- Consola de comandos para ejecutar los programas.

En Windows se puede utilizar GCC mediante MinGW. Los comandos de esta
documentacion se ejecutan desde la carpeta raiz del proyecto.

## Compilacion y ejecucion

Cada programa es independiente y debe compilarse en su propia carpeta:

```powershell
gcc .\01_inventario_piezas\main.c -o .\01_inventario_piezas\main.exe
gcc .\02_estadisticas_calificaciones\main.c -o .\02_estadisticas_calificaciones\main.exe
gcc .\03_inversion_arreglo\main.c -o .\03_inversion_arreglo\main.exe
gcc .\04_cadenas_texto\main.c -o .\04_cadenas_texto\main.exe
gcc .\05_arreglo_promedio\main.c -o .\05_arreglo_promedio\main.exe
g++ .\06_gestion_calificaciones\main.cpp -o .\06_gestion_calificaciones\main.exe
g++ .\07_matriz_dinamica\main.cpp -o .\07_matriz_dinamica\main.exe
```

Luego se puede ejecutar cada programa con:

```powershell
.\01_inventario_piezas\main.exe
.\02_estadisticas_calificaciones\main.exe
.\03_inversion_arreglo\main.exe
.\04_cadenas_texto\main.exe
.\05_arreglo_promedio\main.exe
.\06_gestion_calificaciones\main.exe
.\07_matriz_dinamica\main.exe
```

Los programas 02 al 07 muestran sus resultados y esperan que el usuario
presione Enter durante la ejecucion o antes de cerrar la ventana.

## Descripcion de los ejercicios

### 1. Inventario de piezas

Ruta: `01_inventario_piezas/main.c`

Implementa un sistema de inventario usando la estructura `Pieza`. Permite:

- Registrar piezas con codigo, descripcion, stock y costo.
- Consultar el stock mediante el codigo de una pieza.
- Actualizar el stock sumando o restando unidades.
- Mostrar el inventario y el valor total de cada pieza.
- Guardar la informacion en `inventario.txt`.

El inventario admite hasta 10 piezas.

### 2. Estadisticas de calificaciones

Ruta: `02_estadisticas_calificaciones/main.c`

Solicita la cantidad de estudiantes y sus calificaciones. Calcula el promedio
general, la calificacion maxima, la calificacion minima y la cantidad de
estudiantes aprobados con una nota mayor o igual a 10. Los resultados se
muestran en pantalla y se guardan en `reporte_calificaciones.txt`.

### 3. Inversion y estadisticas de un arreglo

Ruta: `03_inversion_arreglo/main.c`

Trabaja con un arreglo de enteros y aritmetica de apuntadores. Muestra el
arreglo original, invierte sus elementos por referencia y calcula el maximo,
el minimo y el promedio. Las estadisticas se guardan en
`estadisticas_arreglo.txt`.

### 4. Procesamiento de cadenas

Ruta: `04_cadenas_texto/main.c`

Recibe una frase, cuenta sus vocales, consonantes y espacios, y convierte el
texto a mayusculas. El resultado se muestra en pantalla y se guarda en
`resultado_cadena.txt`.

### 5. Arreglo unidimensional y promedio

Ruta: `05_arreglo_promedio/main.c`

Solicita la cantidad de enteros que formaran un arreglo y reserva la memoria
necesaria con `malloc`. Permite ingresar los valores, calcula su promedio y
libera correctamente la memoria con `free` antes de finalizar.

### 6. Gestion de calificaciones con redimensionamiento

Ruta: `06_gestion_calificaciones/main.cpp`

Gestiona un arreglo dinamico de calificaciones con `new` y `delete[]`.
Despues de registrar las notas iniciales, redimensiona el arreglo para agregar
tres estudiantes, muestra la lista final y libera toda la memoria reservada.

### 7. Matriz dinamica bidimensional

Ruta: `07_matriz_dinamica/main.cpp`

Solicita las dimensiones de una matriz de valores `double` y reserva memoria
para el arreglo de filas y cada fila individualmente. Llena la matriz con el
producto de sus indices, la muestra en formato de tabla y libera la memoria en
orden inverso.

## Archivos de resultados

Los archivos `.txt` incluidos contienen ejemplos de datos de entrada o
resultados generados por los programas. Al ejecutar nuevamente un programa,
estos archivos pueden actualizarse porque se abren en modo escritura.

## Autor

Jose Javier Cuello Camargo
