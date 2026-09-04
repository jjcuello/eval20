/*
Instituto Universitario Santiago Mariño
Programación No Numérica I
Profesor: José Luis Guzmán Hútton
Estudiante: José Javier Cuello Camargo

Ejercicio 7: Matriz Dinámica Bidimensional en C++
*/

#include <iostream>
#include <iomanip>

using namespace std;

void llenarMatriz(double **matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            *(*(matriz + i) + j) = (i + 1) * (j + 1);
        }
    }
}

void mostrarMatriz(double **matriz, int filas, int columnas) {
    cout << "\n=== MATRIZ DE " << filas << " FILAS Y " << columnas << " COLUMNAS ===" << endl;

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << setw(8) << fixed << setprecision(2) << *(*(matriz + i) + j);
        }
        cout << endl;
    }
}

void liberarMatriz(double **matriz, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] *(matriz + i);
        *(matriz + i) = NULL;
    }

    delete[] matriz;
}

void esperarEnter(const char *mensaje) {
    cout << "\n" << mensaje;
    cin.ignore(10000, '\n');
    cin.get();
}

int main() {
    int filas;
    int columnas;
    double **matriz;

    cout << "Ingrese la cantidad de filas: ";
    cin >> filas;
    cout << "Ingrese la cantidad de columnas: ";
    cin >> columnas;

    if (filas <= 0 || columnas <= 0) {
        cout << "Las dimensiones deben ser mayores que cero." << endl;
        esperarEnter("Presione Enter para cerrar...");
        return 1;
    }

    matriz = new double *[filas];

    for (int i = 0; i < filas; i++) {
        *(matriz + i) = new double[columnas];
    }

    llenarMatriz(matriz, filas, columnas);

    esperarEnter("Presione Enter para mostrar la matriz...");

    mostrarMatriz(matriz, filas, columnas);
    liberarMatriz(matriz, filas);
    matriz = NULL;

    cout << "\nMemoria liberada correctamente." << endl;
    esperarEnter("Presione Enter para cerrar...");
    return 0;
}