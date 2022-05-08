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

// vector<int> g1_memo(1000000005, -1);
// vector<int> g2_memo(1000000005, -1);
// vector<int> f_memo(1000000005, -1);

ll g1(int x) {
  // if (g1_memo[x] != -1) {
  //   return g1_memo[x];
  // }
  int ze = 0;
  vector<int> vec;
  ll xx = x;
  rep(i, log10(xx) + 1) {
    if (x % 10 == 0) {
      ze++;
    } else {
      vec.push_back(x % 10);
    }
    x /= 10;
  }
  sort(vec.begin(), vec.end(), std::greater<int>());

  ll ans = 0;
  rep(i, log10(xx) + 1 - ze) {
    ans *= 10;
    // cout << vec[i] << endl;
    ans += vec[i];
  }
  rep(i, ze) { ans *= 10; }

  // cout << ans << endl;
  // g1_memo[x] = ans;

  return ans;
}

ll g2(ll x) {
  // if (g2_memo[x] != -1) {
  //   return g2_memo[x];
  // }
  vector<int> vec;
  ll xx = x;
  int ze = 0;
  rep(i, log10(xx) + 1) {
    if (x % 10 == 0) {
    } else {
      vec.push_back(x % 10);
    }
    x /= 10;
  }
  sort(vec.begin(), vec.end());

  ll ans = 0;
  rep(i, log10(xx) + 1 - ze) {
    ans *= 10;
    // cout << vec[i] << endl;
    ans += vec[i];
  }

  // cout << ans << endl;
  // g2_memo[x] = ans;
  return ans;
}

ll f(ll x) {
  // if (f_memo[x] != -1) {
  //   return f_memo[x];
  // }
  // f_memo[x] = g1(x) - g2(x);
  return g1(x) - g2(x);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  ll x = n;

  rep(i, k) {
    // cout << "test";
    if (x == 0) break;
    x = f(x);
    // cout << x << endl;
  }

  cout << x;

  return 0;
}