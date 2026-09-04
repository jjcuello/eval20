/*
Instituto Universitario Santiago Mariño
Programación No Numérica I
Profesor: José Luis Guzmán Hútton
Estudiante: José Javier Cuello Camargo

Ejercicio 6: Gestión de Calificaciones con Redimensionamiento en C++
*/

#include <iostream>

using namespace std;

void leerCalificaciones(float *calificaciones, int cantidad, int inicio) {
    for (int i = 0; i < cantidad; i++) {
        cout << "Ingrese la calificacion " << inicio + i + 1 << ": ";
        cin >> *(calificaciones + inicio + i);
    }
}

float *redimensionarArreglo(float *calificaciones, int cantidadActual, int nuevaCantidad) {
    float *nuevoArreglo = new float[nuevaCantidad];

    for (int i = 0; i < cantidadActual; i++) {
        *(nuevoArreglo + i) = *(calificaciones + i);
    }

    delete[] calificaciones;
    return nuevoArreglo;
}

void mostrarCalificaciones(float *calificaciones, int cantidad) {
    cout << "\n=== LISTA FINAL DE CALIFICACIONES ===" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << "Estudiante " << i + 1 << ": " << *(calificaciones + i) << endl;
    }
}

void esperarEnter(const char *mensaje) {
    cout << "\n" << mensaje;
    cin.ignore(10000, '\n');
    cin.get();
}

int main() {
    int cantidadInicial;
    int cantidadFinal;
    float *calificaciones;

    cout << "Ingrese la cantidad inicial de estudiantes: ";
    cin >> cantidadInicial;

    if (cantidadInicial <= 0) {
        cout << "La cantidad debe ser mayor que cero." << endl;
        esperarEnter("Presione Enter para cerrar...");
        return 1;
    }

    calificaciones = new float[cantidadInicial];
    leerCalificaciones(calificaciones, cantidadInicial, 0);

    esperarEnter("Presione Enter para agregar 3 estudiantes...");

    cantidadFinal = cantidadInicial + 3;
    calificaciones = redimensionarArreglo(calificaciones, cantidadInicial, cantidadFinal);

    cout << "\nIngrese las calificaciones de los 3 estudiantes nuevos:" << endl;
    leerCalificaciones(calificaciones, 3, cantidadInicial);

    mostrarCalificaciones(calificaciones, cantidadFinal);

    if (calificaciones != NULL) {
        delete[] calificaciones;
        calificaciones = NULL;
        cout << "\nMemoria liberada correctamente." << endl;
    }

    esperarEnter("Presione Enter para cerrar...");
    return 0;
}