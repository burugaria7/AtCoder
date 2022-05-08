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

    vector<int> vec;
    int buf;
    rep(i,6){
        cin >> buf;
        vec.push_back(buf):
    }

    std::sort(vec.begin(),vec.end());

    cout << vec[2];


    return 0;
}