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

  int x, y;
  cin >> x >> y;
  // turu i kame y-i
  int kame;
  int turu;

  turu = 0;
  kame = x - turu;
  // cout << turu << " " << kame<<endl;
  if (turu * 2 + kame * 4 == y) {
    cout << "Yes";
    return 0;
  }

  rep(i, x) {
    turu = i + 1;
    kame = x - turu;
    // cout << turu << " " << kame<<endl;
    if (turu * 2 + kame * 4 == y) {
      cout << "Yes";
      return 0;
    }
  }

  cout << "No";

  return 0;
}