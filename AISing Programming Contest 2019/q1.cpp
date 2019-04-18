#include<iostream>
using namespace std;

int main(){
    int n,h,w;
    int a,b;

    cin >> n;
    cin >> h;
    cin >> w;

    a = n - h + 1;
    b = n - w + 1;

   cout << a*b << endl;
}