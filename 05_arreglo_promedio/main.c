/*
Instituto Universitario Santiago Mariño
Programación No Numérica I
Profesor: José Luis Guzmán Hútton
Estudiante: José Javier Cuello Camargo

Ejercicio 5: Arreglo Unidimensional y Promedio con Memoria Dinámica
*/

#include <stdio.h>
#include <stdlib.h>

float calcularPromedio(int *inicio, int tam) {
    int suma = 0;
    int *p = inicio;

    for (int i = 0; i < tam; i++, p++) {
        suma += *p;
    }

    return (float)suma / tam;
}

void esperarEnter(const char *mensaje) {
    int caracter;

    while ((caracter = getchar()) != '\n' && caracter != EOF) {
    }

    printf("\n%s", mensaje);
    fflush(stdout);
    getchar();
}

int main() {
    int cantidad;
    int *numeros;
    float promedio;

    printf("Ingrese la cantidad de elementos del arreglo: ");
    scanf("%d", &cantidad);

    if (cantidad <= 0) {
        printf("La cantidad de elementos debe ser mayor que cero.\n");
        esperarEnter("Presione Enter para cerrar...\n");
        return 1;
    }

    numeros = (int *)malloc(cantidad * sizeof(int));

    if (numeros == NULL) {
        printf("No se pudo reservar la memoria necesaria.\n");
        esperarEnter("Presione Enter para cerrar...\n");
        return 1;
    }

    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", numeros + i);
    }

    esperarEnter("Presione Enter para calcular el promedio...\n");

    promedio = calcularPromedio(numeros, cantidad);

    printf("\nElementos del arreglo: ");
    for (int i = 0; i < cantidad; i++) {
        printf("%d ", *(numeros + i));
    }
    printf("\nPromedio: %.2f\n", promedio);

    if (numeros != NULL) {
        free(numeros);
        numeros = NULL;
        printf("Memoria liberada correctamente.\n");
    }

    esperarEnter("Presione Enter para cerrar...\n");
    return 0;
}