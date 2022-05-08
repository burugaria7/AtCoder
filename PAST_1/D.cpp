#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <iomanip>
#include <queue>
#include <cctype>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<bool> fl;

    rep(i,n){
        fl.push_back(false);
    }

    int ans1 = -1;

    int inp;
    rep(i,n){
        cin >> inp;
        inp--;

        if(fl[inp]){
            ans1 = inp;
        }else{
            fl[inp] = true;
        }

    }

    if(ans1==-1){
        cout << "Correct";
        return 0;
    }

    int ans2;

    rep(i,n){
        if(!fl[i]){
            ans2 = i;
        }
    }

    cout << ans1+1 <<" "<< ans2+1;




    return 0;
}