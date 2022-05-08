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

bool jd(ll x, ll y, ll a, ll b) {
  if (x + y == a + b) return true;
  if (x - y == a - b) return true;
  if (abs(x - a) + abs(y - b) <= 3) return true;

  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll x, y, a, b;
  cin >> x >> y >> a >> b;

  if (x == a && y == b) {
    cout << "0";
    return 0;
  }
  if (jd(x, y, a, b)) {
    cout << "1";
    return 0;
  }
  // 2222222222222222

  for (int i = -2; i <= 2; i++) {
    for (int k = -2; k <= 2; k++) {
      ll xx = x + i;
      ll yy = y + k;
      if (jd(xx, yy, a, b)) {
        cout << "2";
        return 0;
      }
    }
  }

  if (jd(x + 3, y, a, b)) {
    cout << "2";
    return 0;
  }
  if (jd(x - 3, y, a, b)) {
    cout << "2";
    return 0;
  }
  if (jd(x, y + 3, a, b)) {
    cout << "2";
    return 0;
  }
  if (jd(x, y - 3, a, b)) {
    cout << "2";
    return 0;
  }

  ll xdd = abs(x - a);
  ll ydd = abs(y - b);
  if (xdd % 2 == 0 && ydd % 2 == 0) {
    cout << "2";
    return 0;
  }
  if (xdd % 2 == 1 && ydd % 2 == 1) {
    cout << "2";
    return 0;
  }
  cout << "3";
  return 0;
}