#include <iostream>
#include <RC4.h>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
#include <bitset>


int main()
{
    RC4 a(64);
    RC4 b(64);
    ZZ t;
    GenPrime(t,20);
    cout<<t<<endl;
    ZZ bit_mayor(2);ZZ bit_menor(2);
    bit_mayor=power(bit_mayor,512-1);
    bit_menor=power(bit_menor,512)-1;
    ZZ var;
    ZZ var2;


    while(true){
        var=a.randoM()*b.randoM()*a.randoM()*b.randoM();
        var2=a.randoM()*b.randoM()*a.randoM()*b.randoM();
        var*=var2;
        if(var>bit_mayor && var<bit_menor){
        cout<<var<<endl;
        break;
        }
    }




    /*cout<<a.randoM()<<endl;
    cout<<a.randoM()<<endl;
    cout<<a.randoM()<<endl;
    cout<<a.randoM()<<endl;*/

}
