#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;
//Nota: el heap esta definido con typename T pero por como esta hecho lo voy a usar solo para el ej4
template <typename T>
class MinHeap {
private:
    T* datos;
    int cantidad;
    int capacidad;
    int* prioridades;


    int padre(int pos) {
        return (pos - 1) / 2;
    }

    int hijoIzquierdo(int pos) {
        return 2 * pos + 1;
    }

    int hijoDerecho(int pos) {
        return 2 * pos + 2;
    }

    // Devuelve true si a debe salir antes que b REVISAR
    bool menor(T a, T b) {
        if (a != b) {
            return this->prioridades[a] < this->prioridades[b];
        }

        return a < b;
    }

    void intercambiar(int pos1, int pos2) {
        T aux = datos[pos1];
        datos[pos1] = datos[pos2];
        datos[pos2] = aux;
    }

    void flotar(int pos) {
        while (pos > 0 && menor(datos[pos], datos[padre(pos)])) {
            intercambiar(pos, padre(pos));
            pos = padre(pos);
        }
    }

    void hundir(int pos) {
        while (hijoIzquierdo(pos) < cantidad) {
            int hijoMenor = hijoIzquierdo(pos);

            if (hijoDerecho(pos) < cantidad &&
                menor(datos[hijoDerecho(pos)], datos[hijoIzquierdo(pos)])) {
                hijoMenor = hijoDerecho(pos);
            }

            if (!menor(datos[hijoMenor], datos[pos])) {
                return;
            }

            intercambiar(pos, hijoMenor);
            pos = hijoMenor;
        }
    }

public:
    MinHeap(int capacidad, int* prioridades) {
        this->capacidad = capacidad;
        this->cantidad = 0;
        this->datos = new modulo*[capacidad];
        this->prioridades = prioridades;
    }

    ~MinHeap() {
        delete[] datos;
    }

    bool esVacio() {
        return cantidad == 0;
    }

    int tamanio() {
        return cantidad;
    }

    void insertar(T valor) {
        if (cantidad == capacidad) {
            return;
        }

        datos[cantidad] = valor;
        flotar(cantidad);
        cantidad++;
    }

    T obtenerMinimo() {
        if (esVacio()) {
            return nullptr;
        }

        return datos[0];
    }

    T eliminarMinimo() {
        if (esVacio()) {
            return nullptr;
        }

        T minimo = datos[0];

        datos[0] = datos[cantidad - 1];
        cantidad--;

        if (cantidad > 0) {
            hundir(0);
        }

        return minimo;
    }

    void imprimir() {
        for (int i = 0; i < cantidad; i++) {
            cout << datos[i]->numero << " ";
        }
        cout << endl;
    }

    int getCantidad() {
        return this->cantidad;
    }
};
