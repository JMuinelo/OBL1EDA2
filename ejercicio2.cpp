#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;
class NodoHash {
    public:
        string palabra;
        int repeticiones;
        NodoHash* sig;
        NodoHash(string c) : clave(c), cantidad(0), sig(nullptr) {}
};

class Hash {
    private:
        NodoHash * vec;
        int cantElementos;
        int largo;

        int funcionHash(string s) {
            //hacer con el array
        }
    
    public:
        Hash(int esperados) {
            //constructor
        }

        ~Hash() {
            delete[] this->vec;
        }

        void insertar(string s) {
            //insertar con la clave del array ese
        }

        int cantidadElementos() {
            return cantElementos;
        }
        void borrar(string s){

        }
        void esta (string s){

        }
int main()
{
    // TODO
    return 0;
}