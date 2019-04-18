#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    int n,a,b;
   vector<int> p;

   cin >> n;
   cin >> a;
   cin >> b;
   int buf;
   for(int i = 0;i < n; i++){
      cin >> buf;
      p.push_back(buf);
   }

   sort(p.begin(),p.end());
  // printf("%d %d %d\n",n,a,b);
   //{for(int i=0;i<p.size();i++) printf("%d\n",p[i]);}

   // cout << "point1" << endl;

   int ans = 0;
   int bbb = 0;
   int ccc = 0;
   int l = 1;
   int a_ = 0;
   int nn = 0;

   while(1){
      l = 1;
      cout << "poin" << nn << endl;
      a_ = nn;
      if(p[a_] > a){
         cout << ans << endl;
         cout << "point1" << endl;
         return 0;
      }
      if(l == 1){
         //p.erase(p.begin());
         iter_swap(p.begin(), p.begin()+a_);
         nn ++;
         a_ ++;
         //n -= 1;
         
         for(a_ = nn; a_ < n+1; a_++){
            if(p[a_] >= a+1 && p[a_] <= b){
               bbb ++;
            }
         }
         if(bbb == 0){
            cout << ans << endl;
            cout << "point2" << endl;
            return 0;
         }
         //p.erase(p.begin() + a_);
         iter_swap(p.begin(), p.begin()+a_);
         
         nn ++;
         //n -= 1;
         l++;
      }
      if(l == 2){
         for(a_ = nn; a_ < n+1; a_++){
            if(p[a_] >= b+1){
               ccc ++;
            }
         }
         if(ccc == 0){
            cout << ans << endl;
            cout << "point3" << endl;
            return 0;
         }
         ccc --;
         //p.erase(p.begin() + a_);
         iter_swap(p.begin(), p.begin()+a_);
         nn ++;
         n -= 1;
         ans++;
         if(n <= 3){
         cout << ans << endl;
         cout << "point4" << endl;
         return 0;
         }
      }
   }

}