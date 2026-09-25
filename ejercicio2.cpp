#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;


//
class NodoHash {
    public:
        string dato;
        int cantVeces;
        NodoHash* sig;

        NodoHash(string dato):dato(dato), cantVeces(1), sig(nullptr) {}; 
};

class Hash {
    private:
        NodoHash** array;
        int cantElementos;
        int largo; // Largo del vector (primo)

        int funcionHash(string s) {
           //
        }

    public:
        Hash(int esperados) {
           
        }

        ~Hash() {
            //
        }

        void insertar(string s) {
          //
        }

        int cantidadElementos() {
            return cantElementos;
        }
        
        int consultarCajon(string palabra){
            //
        }
};
//



int main()
{
    // TODO
    return 0;
}