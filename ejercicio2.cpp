#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include <cmath>

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
    int largo; // Largo del vector (primo)
    int cajonesDistintos;
    int maxEncajon;

    
    int funcionHash(string clave, int capacidad) {
        long long h = 0;

        for (char c : clave) {
            h = (h * 31 + c) % capacidad;
        }

        return h;
    }
    

public:
    // CREAR EL HASH
    Hash(int esperados)
    {
        largo = esperados;
        cajonesDistintos = 0; // DUDA
        maxEncajon = 0;
        tabla = new NodoHash *[largo];
        for (int i = 0; i < largo; i++)
        {
            tabla[i] = nullptr;
        }
    }

    string obtenerClavedelCajon(string palabra){
        int* ocurrencias = new int[26](); //asumiendo no ñ
        for(char letra : palabra){
            ocurrencias[std::tolower(letra)-'a']++;
        }
        string clave = "";
        for(int i=0;i<26;i++){
            clave += std::to_string(ocurrencias[i]);
            clave += "#"; //pongo el # porque asi separo las ocurrencias, necesario si fuera a aparecer una palabra con 10+ letras iguales
        }
        delete[] ocurrencias;
        return clave; // clave es de la forma 1#0#0#1 etc.
    }

    // INSERTA (Revisar)
    void insertar(string claveString) // insertar recibe la CLAVE del string, no el string
    {
        int pos = funcionHash(claveString, this->largo);
        NodoHash *actual = tabla[pos];
        while (actual != NULL)
        {
            if (actual->clave == claveString){
                actual->cantVeces++;
                if (actual->cantVeces > maxEncajon){
                    maxEncajon = actual->cantVeces;
                }
                return;
            }
            actual = actual->sig;
        }
        NodoHash *nuevo = new NodoHash(claveString);
        nuevo->sig = tabla[pos];
        tabla[pos] = nuevo;
        cajonesDistintos++;

        if (nuevo->cantVeces > maxEncajon){
            maxEncajon = nuevo->cantVeces;
        }
    }

    //CONSULTA CANTIDAD EN CAJON 
    int consultarCajon(string palabra)
    {
        string clave = obtenerClavedelCajon(palabra);
        unsigned int pos = funcionHash(clave, this->largo);

        NodoHash *actual = tabla[pos];
        while (actual != NULL){
            if(clave == actual->clave){
                return actual->cantVeces;
            }
            actual = actual->sig;
        }
        return 0;
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

    void actualizarMaxCajon(){
        int maximo=0;
        for(int i=0;i<this->largo;i++){
            NodoHash* actual = this->tabla[i];
            while(actual){
                if (actual->cantVeces>maximo) maximo = actual->cantVeces;
                actual = actual->sig;
            }
        }
        this->maxEncajon = maximo;
    }

    

};
//

int main()
{
    int palabrasARegistrar = 0;
    cin >> palabrasARegistrar;
    int capacidadCalculada = ceil(palabrasARegistrar/0.7); // capacidad necesaria para que el factor de carga sea aprox 0.7
    Hash* hash = new Hash(capacidadCalculada);

    for(int i=0; i < palabrasARegistrar;i++){
        string palabra = "";
        cin >> palabra ;
        hash->insertar(hash->obtenerClavedelCajon(palabra));
    }

    int cantConsultas = 0;
    cin >> cantConsultas;
    for(int i=0; i<cantConsultas;i++){
        string palabra = "";
        cin >> palabra ;
        cout << hash->consultarCajon(palabra) << "\n" ;
    }

    cout << hash->getCajonesDistintos()<< " " << hash->getMaxPalabrasCajon() << "\n";


    return 0;
}