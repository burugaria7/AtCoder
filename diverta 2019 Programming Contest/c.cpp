#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string str;
    int a = 0;
    int b = 0;
    int num = 0;
    int ba = 0;

    for(int i=0;i<n;i++){
        cin >> str;

        if(str[0] == 'B'&&str[str.size()-1]=='A'){
            ba++;
        }else{    
            if(str[0] == 'B'){
                b++;
            }
            if(str[str.size()-1]=='A'){
                a++;
            }
        }


        for (int i = 1; i < str.size(); i++) {
            if (str[i-1] == 'A') {
                if(str[i]=='B'){
                    num++;
                }
            }
        }  
    }

    //cout << num << a << b;

    if(ba > 1){
        num += ba-1;
    }

    if(ba<1){
        cout << num+min(a,b);
    }else if(a>0&&b>0) {
        cout << num+min(a-1,b-1)+2;
    }else if(a>0){
        cout << num+min(a-1,b)+1;
    }else if(b>0){
        cout << num+min(a,b-1)+1;
    }

    


    return 0;
}