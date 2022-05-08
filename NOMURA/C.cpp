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

  int n;
  cin >> n;
  int ans = 0;
  int a;
  cin >> a;
  int buf = 2 - a;

  vector<int> vec;
  vec.push_back(2);

  vector<int> inp;

  FOR(i, 1, n + 1) {
    cin >> a;
    ans += a;
    inp.push_back(a);
    // cout << a << endl;
    vec.push_back((vec[i - 1] - a) * 2);
  }

  reverse(vec.begin(), vec.end());
  reverse(inp.begin(), inp.end());

  ans += inp[0];

  FOR(i, 1, n) {
    cout << vec[i] << "::" << inp[i] << endl;
    if (vec[i] / 2 >= inp[i]) {
      ans += inp[i];
    } else {
      ans += vec[i];
    }
    }

  cout << ans << endl;

  return 0;
}