#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int, int>;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

const int MOD = 1000000007;

// vector<vector<int>> data(3, vector<int>(4));

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<ll> s;
  vector<vector<int>> ban(n, vector<int>(10, -1));

  string s1;
  istringstream ss1;
  ll tmp;
  rep(i, n) {
    cin >> s1;
    ss1 = istringstream(s1);
    ss1 >> tmp;
    // cout << "tmp=" << tmp << endl;

    rep(k, 10) {
      int kazu = tmp % 10;
      // cout << "M = " << kazu;
      ban[i][kazu] = 9 - k;
      tmp /= 10.0;
    }
    // cout << "\n";
  }

  // rep(k, n) {
  //   rep(i, 10) { cout << ban[k][i] << " "; }
  //   cout << "" << endl;
  // }

  int ans = INF;
  int time;
  set<int> st;
  //まずiでそろえるときを考える
  rep(i, 10) {
    time = 0;
    st = {};
    // l個目のリールを揃える
    rep(l, n) {
      //ボタン押せるまでループ
      while (true) {
        if (st.find(ban[l][i]) != st.end()) {
          ban[l][i] += 10;
        } else {
          time = max(time, ban[l][i]);
          cout << "数字" << i << "リール" << l << "時間" << ban[l][i] << endl;
          st.insert(ban[l][i]);
          break;
        }
      }
    }

    ans = min(ans, time);
  }

  cout << ans;

  return 0;
}