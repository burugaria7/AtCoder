#include<iostream>
#include<string>
using namespace std;

int main(){
    int a;

    cin >> a;

    int sum;
        
    while(a){
        sum += (a % 10);
        a /= 10;
    }

    cout << sum;

}