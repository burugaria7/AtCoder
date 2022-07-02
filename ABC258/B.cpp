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

  int n;
  cin >> n;

  vector<vector<int>> data(3 * n, vector<int>(3 * n, 0));

  string tmp;
  int sum = 0;
  int ans = 0;
  int ans_itr;
  rep(i, n) {
    sum = 0;
    cin >> tmp;
    rep(j, n) {
      int tm = stoi(tmp.substr(j, 1));
      data[i][j] = tm;
    }
  }

  rep(i, n) {
    rep(k, n) { data[i][k + n] = data[i][k]; }
    rep(k, n) { data[i][k + 2 * n] = data[i][k]; }
  }
  rep(i, 3 * n) {
    rep(k, n) { data[k + n][i] = data[k][i]; }
    rep(k, n) { data[k + 2 * n][i] = data[k][i]; }
  }

  int maxx = -1;
  ll anss;
  ll anss_max = -1;
  rep(i, n) {
    rep(j, n) {
      //それぞれの拡張前のますの近辺をみて最大をだす
      maxx = -1;

      for (int del_x = -1; del_x < 2; del_x++) {
        for (int del_y = -1; del_y < 2; del_y++) {
          if (del_x == 0 && del_y == 0) continue;
          anss = 0;
          rep(k, n) {
            anss += data[i + n + del_x * k][j + n + del_y * k];
            if (!(k == n - 1)) {
              anss *= 10;
            }
          }
          anss_max = max(anss_max, anss);
        }
      }

      // cout << delx << dely << endl;
    }
  }

  // for (auto a : data) {
  //   for (auto b : a) {
  //     cout << b;
  //   }
  //   cout << "\n";
  // }

  cout << anss_max;

  return 0;
}