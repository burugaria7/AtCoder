#include <iostream>
#include <vector>
#include <string>
#include<cstring>
using namespace std;

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;

    int ans1 = 0;
    int ans2 = 0;
    int a=strlen(str);

    for(int i=0;i<a;i++){//1start
        if(i%2==0){
            if(str[i] == '1'){
                ans1+=1;
            }
        }else{
            if(str[i] == '0'){
                ans1+=1;
            }
        }
    }
    for(int i=0;i<a;i++){//0start
        if(i%2!=0){
            if(str[i] == '1'){
                ans2+=1;
            }
        }else{
            if(str[i] == '0'){
                ans2+=1;
            }
        }
    }

    if(ans1<ans2){
        cout << ans1;
    }else{
        cout <<ans2;
    }

    return 0;
}