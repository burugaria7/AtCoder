#include<iostream>
#include<string>
#include <vector>
using namespace std;

int main(){

    int n = 0;
    int h,w;
    
    cin >> n;
    cin >> h;
    cin >> w;
    
    vector<int> a(n),b(n);

    
    int c = 0;
    int d = 0;
    int sum = 0;

    for(int i = 0;i<n;i++){
        cin >> a[i];
        cin >> b[i];

        c = a[i] / h;
        d = b[i] / w;

        if(c < 1 || d < 1){
            continue;
        }

        if(c > d){
            sum += d;
        }else{
            sum += c;
        }

    }

    cout << sum;

}