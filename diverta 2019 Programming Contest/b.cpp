#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int r_,g_,b_,n;

    cin >> r_ >> g_ >> b_ >> n;


    int a = 0;
    int b = 0;
    //int c = 0;

    int ans = 0;

    for(;r_*a+g_*b+b_*((n-(r_*a)-(g_*b))/b_)<n+1;b++){
        for(;r_*a+g_*b+b_*((n-(r_*a)-(g_*b))/b_)<n+1;a++){
            //cout <<a<<b<<((n-(r_*a)-(g_*b))/b_)<<endl;
            
            if(((n-(r_*a)-(g_*b))%b_)==0&&(a+b) != 0){
                ans++;
            }
        }
        a=0;
    }

    cout << ans;

    //c = ((n-(r_*a)-(g_*b))/b_)


    return 0;
}