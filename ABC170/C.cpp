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
typedef pair<int, int> P;

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

  int x, n;
  cin >> x >> n;
  int tmp;
  set<int> set;
  int ans;
  rep(i, n) {
    cin >> tmp;
    set.insert(tmp);
  }
  for (int i = 0;; i++) {
    ans = x - i;
    if (!set.count(ans)) {
      cout << ans;
      return 0;
    }
    ans = x + i;
    if (!set.count(ans)) {
      cout << ans;
      return 0;
    }
  }

  return 0;
}