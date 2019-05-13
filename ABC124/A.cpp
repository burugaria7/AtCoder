#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b;
    cin >> a >> b;
    cout << max({a+a-1,a+b,b+b-1});
    return 0;
}