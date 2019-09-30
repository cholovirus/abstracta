#include <iostream>
using namespace std;
 
void euclidesE(int var1 , int var2){
    int q;
    int r; int r1=var1; int r2=var2;
    int s; int s1=1; int s2=0;
    int t; int t1=0; int t2=1;
    while(r2>0){
        q=r1/r2;
        
        r=r1-q*r2;
        r1=r2; r2=r;

        s=s1-q*s2;
        s1=s2; s2=s;

        t=t1-q*t2;
        t1=t2; t2=t;
    }cout<<"X :"<<s1<< " Y :"<<t1<<endl;
} 
int main(){
    euclidesE(250,111);
}
