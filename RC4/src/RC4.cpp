#include "RC4.h"
#include <bitset>
#include <string>
#include <sstream>
#include <climits>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#define DIV 1024
#define WIDTH 7

int RC4::modulo(int var, int modulo){
    int residuo;
    if(var<0){residuo=modulo*((-1*var/modulo)+1)+var;}
    else{residuo= var-((var/modulo)*modulo);}
    return residuo;

}
RC4::RC4(int bit=256){
    bits=bit;
    for(int i=0; i<bit; i++){
        S.push_back(i);
        //S[i]=i;
    }
     int aux=bit;
    for(int i=0,j=1;i<bit;i++){

        K.push_back(modulo(semillas(j++),aux));
        K.push_back(modulo(semillas(j++),aux));
        K.push_back(modulo(semillas(j++),aux));
        K.push_back(modulo(semillas(j++),aux));

        j=1;
    }

   /* for(int i=0;i<bit;i++){
        cout<<K[i]<<endl;
    }*/

}

int RC4::semillas(int var){
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof (statex);
    GlobalMemoryStatusEx (&statex);
    switch(var){
    case 1:
        return (int)statex.dwMemoryLoad;
    case 2:
        return (int)statex.ullAvailPhys/DIV;
   case 3:
        return (int)statex.ullAvailPageFile/DIV;
    case 4:
        return (int)statex.ullAvailPageFile/9;
    }
}

ZZ RC4::string_ZZ(string str){
    ZZ num(NTL::INIT_VAL,str.c_str());
    return num;
}

string RC4::ZZ_string(ZZ var){
    stringstream x;
    x << var;
    return x.str();
}

ZZ RC4::randoM(){
    int F=0;
    for(int i=0; i<bits; i++){
        F=modulo((F+S[i]+K[i]),bits);
        swap(S[i],S[F]);
    }F=0;

    int n; int t;
    string string_bits;
    for(int i=0; i<bits; i++){
        n=(i+1);
        F=modulo((F+S[n]),bits);
        swap(S[i],S[F]);
        t=(S[i]+S[F]);
        bitset<2> _bit(t);
        string_bits+=_bit.to_string();

    }
    string_bits.insert(0,"1");
    string_bits.resize(bits);

    bitset<64> _bit(string_bits);
    unsigned long long aux= _bit.to_ullong();
    string_bits= to_string(aux);
    ZZ var(string_ZZ(string_bits));

    return var;
    ZZ bit_mayor(2);ZZ bit_menor(2);
    bit_mayor=power(bit_mayor,bits-1);
    bit_menor=power(bit_menor,bits)-1;

    if(var>bit_mayor && var<bit_menor){return var;}

}




