#include "Enigma.h"

Enigma::Enigma(string clave){
    this->clave=clave;
    rotor1=rotorRan(alfabeto);
    rotor2=rotorRan(rotor1);
    rotor3=rotorRan(rotor2);
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
    
    string cifrado; int posicion; string aux;
    int rotor1P=alfabeto.find(clave.at(0));
    int rotor2P=alfabeto.find(clave.at(1));
    int rotor3P=alfabeto.find(clave.at(2));
    for(int i=0;i<mensaje.size();i++){
        posicion=modulo(alfabeto.find(mensaje.at(i))-rotor1P,alfabeto.size());
        aux=rotor1.at(posicion);
        posicion= modulo(alfabeto.find(aux)-rotor2P,alfabeto.size());
        aux=rotor2.at(posicion);
        posicion= modulo(alfabeto.find(aux)-rotor3P,alfabeto.size());
        
        cifrado+=rotor3.at(posicion);
        rotor1P++;
        if(rotor1P>= alfabeto.size() || rotor2P>=alfabeto.size()|| rotor3P>=alfabeto.size()){
            rotor1P=modulo(rotor1P,alfabeto.size());
            
            if(!rotor1P){rotor2P=modulo(rotor2P,alfabeto.size());rotor2P++;}
            if(!rotor2P){rotor3P=modulo(rotor3P,alfabeto.size());rotor3P++;}
        } 
        // if(rotor1P>4){rotor2P=modulo(rotor2P,alfabeto.size());rotor2P++;}
        // if(rotor2P>4){rotor3P=modulo(rotor3P,alfabeto.size());rotor3P++;}
        //  if(roto)
        // apartir de la quinta letra se mueve +1 
        //apartie de la novena letra rotoe2+1
        //apartir de la decimotercera rotor3+1 y todos siguen sumando

    }return cifrado;
}

string Enigma::Desincriptado(string cifrado,string cl){
    string descifrado; int posicion; string aux;
    int rotor1P=alfabeto.find(cl.at(0));
    int rotor2P=alfabeto.find(cl.at(1));
    int rotor3P=alfabeto.find(cl.at(2));
    for(int i=0;i<cifrado.size();i++){
       
        posicion=modulo(rotor3.find(cifrado.at(i))+rotor3P,alfabeto.size());
        aux=alfabeto.at(posicion);
        posicion= modulo(rotor2.find(aux)+rotor2P,alfabeto.size());
        aux=alfabeto.at(posicion);
        posicion= modulo(rotor1.find(aux)+rotor1P,alfabeto.size());
        descifrado+=alfabeto.at(posicion);
        rotor1P++;
        if(rotor1P>= alfabeto.size() || rotor2P>=alfabeto.size()|| rotor3P>=alfabeto.size()){
            rotor1P=modulo(rotor1P,alfabeto.size());
            if(!rotor1P){rotor2P=modulo(rotor2P,alfabeto.size());rotor2P++;}
            if(!rotor2P){rotor3P=modulo(rotor3P,alfabeto.size());rotor3P++;}
        } 
    }return descifrado;
}//10-1 =9