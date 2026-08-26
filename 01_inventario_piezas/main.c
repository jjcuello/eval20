/*
Instituto Universitario Santiago Mariño
Programación No Numérica I
Profesor: José Luis Guzmán Hútton
Estudiante: José Javier Cuello Camargo

Ejercicio 1: Sistema de Control e Inventario de Piezas
*/

#include <stdio.h>
#define MAX_PIEZAS 10

typedef struct {
    int codigo;
    char descripcion[50];
    int stock;
    float costo;
} Pieza;

int cargarInventario(Pieza *inventario, int *cantidad, const char *archivo) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        return 0;
    }

    int i = 0;
    while (fscanf(f, "%d|%49[^|]|%d|%f\n",
                 &inventario[i].codigo,
                 inventario[i].descripcion,
                 &inventario[i].stock,
                 &inventario[i].costo) == 4 && i < MAX_PIEZAS) {
        i++;
    }

    *cantidad = i;
    fclose(f);
    return 1;
}

int guardarInventario(const Pieza *inventario, int cantidad, const char *archivo) {
    FILE *f = fopen(archivo, "w");
    if (f == NULL) {
        return 0;
    }

    for (int i = 0; i < cantidad; i++) {
        fprintf(f, "%d|%s|%d|%.2f\n",
                inventario[i].codigo,
                inventario[i].descripcion,
                inventario[i].stock,
                inventario[i].costo);
    }

    fclose(f);
    return 1;
}

void registrarPieza(Pieza *inventario, int *cantidad) {
    if (*cantidad >= MAX_PIEZAS) {
        printf("Inventario lleno. No se pueden registrar más piezas.\n");
        return;
    }

    Pieza *p = inventario + *cantidad;

    printf("Ingrese codigo: ");
    scanf("%d", &p->codigo);

    printf("Ingrese descripcion: ");
    scanf(" %49[^\n]", p->descripcion);

    printf("Ingrese stock: ");
    scanf("%d", &p->stock);

    printf("Ingrese costo unitario: ");
    scanf("%f", &p->costo);

    (*cantidad)++;
    printf("Pieza registrada correctamente.\n\n");
}

void mostrarInventario(Pieza *inventario, int cantidad) {
    if (cantidad == 0) {
        printf("No hay piezas registradas.\n");
        return;
    }

    Pieza *p = inventario;

    printf("\n--- INVENTARIO ACTUAL ---\n");
    for (int i = 0; i < cantidad; i++, p++) {
        printf("Codigo: %d | Descripcion: %s | Stock: %d | Costo: %.2f | Valor total: %.2f\n",
               p->codigo,
               p->descripcion,
               p->stock,
               p->costo,
               p->stock * p->costo);
    }
    printf("-------------------------\n\n");
}

void consultarStock(Pieza *inventario, int cantidad) {
    int codigo;

    printf("Ingrese el codigo de la pieza: ");
    scanf("%d", &codigo);

    Pieza *p = inventario;
    for (int i = 0; i < cantidad; i++, p++) {
        if (p->codigo == codigo) {
            printf("Pieza encontrada.\n");
            printf("Descripcion: %s\n", p->descripcion);
            printf("Stock actual: %d\n", p->stock);
            printf("Valor total: %.2f\n\n", p->stock * p->costo);
            return;
        }
    }

    printf("Pieza no encontrada.\n\n");
}

void actualizarStock(Pieza *inventario, int cantidad) {
    int codigo;
    int movimiento;

    printf("Ingrese codigo de la pieza: ");
    scanf("%d", &codigo);

    Pieza *p = inventario;
    for (int i = 0; i < cantidad; i++, p++) {
        if (p->codigo == codigo) {
            printf("Ingrese cantidad a sumar o restar (use numero negativo para salida): ");
            scanf("%d", &movimiento);
            p->stock += movimiento;

            if (p->stock < 0) {
                p->stock = 0;
                printf("El stock no puede quedar negativo. Se ajusto a 0.\n");
            }

            printf("Stock actualizado: %d\n\n", p->stock);
            return;
        }
    }

    printf("Pieza no encontrada.\n\n");
}

int main() {
    Pieza inventario[MAX_PIEZAS];
    int cantidad = 0;
    int opcion;
    const char *archivo = "inventario.txt";

    cargarInventario(inventario, &cantidad, archivo);

    do {
        printf("\n=== MENU INVENTARIO ===\n");
        printf("1. Registrar pieza\n");
        printf("2. Consultar stock\n");
        printf("3. Actualizar stock\n");
        printf("4. Mostrar inventario\n");
        printf("5. Guardar y salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                registrarPieza(inventario, &cantidad);
                break;
            case 2:
                consultarStock(inventario, cantidad);
                break;
            case 3:
                actualizarStock(inventario, cantidad);
                break;
            case 4:
                mostrarInventario(inventario, cantidad);
                break;
            case 5:
                if (guardarInventario(inventario, cantidad, archivo)) {
                    printf("Datos guardados en inventario.txt\n");
                } else {
                    printf("No se pudo guardar la informacion.\n");
                }
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion invalida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}
