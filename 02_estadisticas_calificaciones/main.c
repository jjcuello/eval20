/*
Instituto Universitario Santiago Mariño
Programación No Numérica I
Profesor: José Luis Guzmán Hútton
Estudiante: José Javier Cuello Camargo

Ejercicio 2: Módulo de Análisis Estadístico para Calificaciones
*/

#include <stdio.h>
#include <stdlib.h>

void leerCalificaciones(float **calificaciones, int *n) {
    printf("Ingrese cantidad de estudiantes: ");
    scanf("%d", n);

    if (*n <= 0) {
        printf("La cantidad debe ser mayor que cero.\n");
        *calificaciones = NULL;
        return;
    }

    *calificaciones = (float *)malloc(sizeof(float) * (*n));

    if (*calificaciones == NULL) {
        printf("No se pudo reservar memoria.\n");
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        printf("Ingrese la calificacion %d: ", i + 1);
        scanf("%f", &(*calificaciones)[i]);
    }
}

void calcularPromedio(float *calificaciones, int n, float *promedio) {
    float suma = 0.0f;

    for (int i = 0; i < n; i++) {
        suma += *(calificaciones + i);
    }

    *promedio = suma / n;
}

void calcularExtremos(float *calificaciones, int n, float *maximo, float *minimo) {
    *maximo = *calificaciones;
    *minimo = *calificaciones;

    for (int i = 1; i < n; i++) {
        if (*(calificaciones + i) > *maximo) {
            *maximo = *(calificaciones + i);
        }

        if (*(calificaciones + i) < *minimo) {
            *minimo = *(calificaciones + i);
        }
    }
}

int contarAprobados(float *calificaciones, int n, float umbral) {
    int contador = 0;

    for (int i = 0; i < n; i++) {
        if (*(calificaciones + i) >= umbral) {
            contador++;
        }
    }

    return contador;
}

int guardarReporte(const char *archivo, float promedio, float maximo, float minimo, int aprobados) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        return 0;
    }

    fprintf(f, "Promedio general: %.2f\n", promedio);
    fprintf(f, "Maximo: %.2f\n", maximo);
    fprintf(f, "Minimo: %.2f\n", minimo);
    fprintf(f, "Aprobados: %d\n", aprobados);

    fclose(f);
    return 1;
}

void esperarEnter(void) {
    int caracter;

    while ((caracter = getchar()) != '\n' && caracter != EOF) {
    }

    printf("\nPresione Enter para cerrar...\n");
    fflush(stdout);
    getchar();
}

int main() {
    float *calificaciones = NULL;
    int cantidad = 0;
    float promedio = 0.0f;
    float maximo = 0.0f;
    float minimo = 0.0f;
    float umbral = 10.0f;
    int aprobados;

    leerCalificaciones(&calificaciones, &cantidad);

    if (calificaciones == NULL || cantidad <= 0) {
        printf("No se puede continuar.\n");
        return 1;
    }

    calcularPromedio(calificaciones, cantidad, &promedio);
    calcularExtremos(calificaciones, cantidad, &maximo, &minimo);
    aprobados = contarAprobados(calificaciones, cantidad, umbral);

    printf("\n=== REPORTE DE CALIFICACIONES ===\n");
    printf("Promedio general: %.2f\n", promedio);
    printf("Calificacion maxima: %.2f\n", maximo);
    printf("Calificacion minima: %.2f\n", minimo);
    printf("Estudiantes aprobados (>= %.1f): %d\n",
           umbral,
            aprobados);

        if (guardarReporte("reporte_calificaciones.txt", promedio, maximo, minimo, aprobados)) {
        printf("Reporte guardado en reporte_calificaciones.txt\n");
    } else {
        printf("No se pudo guardar el reporte.\n");
    }

    free(calificaciones);
    esperarEnter();
    return 0;
}
