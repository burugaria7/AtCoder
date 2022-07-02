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

int n;
vector<int> h(0);

ll dp(int now, int cost) {
  if (now == 20) {
    return cost;
  }
  if (now + 1 < 21) {
    cost + dp(now + 1, cost + abs(h[now] - h[now + 1]));
  }
  if (now + 2 < 21) {
    cost + dp(now + 2, cost + abs(h[now] - h[now + 2]));
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  rep(i, n) {
    int buf;
    cin >> buf;
    h.push_back(buf);
  }

  cout << dp(0, 0);

  return 0;
}