#include<iostream>
#include<vector>
#include <algorithm>    // std::copy
#include <iterator>     // std::back_inserter
using namespace std;

int main(){
    int n,k,oic,shu;
    cin >> n;
    vector<int> t;
    int buf;
    vector<int> d;
    vector<int> co;
    
   
   for(int i = 0; i< n;i++){
       cin >> t[i];
       cin >> buf;
       d[i] = buf;
       co[i] = buf;
   }

   sort(co.begin(), co.end());
  
   for(int i = 0; i< k;i++){
      oic += co[i];
   }

   

   //cout <<  << endl;
}