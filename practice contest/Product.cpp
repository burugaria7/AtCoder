#include<iostream>
#include<string>
using namespace std;

int main(){
    int a,b;

    cin >> a;
    cin >> b;

    if(a*b%2 == 0){
        cout << "Even";
    }else{
        cout << "Odd";
    }

}