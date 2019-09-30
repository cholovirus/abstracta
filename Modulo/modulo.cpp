#include <iostream>

using namespace std;

int modulo(int var, int modulo){
    int residuo;
    if(var<0){residuo=modulo*((-1*var/modulo)+1)+var;}
    else{residuo= var-((var/modulo)*modulo);}
    return residuo;

}

int main(){
    cout<<modulo(-1,6);
}