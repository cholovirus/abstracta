#include <iostream>
#include <string.h>

using namespace std;

int main(){ 
    string alfabeto = "abcdefghijklnmopqrstuvwxyz0123456789 ";

    cout<<"escriba algo: "; string mensaje; getline(cin,mensaje);
    
    int sizeMensaje=mensaje.size();

    string clave;
    int numale;

    int cifrado[sizeMensaje];

    for(int i = 0; i < sizeMensaje ;i++) {
        cin >> numale;
        if(numale>alfabeto.size()){numale%=alfabeto.size();}
        cifrado[i]=numale;
        clave += alfabeto.at(numale);
    }
    cout<<clave<<endl;
    
    for(int i= 0;i <sizeMensaje;i++){
       for(int j = 0; j < alfabeto.size() ; j++){
           if(alfabeto.at(j) == mensaje.at(i)){
                if(cifrado[i]+j > 37){cifrado[i]=(cifrado[i]+ j) % 37;}
                else{cifrado[i]+=j;}
            }
       }
    }
    for(int i=0; i<sizeMensaje;i++){
        mensaje.at(i)=alfabeto.at(cifrado[i]);
    }
    
    cout<<mensaje;
    
}