#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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

  ll n;
  cin >> n;

  vector<ll> vec;

  ll tmp;

  ll mae = -1;

  ll minmin = INF;

  // vector<ll> kaisu_2(n, 0);
  // vector<ll> kaisu_3(n, 0);

  ll ans = 0;

  rep(i, n) {
    cin >> tmp;
    minmin = min(minmin, tmp);
    while (tmp % 3 == 0) {
      tmp /= 3;
      // kaisu_3[i]++;
      ans++;
    }
    while (tmp % 2 == 0) {
      tmp /= 2;
      // kaisu_2[i]++;
      ans++;
    }
    if (i != 0) {
      if (mae != tmp) {
        cout << "-1";
        return 0;
      }
    }
    vec.push_back(tmp);
    // cout << tmp;
    mae = tmp;
  }

  // cout << ans << endl;

  // ll ans = 0;
  // for (auto a : vec) {
  // }

  ll kosu = 0;

  while (minmin % 3 == 0) {
    minmin /= 3;
    kosu++;
  }
  while (minmin % 2 == 0) {
    minmin /= 2;
    kosu++;
  }

  kosu *= n;

  ans -= kosu;

  cout << ans;

  return 0;
}