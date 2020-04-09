#include <iostream>
#include <sstream>
using namespace std;

void recursiveLine1(int N, int n);
void recursiveTriangle(int N){
    static int n = N;
    if (N==0){
        return;
    }
    else if (N>n/2){
        return recursiveLine1(N, n);
    }
    else {
        return recursiveLine2(N-N/2+1, n);
    }
    /*
    if (N<n/2+1){
        for (int i=1; i<n-N+1; i++){
            cout<<"_";
        }
        for (int j=n-N+1; j<=n; j++){
            cout<<j;
        }
        cout<<"\n";
        return recursiveTriangle(N-1);
    }
    */
}


void recursiveTriangle1(int N, int n){
    if (N<n/2){
        return;
    }
    else if (N>0){
        cout<<"_";
        return recursiveTriangle1(N-1,n);
    }
    else if () {
        cout<<
    }
    return recursiveTriangle(N-2);
}

void recursiveTriangle2(int N, int n)

int main() {
    recursiveTriagle2(9);
}
