#include<iostream>
using namespace std;
int main(){
    int a;
    cin >> a;
    int sum = 0;
    char hoge[5];
    sprintf(hoge, "%d", a);
    for(int b = 0; b<4; b++){
        if(hoge[b] == '2'){
            sum++;
        }
    }
    cout << sum;
}