#include<iostream>
#include <math.h>
using namespace std;

int main(){
    double a,b,c,y,s;

    cin >> a;
    cin >> b;
    cin >> c;

    s = (a+b+c)/2;

    y = sqrt(s*(s-a)*(s-b)*(s-c));


   
   cout << y << endl;
}