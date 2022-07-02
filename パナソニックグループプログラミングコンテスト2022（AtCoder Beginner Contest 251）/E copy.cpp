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

vector<ll> vec;
ll n;
ll ans = INF;

ll saiki(ll now, bool pass) {
  if (now = n) {
    return;
  }
  //前回パスされてたら
  if (pass) {
    saiki(now + 1, false) + vec[now];
  } else {
    min(saiki(now + 1, false) + vec[now], saiki(now + 1, false));
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;

  ll tmp;
  rep(i, n) {
    cin >> tmp;
    vec.push_back(tmp);
  }

  saiki(1, 0 + vec[0], false, false);
  saiki(1, 0, false, true);

  cout << ans;

  return 0;
}