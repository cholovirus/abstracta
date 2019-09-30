#include "Enigma.h"

Enigma::Enigma(string clave){
    this->clave=clave;
    rotor1=rotorRan(alfabeto);
    rotor2=rotorRan(rotor1);
    rotor3=rotorRan(rotor2);
}
Enigma::Enigma(string r1,string r2, string r3){
    rotor1=r1;
    rotor2=r2;
    rotor3=r3;
}

int Enigma::modulo(int var, int modulo){
    int residuo;
    if(var<0){residuo=modulo*((-1*var/modulo)+1)+var;}
    else{residuo= var-((var/modulo)*modulo);}
    return residuo;
}

string Enigma::rotorRan(string arr){
    srand(time(NULL));
    string random; string aux=arr;
    for(int i=0;i<arr.size();i++){
        int ran= rand()%aux.size();
        random+=aux.at(ran);
        aux.erase(aux.begin()+ran);
    }
    return random;
}

string Enigma::Incriptado(string mensaje){
    string cifrado ; int posicion;
    int rotor1P=alfabeto.find(clave.at(2));
    int rotor2P=alfabeto.find(clave.at(1));
    int rotor3P=alfabeto.find(clave.at(0));
    
    for(int i=0; i<mensaje.size();i++){
        posicion=modulo(alfabeto.find(mensaje.at(i))-rotor1P,alfabeto.size());
        posicion=modulo(alfabeto.find(rotor1.at(posicion))-rotor2P,alfabeto.size());
        posicion=modulo(alfabeto.find(rotor2.at(posicion))-rotor3P,alfabeto.size());
        cifrado+=rotor3.at(posicion);
        if(i>=4){ 
            rotor1P++; 
            rotor1P=modulo(rotor1P,alfabeto.size());
            if(i>=8){
                rotor2P++; 
                rotor2P=modulo(rotor2P,alfabeto.size());
                if(i>=12){
                    rotor3P++; 
                    rotor3P=modulo(rotor3P,alfabeto.size());
                }
            }      
        }
    }
    cout<<rotor1<<endl;
    cout<<rotor2<<endl;
    cout<<rotor3<<endl;
    return cifrado;
}


string Enigma::Desincriptado(string cifrado, string cl){
    

    string descifrado; int posicion; 
     
    int rotor1P=alfabeto.find(cl.at(2));
    int rotor2P=alfabeto.find(cl.at(1));
    int rotor3P=alfabeto.find(cl.at(0));
    
    for(int i=0; i<cifrado.size();i++){
        posicion=modulo(rotor3.find(cifrado.at(i))+rotor3P,alfabeto.size());
        posicion=modulo(rotor2.find(alfabeto.at(posicion))+rotor2P,alfabeto.size());
        posicion=modulo(rotor1.find(alfabeto.at(posicion))+rotor1P,alfabeto.size());
        descifrado+=alfabeto.at(posicion);
        if(i>=4){ 
            rotor1P++; 
            rotor1P=modulo(rotor1P,alfabeto.size());
            if(i>=8){
                rotor2P++; 
                rotor2P=modulo(rotor2P,alfabeto.size());
                if(i>=12){
                    rotor3P++; 
                    rotor3P=modulo(rotor3P,alfabeto.size());
                }
            }      
        }
    }
    return descifrado;
}