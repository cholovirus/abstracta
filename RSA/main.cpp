
#include "RSA.h"
#include <cmath>
#include <time.h>
using namespace std;
int main(){    
    RSA a(11,3);
    cout<<a.Incriptado("l",3,33)<<endl;
    a.Desincriptado("13051100",3);
}