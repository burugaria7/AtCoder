#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,k;
    cin >> n >>k;

    cout << n-k+1;

    return 0;
}