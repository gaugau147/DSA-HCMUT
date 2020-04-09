#include <iostream>
using namespace std;

int pow(int a, int b){
    int t = 1;
    while (b>0){
        t = t*a;
        b--;
    }
    return t;
}
int pow2(int a, int b){
    if (b>0) return a*pow(a,b-1);
    else return 1;
}
int main(){
    cout<<"3 power 3 = "<<pow(3,3);
}
