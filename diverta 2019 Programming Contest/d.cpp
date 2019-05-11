#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);

    long n;
    long m;
    long okini = 0;

    cin >> n;

    if(n/m == n%m){
        okini++;
    }

    cout << okini;


    return 0;
}