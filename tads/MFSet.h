#ifndef MFSET_H
#define MFSET_H
#include <iostream>
using namespace std;


class MFSet{
    private:
        int capacidad;
        int* padre; //padre[i] contiene el representante del grupo al que pertenece i, si padre[i] =i, entonces i es el representante del grupo
        int* tamanio;
    public:
        MFSet(int capacidad){
            this->capacidad=capacidad;
            int* padre = new int[capacidad+1]; // por lo general los grafos son de 1-v, no tienen vertice 0
            int* tamanio = new int[capacidad+1];
            for(int i=1;i<capacidad+1;i++){
                padre[i]=i; // cada v comienza en su porpio grupo
                tamanio[i] = 1;
            }
            this->padre=padre;
        }
        ~MFSet(){
            delete[] this->padre;
        }

        int find(int v){
            if(v == this->padre[v]) return this->padre[v];
            else{
                this->padre[v] = find(this->padre[v]);
            }
            return find(this->padre[v]);
        }

        void merge(int a, int b){
            int repA = find(a);
            int repB = find(b);

            if(repA == repB) return; 
            
            if(this->tamanio[repA] < this->tamanio[repB]){
                this->padre[repA] = repB;
                tamanio[repB]+= tamanio[repA];

            }else{
                this->padre[repB] = repA;
                tamanio[repA]+= tamanio[repB];
            }
            //como solo busco el tamaño de los representantes, puedo dejar basura en el array, porque no voy a volver a buscar un valor cuando ya no va a ser represetnante de su grupo
        }

};


#endif

