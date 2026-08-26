/*
Instituto Universitario Santiago Mariño
Programación No Numérica I
Profesor: José Luis Guzmán Hútton
Estudiante: José Javier Cuello Camargo

Ejercicio 4: Procesamiento de Cadenas y Extracción de Datos por Referencia Múltiple
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void analizarCadena(char *texto, int *vocales, int *consonantes, int *espacios) {
    char *p = texto;

    *vocales = 0;
    *consonantes = 0;
    *espacios = 0;

    while (*p != '\0') {
        char letra = tolower((unsigned char)*p);

        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u') {
            (*vocales)++;
        } else if (letra >= 'a' && letra <= 'z') {
            (*consonantes)++;
        } else if (letra == ' ') {
            (*espacios)++;
        }

        p++;
    }
}

void convertirMayusculas(char *texto) {
    char *p = texto;

    while (*p != '\0') {
        *p = toupper((unsigned char)*p);
        p++;
    }
}

int guardarResultado(const char *archivo, const char *texto, int vocales, int consonantes, int espacios) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        return 0;
    }

    fprintf(f, "Texto: %s\nVocales: %d\nConsonantes: %d\nEspacios: %d\n", texto, vocales, consonantes, espacios);
    fclose(f);
    return 1;
}

void esperarEnter(void) {
    printf("\nPresione Enter para cerrar...\n");
    fflush(stdout);
    getchar();
}

int main() {
    char texto[100];
    int vocales = 0;
    int consonantes = 0;
    int espacios = 0;

    printf("Ingrese una frase: ");
    fgets(texto, sizeof(texto), stdin);
    texto[strcspn(texto, "\n")] = '\0';

    analizarCadena(texto, &vocales, &consonantes, &espacios);
    convertirMayusculas(texto);

    printf("\nCadena original: %s\n", texto);
    printf("Vocales: %d\n", vocales);
    printf("Consonantes: %d\n", consonantes);
    printf("Espacios: %d\n", espacios);

    if (guardarResultado("resultado_cadena.txt", texto, vocales, consonantes, espacios)) {
        printf("Resultado guardado en resultado_cadena.txt\n");
    } else {
        printf("No se pudo guardar el resultado.\n");
    }

    esperarEnter();
    return 0;
}
