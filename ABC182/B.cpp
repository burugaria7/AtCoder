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

  int n;
  cin >> n;

  int ans = 0;

  int gcd = 0;
  int buf;
  vector<int> vec;
  rep(i, n) {
    cin >> buf;
    gcd = max(gcd, buf);
    vec.push_back(buf);
  }

  int anss = 0;
  for (int i = 2; i <= gcd; i++) {
    int ans_ = 0;
    for (int at : vec) {
      if (at % i == 0) {
        ans_++;
      }
    }
    if (ans_ >= ans) {
      cout << ans_ << "" << ans << endl;
      anss = i;
    }
  }

  cout << anss;

  return 0;
}