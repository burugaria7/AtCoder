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

  ll x, a, d, n;
  cin >> x >> a >> d >> n;

  if (x == a) {
    cout << "0";
    return 0;
  }
  if (d == 0) {
    cout << abs(a - x);
  }

  ll matu = a + (n - 1) * d;

  if (x <= a) {
    ll ans = min(abs(a - x), abs(matu - x));
    cout << ans;
    return 0;
  }
  if (matu <= x) {
    ll ans = min(abs(a - x), abs(matu - x));
    cout << ans;
    return 0;
  }

  ll alpha = abs(x - a) / (double)abs(d);
  // ll beta = abs(matu - x) % d;

  ll aa = a + d * alpha;

  // ll bb = matu - d * beta;
  // ll aaa = a + d * (alpha + 1);

  // cout << aa << aaa << endl;

  ll ans = min(abs(x - aa), abs(abs(d) - abs(x - abs(x - aa))));

  cout << ans;

  return 0;
}