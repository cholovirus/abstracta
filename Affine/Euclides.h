
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

int euclidesE(int var1 , int var2){
    int q;
    int r; int r1=var1; int r2=var2;
    int s; int s1=1; int s2=0;
    int t; int t1=0; int t2=1;
    while(r2>0){
        q=r1/r2;
        
        r=r1-q*r2;
        r1=r2; r2=r;

        s=s1-q*s2;
        s1=s2; s2=s;

        t=t1-q*t2;
        t1=t2; t2=t;
    }
    return s1;
}   