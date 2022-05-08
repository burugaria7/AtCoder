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

  string str;
  cin >> str;

  if (str.size() <= 3) {
    int kazu = stoi(str);

    if (kazu != 0 && kazu >= 8 && kazu % 8 == 0) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    return 0;
  }

  rep(i, str.size()) {
    //作成する３桁の数字のうち下１桁をstr[1]で固定
    if (stoi(str.substr(i, 1)) % 2 == 0) {
      rep(j, str.size()) {
        if (j == i) continue;
        rep(k, str.size()) {
          if (k == i || j == k) continue;
          string str_ = str.substr(j, 1) + str.substr(k, 1) + str.substr(i, 1);
          int hati = stoi(str_);
          cout << j << " " << k << " " << i << endl;
          if (hati % 8 == 0) {
            // cout << "Yes";
            // return 0;
          }
        }
      }
    }
  }

  cout << "No";

  return 0;
}