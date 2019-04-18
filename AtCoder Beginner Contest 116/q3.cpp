#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    vector<int> h;
    int buf;
    int higt = 0;
    int mizu = 0;

    for(int i = 0; i< n;i++){
       cin >> buf;
       if(buf>higt){
          higt = buf;
       }
       h.push_back(buf);
    }
    for(int i = 0; i< n;i++){
      if(h[i]<higt){
          mizu += higt - h[i];
       }
    }
   
   cout << mizu << endl;
}