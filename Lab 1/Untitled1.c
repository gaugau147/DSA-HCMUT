#include <iostream>
#include <stdbool.h>
#include <string>
#include <strstream>
using namespace std;

char *compare_str(char a[], char b[]){
    char* p;
    int i, j;
    //Tim kich thuoc that cua chuoi
    int size_A, size_B;
    for (i=0; i<sizeof(a); i++){
        if (a[i]=='\0') break;
    }
    size_A = i;
    for (j=0; j<sizeof(b); j++){
        if (b[j]=='\0') break;
    }
    size_B = j;
    cout<<size_A<<" "<<size_;

    //Gan flag = F: 2 chuoi giong nhau
    bool Flag = false;

    //Truong hop 2 chuoi co do dai khac nhau
    if (size_A != size_B){
        Flag = true;
        if (size_A<size_B){
            for (i=0; i<size_A; i++){
                if (b[i]!=a[i]){
                    p = &b[i];
                    return p;
                }
            }
            p = &b[i];
            return p;
        }
        else{
            for (i=0; i<size_B; i++){
                if (a[i]!=b[i]){
                    p = &a[i];
                    return p;
                }
            }
            p = &a[i];
            return p;
        }
    }
    else{
        for (i=0; i<size_A; i++){
            if (a[i] != b[i]){
                Flag = true;
                p = &a[i];
                return p;
            }
        }
    }
    if (Flag == false){
        return 0;
    }
}
int main(){
    char A[10], B[10];
    cout<<"Enter char A[10]: ";
    cin.getline(A, 10);
    cout<<"Enter char B[10]: ";
    cin.getline(B, 10);

    cout<<*compare_str(A, B);
}
