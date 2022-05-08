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

unsigned GetDigit(unsigned num) { return log10(num) + 1; }
unsigned ketame(int n, int x) {
  n /= pow(10, x - 1);
  return n % 10;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int str;
  cin >> str;

  int keta = GetDigit(str);

  if (keta <= 3) {
    int kazu = str;

    if (kazu != 0 && kazu >= 8 && kazu % 8 == 0) {
      cout << "Yes";
    } else {
      cout << "No";
    }
    return 0;
  }

  rep(i, keta) {
    //作成する３桁の数字のうち下１桁をstr[1]で固定
    if (ketame(str, i) % 2 == 0) {
      rep(j, keta) {
        if (j == i) continue;
        rep(k, keta) {
          if (k == i || j == k) continue;
          int hati =
              ketame(str, j) * 100 + ketame(str, k) * 10 + ketame(str, i);
          // cout << j << " " << k << " " << i << endl;
          if (hati % 8 == 0) {
            cout << "Yes";
            return 0;
          }
        }
      }
    }
  }

  cout << "No";

  return 0;
}