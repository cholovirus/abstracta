#include "Affine.h"
#include "Euclides.h"

Affine::Affine(){
    srand(time(NULL));
    while(true){
        int ran= modulo(rand(),alfabeto.size());
        if(euclides(alfabeto.size(),ran)==1){
            claveA=ran;
            break;
        } 
    }
    int ran= modulo(rand(),alfabeto.size());
    claveB=ran;
    
}
Affine::Affine(int clave1, int clave2){
    claveA=euclidesE(clave1,alfabeto.size());
    claveB=clave2;
    
}

string Affine::Incriptado(string mensaje){
    string cifrado; int posicion;
    for(int i=0;i<mensaje.size();i++){
        posicion=alfabeto.find(mensaje.at(i));
        posicion=modulo((claveA*posicion)+claveB,alfabeto.size());
        cifrado+=alfabeto.at(posicion);
    }
    cout<<claveA<<" "<<claveB <<endl;
    return cifrado;
}

string Affine::Desinciptado(string cifrado){
    string decifrado; int posicion;
    for(int i=0;i<cifrado.size();i++){
        posicion=alfabeto.find(cifrado.at(i));
        posicion=modulo(claveA*(posicion-claveB),alfabeto.size());
        decifrado+=alfabeto.at(posicion);
    }
    return decifrado;
}