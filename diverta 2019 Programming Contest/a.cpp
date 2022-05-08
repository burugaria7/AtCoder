#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main(void){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;
    cin >> n >> m ;

    vector<int> t;

    int ans = 0;

    int in;
    int num = 0;
    for(int i=0;i<n;i++){
        cin >> in;
        t.push_back(in);
    }

    sort(t.begin(), t.end());
    vector<int> t_ = t;

    m -= t.size();
    
    for(;;){

        ans++;
        
        for(int k = 0;k<n;k++){
            if(m >0 && t[k] == 0){
                m--;
                t[k] = t_[k];
            }
        }

        
     
        num = 0;
        //ここで１すすめる
        for(int k = 0;k<n;k++){
            if(t[k]>0){
                t[k]--;
            }
            num += t[k];
        }

        if( m<1 && num  < 1){
            cout << ans << endl;
            return 0;
        }
    }
}
