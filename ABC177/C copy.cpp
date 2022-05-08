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

  ll n;
  cin >> n;

 
  vector<ll> vec;

  ll ans = 0;

  ll buf;

  ll sum = 0;

  cin >> buf;
  sum += buf;
  sum %= MOD;
  vec.push_back(buf);

  vector<ll> vecc;
  vecc.push_back(buf);

  rep(i, n - 1) {
    cin >> buf;
    vecc.push_back(buf);
    sum += buf;
    sum %= MOD;
    vec.push_back((vec[i] + buf) % MOD);
  }

  rep(i, n - 2) {
    ans += (vecc[i] * ((sum - vec[i]) % MOD)) % MOD;
    ans %= MOD;
    // cout << vec[i] << endl;
  }

  ans += (vecc[vecc.size() - 2] * vecc[vecc.size() - 1]) % MOD;
  ans %= MOD;

  printf("%lld", ans);

  return 0;
}