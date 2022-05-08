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

  int alp[500];
  rep(i, 500) { alp[i] = 0; }
  bool low = false;
  bool upr = false;

  rep(i, str.size()) {
    char c = str[i];
    if (islower(c)) {
      low = true;
    }
    if (isupper(c)) {
      upr = true;
    }
    int suuti = c - '0';
    alp[suuti]++;
  }

  int ma = *max_element(alp, alp + 500);
  cout << ma;
  if (ma == 1 && low && upr) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}