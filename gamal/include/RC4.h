#ifndef RC4_H
#define RC4_H
#include <stdlib.h>
#include <string>
#include <time.h>
#include <iostream>
#include <bitset>
#include <iostream>
#include <NTL/ZZ.h>
#include <vector>
using namespace std;
using namespace NTL;


class RC4{
private:
    int bits;
public:
    RC4(int);

    ZZ randoM();
    vector<int> S;
    vector<int> K;

    int semillas(int);
    int modulo(int,int);
    ZZ modulo(ZZ,ZZ);
    ZZ convertBinaryToDecimal(ZZ);
    ZZ string_ZZ(string);
    string ZZ_string(ZZ);

};

#endif // RC4_H
