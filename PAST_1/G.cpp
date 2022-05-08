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
int dat[9][9];
int n;
int ans = -9999999;
void saiki(int x,vector<int> vec){
    if(x == -1){
        int kouhuku = 0;
        set<int> gro[3];
        rep(i,n){
            gro[vec[i]].insert(i);
        }
        for(auto aa:gro){
            rep(i,n-1){
                int roop_ = n-1;
                rep(k,roop_){
                    if(aa.count(i)>0&&aa.count(k+i+1)){
                        kouhuku += dat[i][k+i+1];
                    }
                }
            roop_--;
            }
        }
        ans = max(ans,kouhuku);
        return;
    }
    if(x>=0){
        vec.push_back(0);
        saiki(x-1,vec);
        vec.pop_back();

        vec.push_back(1);
        saiki(x-1,vec);
        vec.pop_back();

        vec.push_back(2);
        saiki(x-1,vec);
    }

}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int inp;
    int roop = n-1;
    rep(i,n-1){
        rep(k,roop){
            cin >> inp;
            dat[i][k+i+1] = inp;
        }
        roop--;
    }
    vector<int> ve;
    saiki(n,ve);
    cout << ans;
    return 0;
}