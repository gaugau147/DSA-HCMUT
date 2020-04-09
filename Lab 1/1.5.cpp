#include <iostream>
#include <stdbool.h>
#include <string.h>
#include <strstream>
using namespace std;

class candidates{
private:
    float math, physic, chemistry;
public:
    int id;
    char *name;
    candidates(int id, char* name, float math, float physic, float chemistry);
    ~candidates(){
        delete [] name;
    }
    float total_grade();
    void show_info(){ cout<<id<<" "<<name<<" "<<math<<" "<<physic<<" "<<chemistry;}
};

candidates::candidates(int ID, char* NAME, float MATH, float PHYSIC, float CHEMISTRY): id(ID), math(MATH), physic(PHYSIC), chemistry(CHEMISTRY){
    name = new char[50];
    strcpy(name, NAME);
}

float candidates::total_grade(){
    return math+physic+chemistry;
}

int main() {
    candidates A(1412,"Nguyen Van A", 8.8, 9.9, 7.7);
    A.show_info();
    cout<<"\nTotal grade: "<<A.total_grade();
}
