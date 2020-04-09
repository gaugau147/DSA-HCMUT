#include <iostream>
#include <stdbool.h>
#include <string>
#include <strstream>
using namespace std;
#define Max 20

char *compare_str(char a[], char b[]){
    char* p;
    int i, j;
    //Tim kich thuoc that cua chuoi
    int size_A, size_B;
    for (i=0; i<Max; i++){
        if (a[i]=='\0') break;
    }
    size_A = i;
    for (j=0; j<Max; j++){
        if (b[j]=='\0') break;
    }
    size_B = j;

    //Gan flag = F: chuoi nay khong phai la substring cua chuoi kia
    bool Flag = false;

    //Truong hop 2 chuoi co do dai khac nhau
    if (size_A != size_B){
        if (size_A<size_B){
            for (i=0; i<size_A; i++){
                if (b[i]==a[i]){
                    for (j=i+1; j<size_A; j++){
                        if (b[j]!=a[j]) break;
                    }
                }
                if (j==size_A){
                    Flag = true;
                    p = &a[i];
                    return p;
                }
            }
        }
        else{
            for (i=0; i<size_B; i++){
                if (a[i]==b[i]){
                    for (j=i+1; j<size_B; j++){
                        if (a[j]!=b[j]) break;
                    }
                }
                if (j==size_B){
                    Flag = true;
                    p = &b[i];
                    return p;
                }
            }
        }
    }
    else{
        for (i=0; i<size_A; i++){
            if (a[i] != b[i]){
                Flag = false;
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
