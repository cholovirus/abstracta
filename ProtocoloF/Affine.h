#include <iostream>
#include <string.h>
#include <cmath>
#include <time.h>

using namespace std;

class Affine{
    
    private:
    int claveA;
    int claveB;

    public:
    string alfabeto ="abcdefghijklmnopqrstuvwxyz0123456789 ";
    //string alfabeto ="abcdefghijklmnopqrstuvwxyz ";
    Affine();
    Affine(int,int);

    string Incriptado(string);
    string Desinciptado(string);
    string getclaveA(){return to_string(claveA);}
    string getclaveB(){return to_string(claveB);}
};
