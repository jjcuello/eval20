# Programas en C - Programacion No Numerica I

Coleccion de cuatro ejercicios desarrollados en lenguaje C para el curso de
Programacion No Numerica I del Instituto Universitario Santiago Marino.

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
```

El archivo `liniamiento.txt` no forma parte de este repositorio.

## Requisitos

- Compilador compatible con C99 o posterior.
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
```

Luego se puede ejecutar cada programa con:

```powershell
.\01_inventario_piezas\main.exe
.\02_estadisticas_calificaciones\main.exe
.\03_inversion_arreglo\main.exe
.\04_cadenas_texto\main.exe
```

Los programas 02, 03 y 04 muestran sus resultados y esperan que el usuario
presione Enter antes de cerrar la ventana.

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

## Archivos de resultados

Los archivos `.txt` incluidos contienen ejemplos de datos de entrada o
resultados generados por los programas. Al ejecutar nuevamente un programa,
estos archivos pueden actualizarse porque se abren en modo escritura.

## Autor

Jose Javier Cuello Camargo