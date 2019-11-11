#include <iostream>
#include "RSA.h"
using namespace std;

int main()
{

    //RSA a(16);
    //a.Incriptado("hola amigo como estas");
//968527955
//64667-39883
    ZZ x,y,z;
    x=968527955; y=64667; z=39883;
    RSA b(x,y,z);
    b.Desincriptado("cifrado");
}
