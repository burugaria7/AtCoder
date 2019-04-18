#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
   int a;
   cin >> a;

   vector<int> n;

   int buf;

   for(int i = 0;i < a; i++){
      cin >> buf;
      n.push_back(buf);
   }

   int count = 0;

   while(1){
    for(int i = 0;i < a;i++){
         if(n[i]%2 == 0){
           n[i] /= 2;
       }else{
          cout << count;
            return 0;
         }
    }
    count++;
   }

}