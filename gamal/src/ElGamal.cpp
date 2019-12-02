#include "ElGamal.h"
#include <sstream>
#include <vector>
#include "RC4.h"
#include <fstream>

ElGamal::ElGamal(int bits,string _alfabeto){
    alfabeto=_alfabeto;
    //primo=genPrimo(bits);
    GenPrime(primo,bits);
    e1=raizPrimitiva(primo);
    RC4 aux(bits-1);
    D=modulo(primo+aux.randoM(),primo-2);
    e2=numexponente(e1,D,primo);

    ofstream claves;
    claves.open("claves.txt",ios::out);
    claves<<"e1 "<<e1<<endl;
    claves<<"e2 "<<e2<<endl;
    claves<<"primo "<<primo<<endl;
    claves<<"D "<<D<<endl;
    claves.close();
    cout<<"claves generadas"<<endl;
}
ElGamal::ElGamal(ZZ _d,ZZ _primo,string _alfabeto){
    alfabeto=_alfabeto;
    D=_d;
    primo=_primo;

}
ElGamal::ElGamal(ZZ _e1,ZZ _e2,ZZ p,string _alfabeto){
    primo=p;
    e1=_e1;
    e2=_e2;
    alfabeto=_alfabeto;
    RC4 num(16);
    r=modulo(primo+num.randoM(),primo-2);
    C1=numexponente(e1,r,primo);
    K=numexponente(e2,r,primo);
}
string ElGamal::Incriptado(string mensaje){
    string cifrado;
    string Pri=stringtoZZ(primo);
    int lenP=Pri.size()-1;

    string aux, aux2;
    string num_concatenados;
    for(int i=0;i<mensaje.size();i++){
        int pos=alfabeto.find(mensaje.at(i));
        aux=to_string(pos);
        aux2; aux2.resize(2-aux.size(),'0');
        aux.insert(0,aux2);
        num_concatenados+=aux;
    }
    for(int i=0;i<num_concatenados.size();i+=lenP){
        aux=num_concatenados.substr(i,i+(lenP));
        aux.resize(lenP,'2');
        ZZ auxZZ=ZZtostring(aux);
        C2=modulo(auxZZ*K,primo);

        aux=stringtoZZ(C2);
        aux2; aux2.resize(Pri.size()-aux.size(),'0');
        aux.insert(0,aux2);
        cifrado+=aux;

    }
    aux2=stringtoZZ(C1);
    aux.resize(Pri.size()-aux2.size(),'0');
    aux2.insert(0,aux);
    cout<<aux2<<endl;
    cifrado.insert(0,aux2);
    return cifrado;

    //codigo que funciona
    /*for(int i=0;i<mensaje.size();i++){

        C2=modulo(alfabeto.find(mensaje.at(i))*K,primo);
        aux2=stringtoZZ(C2);
        aux.resize(pri_size.size()-aux2.size(),'0');
        aux2.insert(0,aux);
        cifrado+=aux2;

    }

    aux2=stringtoZZ(C1);
    aux.resize(pri_size.size()-aux2.size(),'0');
    aux2.insert(0,aux);
    cifrado.insert(0,aux2);
    return cifrado;*/

}
string ElGamal::Desincriptado(string nombre){
    string sizeprimo=stringtoZZ(primo);
    int lenP=sizeprimo.size();
    string aux=nombre.substr(0,sizeprimo.size());
    C1=ZZtostring(aux);
    //cout<<C1<<endl;
    K=numexponente(C1,D,primo);
    K=modulo(euclidesE(K,primo),primo);

    string auxdecifrado;
    string aux2;
    for(int i=lenP;i<nombre.size();i+=lenP){
        aux=nombre.substr(i,i+lenP);
        aux.resize(lenP);
        C2=modulo(ZZtostring(aux)*K,primo);
        aux=stringtoZZ(C2);
        aux2.resize((lenP-1)-aux.size(),'0');
        aux.insert(0,aux2);
        auxdecifrado+=aux;
    }
    string decifrado;
    for(int i=0;i<auxdecifrado.size();i+=2){
        aux=auxdecifrado.substr(i,i+2);
        aux.resize(2);
        stringstream String_int(aux);
        int pos=0;
        String_int>>pos;
        decifrado+=alfabeto.at(pos);
    }

    return decifrado;
    //---- decifrado correcto
    /*for(int i=sizeprimo.size();i<nombre.size();i+=sizeprimo.size()){
        aux=nombre.substr(i,i+sizeprimo.size());
        aux.resize(sizeprimo.size());
        C2=modulo(ZZtostring(aux)*K,primo);
        aux=stringtoZZ(C2);
        stringstream String_int(aux);
        int pos=0;
        String_int>>pos;
        decifrado+=alfabeto.at(pos);
    }
    return decifrado;*/
}

ZZ ElGamal::raizPrimitiva(ZZ varprima){
    ZZ q((varprima-1)/2);
    for(ZZ i(varprima-1),j(2);i>2;i--){
        if((numexponente(i,j,varprima)!=1)&&(numexponente(i,q,varprima)!=1)){
            return i;
        }
    }


}

ZZ ElGamal::numexponente(ZZ base,ZZ expo, ZZ mod){
    ZZ cont; cont=1;
    ZZ emod2; emod2=2;
    while(expo!=0){
        if(modulo(expo,emod2)==1){
            cont=modulo(cont*base,mod);
        }
        base=modulo(base*base,mod);
        expo=expo/emod2;
    }
    return cont;
}

ZZ ElGamal::modulo(ZZ var,ZZ mod){
    ZZ residuo;
    if(var<0){residuo=mod*((-1*var/mod)+1)+var;}
    else{residuo= var-((var/mod)*mod);}
    return residuo;
}

ZZ ElGamal::euclides(ZZ var,ZZ var2){
    if(var<var2){
        ZZ temp=var;
        var=var2;
        var2=temp;
    }
    ZZ residuo; ZZ q;
    while(var2>0){
        q=var/var2;
        residuo=var-q*var2;
        var=var2;
        var2=residuo;
    }
    return var;
}

ZZ ElGamal::euclidesE(ZZ var1, ZZ var2){
    ZZ q;
    ZZ r; ZZ r1=var1; ZZ r2=var2;
    ZZ s; ZZ s1(1); ZZ s2(0);
    ZZ t; ZZ t1(0); ZZ t2(1);
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

bool ElGamal::testprimo(ZZ var){

    if (var <= 1)  return false;
    if (var <= 3)  return true;
    ZZ a(2),b(3);
    if (modulo(var,a) == 0 || modulo(var,b) == 0) return false;

    for (ZZ i(5); i*i<=var; i=i+6)
        if (modulo(var,i) == 0 || modulo(var,i+2) == 0)
            return false;

    return true;
}
ZZ ElGamal::genPrimo(int bit){
    RC4 a(bit);
    while(true){
        ZZ pri=a.randoM();
        if(testprimo(pri)){
            return pri;
        }
    }
}
ZZ ElGamal::ZZtostring(string str){
   ZZ num(NTL::INIT_VAL,str.c_str());
   return num;
}
string ElGamal::stringtoZZ(ZZ var){
   stringstream x;
   x << var;
   return x.str();
}

