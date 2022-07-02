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

#include <bits/stdc++.h>
using namespace std;
// 素因数分解
template <typename T>
map<T, T> prime_factor(T n) {
  map<T, T> ret;
  for (T i = 2; i * i <= n; i++) {
    T tmp = 0;
    while (n % i == 0) {
      tmp++;
      n /= i;
    }
    ret[i] = tmp;
  }
  if (n != 1) ret[n] = 1;
  return ret;
}
/*  divisor_num(n)
    入力：整数 n
    出力：nの約数の個数
    計算量：O(√n)
*/
template <typename T>
T divisor_num(T N) {
  map<T, T> pf = prime_factor(N);
  T ret = 1;
  for (auto p : pf) {
    ret *= (p.second + 1);
  }
  return ret;
}

// 平方数かどうかの判定
bool is_squere(long long N) {
  long long r = (long long)floor(sqrt((long double)N));  // 切り捨てした平方根
  return (r * r) == N;
}
long long N;

// vector<vector<int>> data(3, vector<int>(4));

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  ll ans = 0;
  ll num;

  ll num;
  for (ll i = 1; i <= n; i++) {
    for (ll k = 2; k * k <= i; k++) {
      num = i * k * k;
      if (num <= n) {
        ans++;
      } else {
        break;
      }
    }
  }

  cout << ans;

  return 0;
}