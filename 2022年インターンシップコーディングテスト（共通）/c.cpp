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

// vector<vector<int>> data(3, vector<int>(4));

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;

  vector<int> color(n);
  int tmp;
  rep(i, n) {
    cin >> tmp;
    color.push_back(tmp);
  }

  vector<vector<int>> data(m, vector<int>());
  int u, v;
  rep(i, m) {
    cin >> u;
    cin >> v;
    data[u].push_back(v);
    data[v].push_back(u);
  }

  // rep(time, k) {
  //   rep(banchi, n) {
  //     ll max = -1;
  //     for (auto a : data[banchi]) {
  //       max = fmax(max, color[a]);
  //     }
  //     vector<ll> vec;
  //     for (auto a : data[banchi]) {
  //       if (color[a] == max) vec.push_back(banchi);
  //     }
  //     int min = *min_element(vec.begin(), vec.end());
  //     color[banchi] = color[min];
  //   }
  // }

  // for (auto a : color) {
  //   cout << a << "\n";
  // }

  return 0;
}