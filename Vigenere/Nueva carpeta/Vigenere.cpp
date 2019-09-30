#include "Vigenere.h"

Vigenere::Vigenere(int len){ this-> size_=len;}

int Vigenere::modulo(int var, int modulo){
    int residuo;
    if(var<0){residuo=modulo*((-1*var/modulo)+1)+var;}
    else{residuo= var-((var/modulo)*modulo);}
    return residuo;
}

void Vigenere::Incriptado(string mensaje){
    srand(time(NULL));
    int posicion; int numrand;
    for(int i=0; i < this->size_ ;i++){
        numrand=rand() % this-> alfabeto.size();
        this-> clave+= alfabeto.at(numrand);
        posicion=alfabeto.find(mensaje[i]);
        
        posicion=modulo(posicion+numrand,alfabeto.size());
        this-> cifrado+=alfabeto.at(posicion);
    }
    cout<<"El cifrado es :"<<this-> cifrado<<endl;
    cout<<"La clave es   :"<<this-> clave<<endl;
}

void Vigenere::Desincriptado(string cifrado_,string clave_){
    string desinc;
    int sizeCifrado = cifrado_.size();

    for(int i=0;i<sizeCifrado;i++){
        int posci; int poscl;
        posci=alfabeto.find(cifrado_[i]);
        poscl=alfabeto.find(clave_[i]);
        
        int modul=modulo(posci-poscl,alfabeto.size());
        desinc+=alfabeto.at(modul);
    }
    cout<<"El mensaje decifrado es :"<<desinc;
}
