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

  vector<int> x;
  vector<int> y;

  int x_, y_;
  rep(i, n) {
    cin >> x_ >> y_;
    x.push_back(x_);
    y.push_back(y_);
  }

  int x_1, x_2, x_3;
  int y_1, y_2, y_3;

  rep(i, n) {
    rep(k, n - i - 2) {
      rep(j, n - i - k - 2) {
        cout << i << " : " << k + i + 1 << " : " << k + i + j + 2 << endl;

        x_1 = x[i];
        x_2 = x[k + i + 1];
        x_3 = x[k + i + j + 2];

        y_1 = y[i];
        y_2 = y[k + i + 1];
        y_3 = y[k + i + j + 2];

        // cout << i << " : " << k + i + 1 << " : " << k + i + 2 << endl;
        // cout << "AAA= " << y_1 * (x_2 - x_3) + y_2 * (x_3 - x_1) + y_3 * (x_1
        // - x_2) << endl;

        if ((y_1 * (x_2 - x_3) + y_2 * (x_3 - x_1) + y_3 * (x_1 - x_2)) == 0) {
          cout << "Yes";
          return 0;
        }
      }
    }
  }

  cout << "No";

  return 0;
}