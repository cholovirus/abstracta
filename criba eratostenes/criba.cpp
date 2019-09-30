#include <iostream>
#include <cmath>

using namespace std;
int modulo(int var, int modulo){
    int residuo;
    if(var<0){residuo=modulo*((-1*var/modulo)+1)+var;}
    else{residuo= var-((var/modulo)*modulo);}
    return residuo;

}

bool primo(int var, int raiz){
    bool aux= true;
    for(int i=2;i<raiz;i++){
        if(!(modulo(var,i))){    
            aux=false;
        }
    }return aux;
}

bool criva(int var){
    int raiz=sqrt(var);
    return primo(var,raiz);
}

int main(){
    int a; cin>>a;
    cout<<criva(a);
}