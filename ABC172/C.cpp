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

// vector<vector<int>> data(3, vector<int>(4));

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> timea(n);
  vector<ll> timeb(n);
  rep(i, n) cin >> timea[i];
  rep(i, m) cin >> timeb[i];

  ll time = 0;
  ll b = 0;

  ll ans = 0;

  rep(i, n + 1) {
    ll t = time;
    while (1) {
      t += timeb[b];
      if (t > k || b >= m) break;
      b++;
    }

    // cout << i << " " << b << endl;
    if (time > k) break;
    ans = max(ans, i + b);
    time += timea[i];

    b = 0;
  }

  cout << ans;

  return 0;
}