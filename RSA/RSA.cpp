#include "RSA.h"
#include "criba.h"
#include "Euclides.h"


RSA::RSA(unsigned long long primop, unsigned long long primoq){
    unsigned long long N;
    unsigned long long phi;
    while(true){
        if( criva(primop) && criva(primoq)){
            if(euclides(primop,primoq)==1){
                N=primop*primoq;
                modN=N;
                phi=(primop-1)*(primoq-1) ;
                phiN=phi;
                break;
            }else{cout<<"no son ##coprimos";}
        }
    }
    
    srand(time(NULL));
    unsigned long long e;
    while(true){
        e=modulo(rand(),phi);
        if(euclides(phi,e)==1){publica=e;break;}
    }  

    if(!(publica == 0)){
        privada=modulo(euclidesE<unsigned long long>(publica,phi),N);
    }
    cout<<"clave publica "<<publica<<endl;
    cout<<"clave privada "<<privada<<endl;
    
}

unsigned long long RSA::numexponente(int posicion, unsigned long long exponente,int eN){
    int exp=0; int pote2=0; int resul=0; int auxpote2=1;
    unsigned long long emod2=modulo(exponente,2);
    
    pote2=modulo(posicion,eN);
    resul=modulo(auxpote2*pote2,eN);
    exp=(exponente-emod2)/2;
    while(exp>0){
        emod2=modulo(exp,2);
        pote2=modulo(pote2*pote2,eN);
        if(emod2){resul=modulo(pote2*resul,eN);}
        exp=(exp-emod2)/2;

    }
    return resul;    
}

string RSA::Incriptado(string mensaje, unsigned long long e, unsigned long long n){
    string cifrado;
    for(unsigned long long i=0;i<mensaje.size();i++){
        unsigned long long pos=alfabeto.find(mensaje.at(i));
        unsigned long long cifer=modulo(numexponente(pos,e,n),n);
        //int Z_27=modulo(cifer,alfabeto.size());
        string aux=to_string(cifer);
        if(aux.size()==2){}
        else{aux.insert(0,"0");}
        //aux.resize(2);
        cifrado+=aux;
    }
    return cifrado;
}

string RSA::Desincriptado(string cifrado, unsigned long long a){
    string decifrado; int j=0; 
    unsigned long long pri=modulo(euclidesE<unsigned long long>(a,phiN),modN);
    
    for(unsigned long long i=0;i<cifrado.size();i++){
        string subst= cifrado.substr(j,j+2); if(!(j<cifrado.size())){break;}
        subst.resize(2);
        stringstream S_I(subst);
        unsigned long long entero=0;
        S_I>>entero;
        
        entero=modulo(numexponente(entero,pri,modN),modN);
        string aux=to_string(entero);
        decifrado+=aux;
        j+=2;
    }
    cout<<decifrado;
}