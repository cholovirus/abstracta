
#include <iostream>
using namespace std;
template <typename B>
B modulo(B var, B modulo){
    B residuo;
    if(var<0){residuo=modulo*((-1*var/modulo)+1)+var;}
    else{residuo= var-((var/modulo)*modulo);}
    return residuo;

}


unsigned long long euclides(unsigned long long var, unsigned long long var2){
    if(var<var2){
        unsigned long long temp=var;
        var=var2;
        var2=temp;
    }
    unsigned long long residuo; unsigned long long q;
    while(var2>0){
        q=var/var2;
        residuo=var-q*var2;
        var=var2;
        var2=residuo;
        
        
        
    }
    return var;
}
template <typename A>
A euclidesE(A var1 , A var2){
    A q;
    A r; A r1=var1; A r2=var2;
    A s; A s1=1; A s2=0;
    A t; A t1=0; A t2=1;
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