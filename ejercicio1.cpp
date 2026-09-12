#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;


//
template <typename T>
class AVL {
    private:
        class Nodo {
            public:
                T dato;
                int altura;
                Nodo *izq;
                Nodo *der;
                Nodo(T x): dato(x), altura(1), izq(NULL), der(NULL) {}
        };
        Nodo * raiz;

        // Altura de un subarbol (0 si es vacio)
        int altura(Nodo * t) {
            if (!t) return 0;
            return t->altura;
        }

        void ActualizarAltura(Nodo * t) {
            t->altura = 1 + max(altura(t->izq), altura(t->der));
        }

        // Balance = altura(der) - altura(izq)
        // > 1: cargado a la derecha | < -1: cargado a la izquierda
        int calcBalance(Nodo * t) {
            return altura(t->der) - altura(t->izq);
        }

        // B es el hijo derecho de A; B sube y A queda como su hijo izquierdo
        Nodo * rotacionIzq(Nodo * A, Nodo * B) {
            A->der = B->izq;
            B->izq = A;
            ActualizarAltura(A);
            ActualizarAltura(B);
            return B;
        }

        // B es el hijo izquierdo de A; B sube y A queda como su hijo derecho
        Nodo * rotacionDer(Nodo * A, Nodo * B) {
            A->izq = B->der;
            B->der = A;
            ActualizarAltura(A);
            ActualizarAltura(B);
            return B;
        }

        Nodo * insertar(Nodo * t, T x) {
            if (!t) {
                return new Nodo(x);
            }
            if (t->dato == x) {
                return t; // ya estaba, no insertamos
            } else if (t->dato > x) {
                t->izq = insertar(t->izq, x);
            } else {
                t->der = insertar(t->der, x);
            }

            // Camino de vuelta: actualizar altura y rebalancear si hace falta
            ActualizarAltura(t);
            int balance = calcBalance(t);

            // DD: inserte a la derecha del hijo derecho
            if (balance > 1 && t->der->dato < x) {
                return rotacionIzq(t, t->der);
            }
            // DI: inserte a la izquierda del hijo derecho
            if (balance > 1 && t->der->dato > x) {
                t->der = rotacionDer(t->der, t->der->izq);
                return rotacionIzq(t, t->der);
            }
            // II: inserte a la izquierda del hijo izquierdo
            if (balance < -1 && t->izq->dato > x) {
                return rotacionDer(t, t->izq);
            }
            // ID: inserte a la derecha del hijo izquierdo
            if (balance < -1 && t->izq->dato < x) {
                t->izq = rotacionIzq(t->izq, t->izq->der);
                return rotacionDer(t, t->izq);
            }

            return t; // no hubo desbalance
        }

        void imprimirEnOrden(Nodo * t) {
            if (!t) return;
            imprimirEnOrden(t->izq);
            cout << t->dato << " ";
            imprimirEnOrden(t->der);
        }

        bool pertenece(T x, Nodo* arbol){
            if(!arbol) return false;

            if(arbol->dato == x)  return true;
            else{
                if(arbol->dato > x){
                    return pertenece(x,arbol->izq);
                }else return pertenece(x,arbol->der);
            }
        }

    public:
        AVL(): raiz(NULL) {}

        void insertar(T x) {
            this->raiz = insertar(this->raiz, x);
        }

        int alturaArbol() {
            return altura(this->raiz);
        }

        void imprimirEnOrden() {
            imprimirEnOrden(this->raiz);
            cout << endl;
        }
        bool pertenece(T x){
            return pertenece(x, this->raiz);
        }
};
//

//PRE: recibe un tipo M o P
//POS: toma por consola un dato (pintura o moneda) y lo inserta en el arbol correspondiente.
void ALTA(string tipo){
    if(tipo == "M"){
        long long nroMoneda=0;
        cin >> nroMoneda;
        monedas.insertar(nroMoneda);
    }else if(tipo == "P"){
        string nombrePintura;
        cin >> nombrePintura;
        pinturas.insertar(nombrePintura);
    }
}
void BUSCAR(){

}
void RANGO(){

}



int main()
{
    AVL<long long> monedas;
    AVL<string> pinturas;

    int repeticiones = 0;
    cin >> repeticiones;

    for(int i=0;i<repeticiones;i++){
        string operacion;
        string tipo;
        cin >> operacion >> tipo;
        if(operacion == "ALTA"){
            ALTA(tipo);
        }
        if(operacion == "BUSCAR"){
            BUSCAR();
        }
        if(operacion == "RANGO"){
            RANGO();
        }
        
    }
}