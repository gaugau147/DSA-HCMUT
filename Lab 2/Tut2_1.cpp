#include <iostream>
#include <sstream>
#include <stdbool.h>
using namespace std;

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    int i;
    for (i = 2; i*i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void onePrime(int *arr, int n) {
    static bool flag; //False: there is no prime number in array
    if (n==0){
        if (flag!=true){
            cout<<"There's no prime number in the array. ";
        }
    }
    else if (isPrime(*arr)==true){
        flag = true;
        cout<<"The prime number is: "<<*arr<<"\n";
    }
    else if (isPrime(*arr)==false){
        return onePrime((arr+1),n-1);
    }
}









int main(){
    int arr[20] = {1,3,4,5,6,7,8,9,10,11,12,13};
    int *p;
    p = arr;
    onePrime(p, 20);
}
