#include <iostream>
#include <string.h>
#include <cmath>
#include <time.h> 
using namespace std;

class Enigma{
    private:
        string clave;
    public:
        string rotorRan(string); 
        
        string alfabeto ="abcdefghijklmnopqrstuvwxyz0123456789 ";
        
        string rotor1;
        string rotor2;
        string rotor3;
    //string ralfa="abcdefghijklmnopqrstuvwxyz0123456789 ";
       // string rotor1="jkd6vf4urc 0b3logx1zq7h85taenymispw29";
        //string rotor2="d9s1pfbg862j 5a0mwvz4oqhrtc7yikxelu3n";
        //string rotor3="c 6s7fmqxd9aky0l48etgpuwizjv35br1ohn2";

        Enigma(string);

        int modulo(int, int);
        string Incriptado(string);
        string Desincriptado(string, string);

};