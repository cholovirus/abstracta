#include "Vernar.h"

Vernar::Vernar(int len){
    srand(time(NULL));
    for(int i=0;i<len;i++){
        int numram= rand()%alfabeto.size();
        this->clave+=alfabeto.at(numram);
    }
}
void Vernar::creartxt(string bin){
    ofstream archivo;
    archivo.open("cifrado.txt",ios::out);
    archivo<<bin;
}

string Vernar::leertxt(){
    ifstream archivo;
    string desin;
    archivo.open("cifrado.txt",ios::in);
    while(!archivo.eof()){
        getline(archivo,desin);
    }return desin;
} 

string Vernar::binario(int var){
    string bin; string aux;
    if(var==0){return "000000";}
    while(!(var==1)){
        string cast=to_string(var%2);
        //string cast=to_string(modulo(var,2));
        var/=2;      
        bin.insert(0,cast);
    }
    bin.insert(0,"1");
    aux.resize(6-bin.size(),'0');
    bin.insert(0,aux);
    return bin;
}

string Vernar::xorbinario(string var1,string var2){
    string xo; 
    for(int i=0;i<6;i++){
        if((var1.at(i)=='0' &&var2.at(i)=='0')||(var1.at(i)=='1' && var2.at(i)=='1')){
            xo+="0";
        }else{xo+="1";}
    }
    return xo;
}

int Vernar::bindecimal(string var){
    int suma=0; int aux=0; int j=0;
    for(int i=var.size()-1;i>=0;i--){
        
        if(var.at(i)== '1'){aux=1;}
        else{aux=0;}
        suma+=(aux*pow(2,j++));
        
    }return suma;
}

string Vernar::Incriptado(string mensaje){
    string menbin; string clavebin; string xorbxb;
    for(int i=0; i<mensaje.size();i++){
        menbin=binario(alfabeto.find(mensaje.at(i)));
        clavebin=binario(alfabeto.find(clave.at(i)));
        xorbxb+=xorbinario(menbin,clavebin);
        creartxt(xorbxb);
    }return clave;
}

string Vernar::Desincriptado(string clave){
    string ci=leertxt();string a; string b;
    int j=0; string des; string des1; int var;
    for(int i=0;i<clave.size();i++){
        a=binario(alfabeto.find(clave.at(i)));
        if(!(j<ci.size())){break;}
        b=ci.substr(j,j+6);
        j+=6;
        des=xorbinario(a,b);
        
        des1+=alfabeto.at(bindecimal(des));
    }
        return des1;
}