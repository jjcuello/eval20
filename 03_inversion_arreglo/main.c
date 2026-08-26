/*
Instituto Universitario Santiago Mariño
Programación No Numérica I
Profesor: José Luis Guzmán Hútton
Estudiante: José Javier Cuello Camargo

Ejercicio 3: Análisis e Inversión de una Secuencia Numérica por Referencia
*/

#include <stdio.h>

void invertirArreglo(int *inicio, int tam) {
    int *fin = inicio + tam - 1;

    while (inicio < fin) {
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;

        inicio++;
        fin--;
    }
}

void calcularEstadisticas(int *inicio, int tam, int *maximo, int *minimo, float *promedio) {
    int suma = 0;
    int *p = inicio;

    *maximo = *inicio;
    *minimo = *inicio;

    for (int i = 0; i < tam; i++, p++) {
        suma += *p;

        if (*p > *maximo) {
            *maximo = *p;
        }

        if (*p < *minimo) {
            *minimo = *p;
        }
    }

    *promedio = (float)suma / tam;
}

int guardarEstadisticas(const char *archivo, int maximo, int minimo, float promedio) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        return 0;
    }

    fprintf(f, "Maximo: %d\nMinimo: %d\nPromedio: %.2f\n", maximo, minimo, promedio);
    fclose(f);
    return 1;
}

void esperarEnter(void) {
    printf("\nPresione Enter para cerrar...\n");
    fflush(stdout);
    getchar();
}

int main() {
    int datos[10] = {12, 5, 9, 1, 18, 7, 3, 14, 6, 10};
    int *ptr = datos;
    int maximo;
    int minimo;
    float promedio;

    printf("Arreglo original: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    invertirArreglo(ptr, 10);

    printf("Arreglo invertido: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    calcularEstadisticas(ptr, 10, &maximo, &minimo, &promedio);

    printf("Valor maximo: %d\n", maximo);
    printf("Valor minimo: %d\n", minimo);
    printf("Promedio: %.2f\n", promedio);

    if (guardarEstadisticas("estadisticas_arreglo.txt", maximo, minimo, promedio)) {
        printf("Estadisticas guardadas en estadisticas_arreglo.txt\n");
    } else {
        printf("No se pudieron guardar las estadisticas.\n");
    }

    esperarEnter();
    return 0;
}
