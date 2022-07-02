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

void saiki(ll now, ll money, bool pass, bool one) {
  if (money >= ans) return;
  //最後の処理
  if (now == n) {
    // cout << money << endl;
    if (ans > money) {
      ans = money;
    }
    return;
  }
  //一個前にきたら=最後のタス処理
  if (now == n - 1) {
    if (one) {
      saiki(now + 1, money + vec[now], false, one);
    } else if (pass) {
      saiki(now + 1, money + vec[now], true, one);
    } else {
      saiki(now + 1, money, false, one);
    }
    return;
  }
  //前回パスされてたら
  if (pass) {
    saiki(now + 1, money + vec[now], false, one);
  } else {
    saiki(now + 1, money + vec[now], false, one);
    saiki(now + 1, money, true, one);
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