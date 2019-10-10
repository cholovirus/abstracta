#include <iostream>
#include <cmath>

using namespace std;

unsigned long long modulo(unsigned long long var, unsigned long long modulo){
    unsigned long long residuo;
    if(var<0){residuo=modulo*((-1*var/modulo)+1)+var;}
    else{residuo= var-((var/modulo)*modulo);}
    return residuo;

}

bool primo(unsigned long long var, unsigned long long raiz){
    bool aux= true;
    for(unsigned long long i=2;i<raiz;i++){
        if(!(modulo(var,i))){    
            aux=false;
        }
    }return aux;
}

bool criva(unsigned long long var){
    unsigned long long raiz=sqrt(var);
    return primo(var,raiz);
}

