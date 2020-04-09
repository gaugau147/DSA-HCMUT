#include <iostream>
using namespace std;

bool isLeapYear(int y){
    if (((y%4==0)&&(y%100!=0))||(y%400==0)){
        return true;
    }
    else return false;
}

int main(){
   /* int y;
    cout<<"Nhap nam: ";
    cin>>y;
    if (isLeapYear(y)==1){
        cout<<"Nam Nhuan";
    }
    else {
        cout<<"Khong phai nam nhuan";
    }
    */
    char ch = 'b';
    ch = ch - 'a' + 'A';
    cout<<ch;
}
