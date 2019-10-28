#include "Protocolo.h"
#include "Enigma.h"
#include "Escitala.h"
#include "Vigenere.h"
#include "Affine.h"
#include <sstream>

void Protocolo::creartxt(string name,string mensaje){
    ofstream crear;
    crear.open(name+".txt",ios::in);
    crear<<rotor<<endl; 
    crear<<claveE<<endl;
    crear<<fila<<endl;
    crear<<columna<<endl;
    crear<<vig<<endl;
    crear<<a<<endl;
    crear<<b<<endl;
    crear<<mensaje<<endl;
    crear.close();
}
string Protocolo::leertxt(string name){
    ifstream lectura;
    string archivo;
    lectura.open(name+".txt",ios::out);
    
    
    getline(lectura,rotor);
    getline(lectura,claveE);
    getline(lectura,f);
    getline(lectura,c);
    getline(lectura,vig);
    getline(lectura,a);
    getline(lectura,b);
    getline(lectura,mensaje);

    lectura.close();
    return archivo;
}
Protocolo::Protocolo(string name){

    leertxt(name);
    stringstream fi(f);
    stringstream co(c);
    fi>>fila;
    co>>columna;
    

}
Protocolo::Protocolo(string cE,int fil,int col, int vige ){
    Enigma ran; rotor=ran.getrotor();    
    claveE=cE;
    fila=fil; columna=col;
    lenViginere=vige;

}
string Protocolo::Incriptado(string mensaje){
    string cifrado;
    Vigenere vige(lenViginere);
    //cout<<vige.Incriptado(mensaje)<<"vige"<<endl;
    vig=vige.Obtenerclave();
    

    //-----------
    string rotoraux; string aux;

    rotoraux=rotor;
    aux=rotoraux.substr(rotoraux.size()-1,rotoraux.size());
    rotoraux.erase(rotoraux.size()-1,rotoraux.size());
    rotoraux.insert(0,aux);

    Escitala men(fila,columna);
    string rotor2=men.Incriptado(rotoraux);
    rotor2.resize(rotor.size());
    
    rotoraux=rotor2;
    aux=rotoraux.substr(0,2);
    rotoraux.erase(0,2);
    rotoraux.insert(rotoraux.size(),aux);

    string rotor3=men.Incriptado(rotoraux);
    rotor3.resize(rotor.size());
    //-----------

    Enigma eni(claveE,rotor,rotor2,rotor3);
   //eni.Incriptado(vige.Incriptado(mensaje));

    Affine affi;
    cifrado=affi.Incriptado(eni.Incriptado(vige.Incriptado(mensaje)));
    a=affi.getclaveA();
    b=affi.getclaveB();
    
    creartxt("cifrado",cifrado);
    return cifrado;
}

string Protocolo::Desincriptado(){
    string descifrado;
    int ca,cb;
    stringstream a_(a); stringstream b_(b);
    a_>>ca; b_>>cb;
    
    Affine affi(ca,cb);
    descifrado=affi.Desinciptado(mensaje);
   
    
    //-----------
    string rotoraux; string aux;

    rotoraux=rotor;
    aux=rotoraux.substr(rotoraux.size()-1,rotoraux.size());
    rotoraux.erase(rotoraux.size()-1,rotoraux.size());
    rotoraux.insert(0,aux);

    Escitala men(fila,columna);
    string rotor2=men.Incriptado(rotoraux);
    rotor2.resize(rotor.size());
    
    rotoraux=rotor2;
    aux=rotoraux.substr(0,2);
    rotoraux.erase(0,2);
    rotoraux.insert(rotoraux.size(),aux);

    string rotor3=men.Incriptado(rotoraux);
    rotor3.resize(rotor.size());
    //-----------
    Enigma eni(claveE,rotor,rotor2,rotor3);
    descifrado=eni.Desincriptado(descifrado,claveE);
    
    Vigenere vige;
    descifrado=vige.Desincriptado(descifrado,vig);
    
    return descifrado;
    
}