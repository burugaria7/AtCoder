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

vector<ll> vec;  //素因数分解で出てきた素数を全て挿入するvector

// O(√n)
//整列済み
void prime_factorize(ll n) {
  if (n <= 1) return;
  ll l = sqrt(n);
  FOR(i, 2, l) {
    if (n % i == 0) {
      prime_factorize(i);
      prime_factorize(ll(n / i));
      return;
    }
  }
  vec.push_back(n);
  return;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int k;

  cin >> k;

  if (k % 2 == 0) {
    cout << "-1";
    return 0;
  }
  if (k == 7) {
    cout << "1";
    return 0;
  }

  int nana = 0;
  for (int n = 1;; n++) {
    nana *= 10;
    nana += 7;
    if (nana % k == 0) {
      cout << n + 1;
      return 0;
    }
  }
}