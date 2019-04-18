#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int b,r;

    b = 0;
    r = 0;

    int n;

    cin >> n;

    char tmp[100];

    cin >> tmp;

    for(int i = 0;i<n;i++){
        //cin >> tmp;
        if(tmp[i] == 'B'){
            b++;
        }else {
            r++;
        }
    }

    if(r>b){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }




    return 0;
}