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

  long s_x, s_y, g_x, g_y;
  cin >> s_x >> s_y >> g_x >> g_y;
  long y_min;
  if (g_x > s_x && s_y > g_y) {
    y_min = max(g_y, s_y);
  }
  if (g_x > s_x && s_y < g_y) {
    y_min = min(g_y, s_y);
  }
  if (g_x < s_x && s_y > g_y) {
    y_min = min(g_y, s_y);
  }
  if (g_x < s_x && s_y < g_y) {
    y_min = max(g_y, s_y);
  }

  double ans =
      min(s_x, g_x) + abs(s_x - g_x) * (double)y_min / (double)(s_y + g_y);

  printf("%lf", ans);

  return 0;
}