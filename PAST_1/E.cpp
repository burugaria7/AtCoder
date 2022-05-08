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

    int n,q;
    cin >> n >> q;

    vector<set<int>> fl(n);
    vector<set<int>> fled(n);


    int x,a,b;
    rep(i,q){
        cin >> x;
        if(x==1){

            cin >> a >> b;
            a--;b--;
            
            fl[a].insert(b);
            fled[b].insert(a);

        }else if(x==2){

            cin >> a;
            a--;

            for(auto aa:fled[a]){
                fl[a].insert(aa);
                fled[aa].insert(a);
            }

        }else{
            cin >> a;
            a--;

            vector<int> buf;

            for(auto aa:fl[a]){
                for(auto bb:fl[aa]){
                    if(bb!=a){
                        buf.push_back(bb);
                        
                    }
                }
            }

            for(auto aa:buf){
                fl[a].insert(aa);
                fled[aa].insert(a);
            }

        }

    }


    rep(aa,n){
        rep(bb,n){
            if(aa!=bb&&fl[aa].count(bb)>0){
                cout << "Y";
            }else{
                cout << "N";
            }
        }
        cout << "" << endl;
    }


    return 0;
}