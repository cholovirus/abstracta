#include <iostream>
using namespace std;

int modulo(int var, int modulo){
    int residuo;
    if(var<0){residuo=modulo*((-1*var/modulo)+1)+var;}
    else{residuo= var-((var/modulo)*modulo);}
    return residuo;

}

int euclides(int var, int var2){
    int residuo; int q;
    while(var2>0){
        q=var/var2;
        residuo=var-q*var2;
        var=var2;
        var2=residuo;
        
        
        
    }
    return var;
}
int main(){
    cout<<euclides(4864,3458);
}