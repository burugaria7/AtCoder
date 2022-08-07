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
  string s;
  cin >> n >> s;

  rep(i, n / 2) {
    if (s[i] == s[n - i - 1]) {
    } else {
      if (s[n - i - 1] == 'A' && s[n - i - 2] == 'B') {
        s[i] = 'A';
        s[i + 1] = 'B';
      } else if (s[i] == 'B' && s[i + 1] == 'A') {
        s[n - i - 1] = 'B';
        s[n - i - 2] = 'A';
      }
    }
  }
  bool ans = true;
  string s1 = s;
  string s2 = s;
  rep(i, n / 2) {
    if (s1[i] == s1[n - i - 1]) {
    } else {
      if (s1[n - i - 1] == 'A' && s1[n - i - 2] == 'B') {
        s1[i] = 'A';
        s1[i + 1] = 'B';
      } else if (s1[i] == 'B' && s1[i + 1] == 'A') {
        s1[n - i - 1] = 'B';
        s1[n - i - 2] = 'A';
      }
      if (s1[i] != s1[n - i - 1]) {
        cout << "No";
        ans = false;
        break;
      }
    }
  }
  cout << "Yes";
  return 0;
}