#include<iostream>
#include<stdbool.h>
using namespace std;

int main(){
    int s;
    int a[1000000];
    bool z[1000000];
    for(int i = 0;i < 1000000 ; i++){
        z[i] = false;
    }
    int buf;
    cin >> s;
    a[0] = s;
    z[s] = true;
    for(int i = 1;i < 1000000 ; i++){
        if(a[i-1]%2==0){
            a[i] = a[i-1] /2;
        }else{
            a[i] = 3*a[i-1] + 1;
        }
        buf = a[i];
		if (z[buf] == true) {
			cout << i+1 << endl;
			return 0;
		}
		else {
			z[buf] = true;
		}
       //cout << a[i] << endl;
    }
    return 0;
}