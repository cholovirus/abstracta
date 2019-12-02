#include "RSA.h"
#include <sstream>
#include <fstream>
#include "RC4.h"
//----------
RSA::RSA(int bits){
    while(true){
        //GenPrime(P,bits);
        //GenPrime(Q,bits);
        P=genPrimo(bits);
        Q=genPrimo(bits);

        if(euclides(P,Q)==1){
            modN=P*Q;
            phi=(P-1)*(Q-1);
            break;
        }
    }

    ZZ e;
    while(true){
        RC4 num_ale(bits);

        e=num_ale.randoM();
        e=modulo(e,phi);
        if(euclides(phi,e)==1){publica=e;break;}
    }
    privada=modulo(euclidesE(publica,phi),phi);

    ofstream archivo;
    archivo.open("clave.txt",ios::out);
    /*cout<<"phi "<<phi<<endl;
    cout<<"pub "<<publica<<endl;
    cout<<"modN "<<modN<<endl;
    cout<<"pri  "<<privada<<endl;
    cout<<"p "<<P<<" q "<<Q<<endl;*/

    archivo<<"phi "<<phi<<endl;
    archivo<<"pub "<<publica<<endl;
    archivo<<"modN "<<modN<<endl;
    archivo<<"pri "<<privada<<endl;
    archivo<<"p "<<P<<endl;
    archivo<<"q "<<Q<<endl;
    archivo.close();
    cout<<"claves generadas "<<endl;
}

RSA::RSA(ZZ e, ZZ N){
    publica=e;
    modN=N;
}
RSA::RSA(ZZ d,ZZ p,ZZ q){
    privada=d;
    P=p; Q=q;
    modN=P*Q;
    phi=(P-1)*(Q-1);

}
//----------
string RSA::Incriptado(string mensaje){
    string N=ZZ_string(modN);
    int lenN=N.size()-1;
    string num;
    for(int i=0;i<mensaje.size();i++){
        int pos=alfabeto.find(mensaje.at(i));
        string aux=to_string(pos);
        string aux2; aux2.resize(2-aux.size(),'0');
        aux.insert(0,aux2);
        num+=aux;
    }

    fstream crear;
    crear.open("cifrado.txt",ios::out);
    for(int i=0;i<num.size();i+=lenN){
        string aux=num.substr(i,i+(lenN));
        aux.resize(lenN,'2');


        ZZ auxZZ=string_ZZ(aux);
        auxZZ=numexp(auxZZ,publica,modN);
        //cout<<auxZZ<<" ";
        aux=ZZ_string(auxZZ);

        string aux2; aux2.resize(N.size()-aux.size(),'0');

        aux.insert(0,aux2);
        cout<<aux<<endl;
        crear<<aux;
    }
    crear.close();


}
string RSA::Desincriptado(string nombre){
    ifstream lectura;
    lectura.open(nombre+".txt",ios::in);
    string decifradoaux; getline(lectura,decifradoaux);

    //-----

    string N=ZZ_string(modN);
    int lenN=N.size();
    string num_norm;
    cout<<modN<<endl;
    for(int i=0;i<decifradoaux.size();i+=lenN){
        int lenaux;
        string aux=decifradoaux.substr(i,i+lenN);
        aux.resize(lenN);

        ZZ auxzz=string_ZZ(aux);
        auxzz=resto_chino(auxzz);
        aux=ZZ_string(auxzz);
        lenaux=aux.size();

        string aux2;
        lenaux=lenN-lenaux;
        cout<<aux<<endl;
        /*if(lenaux<0){
            //aux2.resize((lenN)-aux.size(),'0');
            //aux.insert(0,aux2);
        }else{
            aux2.resize((lenN-1)-aux.size(),'0');
            aux.insert(0,aux2);
        }*/
        aux2.resize((lenN-1)-aux.size(),'0');
        aux.insert(0,aux2);
        num_norm+=aux;
    }
    cout<<num_norm<<endl;

    string decifrado;
    for(int i=0;i<num_norm.size();i+=2){
        string sub=num_norm.substr(i,i+2);
        sub.resize(2);

        stringstream String_int(sub);
        int pos=0;
        String_int>>pos;

        decifrado+=alfabeto.at(pos);

    }
    return decifrado;
}

//----------

ZZ RSA::numexp(ZZ var,ZZ exp,ZZ mod){
    if(var==1 || var==0){return var;}
    ZZ cont(1);
    ZZ emod2(2);
    while(exp!=0){
        if(modulo(exp,emod2)==1){
            cont=modulo(cont*var,mod);
        }
        var=modulo(var*var,mod);
        exp=exp/emod2;
    }
    return cont;
}

ZZ RSA::resto_chino(ZZ pos){

    ZZ Dp=modulo(privada,P-1);
    ZZ Dq=modulo(privada,Q-1);

    Dp=numexp(pos,Dp,P);
    Dq=numexp(pos,Dq,Q);

    ZZ q1=modulo(euclidesE(Q,P),P);
    ZZ q2=modulo(euclidesE(P,Q),Q);

    //ZZ Xo=modulo(Dp*Q*q1,modN)+modulo(Dq*P*q2,modN);
    //Xo=modulo(Xo,modN);
    pos=modulo(Dp*Q*q1,modN)+modulo(Dq*P*q2,modN);
    pos=modulo(pos,modN);

    return pos;
}

ZZ RSA::euclides(ZZ var,ZZ var2){
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

ZZ RSA::euclidesE(ZZ var1,ZZ var2){
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

ZZ RSA::modulo(ZZ var,ZZ mod){
    ZZ residuo;
    if(var<0){residuo=mod*((-1*var/mod)+1)+var;}
    else{residuo= var-((var/mod)*mod);}
    return residuo;
}
//----------

bool RSA::criba(ZZ var){
    ZZ raiz(var); raiz=SqrRoot(raiz);
    bool prim=true;
    for(ZZ i(2);i<raiz;i++){
        if(modulo(var,i)==0){prim=false;}
    }return prim;
}

bool RSA::testprimo(ZZ var){

    if (var <= 1)  return false;
    if (var <= 3)  return true;
    ZZ a(2),b(3);
    if (modulo(var,a) == 0 || modulo(var,b) == 0) return false;

    for (ZZ i(5); i*i<=var; i=i+6)
        if (modulo(var,i) == 0 || modulo(var,i+2) == 0)
            return false;

    return true;
}
ZZ RSA::genPrimo(int bit){
    RC4 a(bit);
    while(true){
        ZZ pri=a.randoM();
        if(testprimo(pri)){
            return pri;
        }
    }
}
//----------

ZZ RSA::string_ZZ(string str){
    ZZ num(NTL::INIT_VAL,str.c_str());
    return num;
}

string RSA::ZZ_string(ZZ var){
    stringstream x;
    x << var;
    return x.str();
}



