#include "Escitala.h"

Escitala ::Escitala (int fil, int col){
    columna=col;
    fila=fil;
}

int Escitala::modulo(int var,int modulo){
    int residuo;
    if(var<0){residuo=modulo*((-1*var/modulo)+1)+var;}
    else{residuo= var-((var/modulo)*modulo);}
    return residuo;
}

string Escitala::Incriptado(string mensaje){
    string cifrado;
    int posicion; int j=0; int len=fila*columna;
    
    mensaje.resize(len,'w');
    for(int i=0 ; i < len ; i++ ){
        if(j>=len){j=modulo(j,(len-1));}
        posicion=alfabeto.find(mensaje.at(j));
        j+=columna;
        cifrado+=alfabeto.at(posicion);          
    }
    return cifrado;
}

string Escitala::Descifrado(string mensaje,int fil, int col){
    string descifrado;
    int len= fil*col;
    int j=0; int posicion;
    for(int i=0;i<len;i++){
        posicion=alfabeto.find(mensaje.at(j));
        descifrado+=alfabeto.at(posicion);
        j+=fil;
        if(j>=fil*col){j=modulo(j,(len-1));}
    }
    return descifrado;

}
