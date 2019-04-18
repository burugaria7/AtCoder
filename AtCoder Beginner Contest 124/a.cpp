#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b;
    cin >> a >> b;
    int ans = 0;
    if(a>b){
        ans += a;
        a--;
    }else{
        ans += b;
        b--;
    }
    if(a>b){
        ans += a;
    }else{
        ans += b;
    }
    cout << ans;


    return 0;
}