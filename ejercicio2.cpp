#include <cassert>
#include <string>
#include <iostream>
#include <limits>

using namespace std;
class NodoHash
{
public:
    string clave;
    int cantVeces;
    NodoHash *sig;

    NodoHash(string c) : clave(c), cantVeces(1), sig(nullptr) {};
};

class Hash
{
private:
    NodoHash **tabla;
    int cantElementos;
    int largo; // Largo del vector (primo)
    int cajonesDistintos;
    int maxEncajon;

    int funcionHash(string s)
    {
        //
    }
    string obtenerClavedelCajon(string palabra)
    {
        //
    }

public:
    // CREAR EL HASH
    Hash(int esperados)
    {
        largo = esperados;
        cantElementos = 0;
        cajonesDistintos = esperados; // DUDA
        maxEncajon = 0;
        tabla = new NodoHash *[largo];
        for (int i = 0; i < largo; i++)
        {
            tabla[i] = nullptr;
        }
    }
    // INSERTA (Revisar)
    void insertar(const string &palabra)
    {
        string clave = obtenerClavedelCajon(palabra);
        unsigned int pos = funcionHash(clave);

        NodoHash *actual = tabla[pos];
        while (actual != NULL)
        {
            if (actual->clave == clave)
            {
                actual->cantVeces++;
                // actualizarMaxCajon(); Hacer auxiliar
                return;
            }
            actual = actual->sig;
        }
        NodoHash *nuevo = new NodoHash(clave);
        nuevo->sig = tabla[pos];
        tabla[pos] = nuevo;
        cajonesDistintos++;
        // actualizarMaxCajon(); Hacer auxiliar
    }

    int cantidadElementos()
    {
        return cantElementos;
    }
    //CONSULTA CANTIDAD EN CAJON 
    int consultarCajon(string palabra)
    {
        int cantidadDelCajon=0;
        string clave = obtenerClavedelCajon(palabra);
        unsigned int pos = funcionHash(clave);

        NodoHash *actual = tabla[pos];
        while (actual != NULL){
         cantidadDelCajon++;
        }
        return cantidadDelCajon;
    }
    //Para devolver cuantos hicieron falta
    int getCajonesDistintos() const
    {
        return cajonesDistintos;
    }
    //Para devolver el cajon con mas palabras
    int getMaxPalabrasCajon() const
    {
        return maxEncajon;
    }
};
//

int main()
{
    // TODO, a ver si anda
    return 0;
}