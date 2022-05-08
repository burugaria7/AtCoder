#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
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

  int n, w;
  cin >> n >> w;

  vector<long> ou(n);
  vector<long> s_(n);
  vector<long> t_(n);
  long s, t, p;
  rep(i, n) {
    cin >> s >> t >> p;
    s_[i] = s;
    t_[i] = t;
    ou[i] = p;
  }

  cout << n;

  rep(i, n) {
    long oyu = 0;

    cout << i << endl;
    rep(k, n) {
      if (i == k) {
        oyu -= ou[i];
      }
      cout << i << k << endl;
      // cout << s_[k] << t_[i] << s_[i] << t_[k] << endl;
      if (!(s_[k] < t_[i] && s_[i] <= t_[k])) {
        oyu += ou[k];
      }
      cout << "OU" << oyu << endl;
      if (oyu > ou[i]) {
        cout << "No";
        return 0;
      }
    }
  }
  cout << "Yes";
  return 0;
}