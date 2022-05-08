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
#include <functional>
#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

const int MOD = 1000000007;

// vector<vector<int>> data(3, vector<int>(4));

const int M = 100;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  int ans = 0;

  cin >> n >> k;

  vector<vector<int>> vec(n, vector<int>(M, 0));

  string str;
  rep(i, n) {
    cin >> str;
    for (char c : str) {
      int suuti = c - '0';
      // cout << suuti;
      vec[i][suuti]++;
    }
    // cout << "\n";
  }

  // int maxx = *max_element(vec[0].begin(), vec[0].end());
  // cout << maxx;

  for (int bit = 0; bit < (1 << n); ++bit) {
    vector<int> S;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {  // 列挙に i が含まれるか
        S.push_back(i);
      }
    }

    vector<int> v(M, 0);
    // cout << bit << ": {";
    for (int i = 0; i < (int)S.size(); ++i) {
      rep(l, M) { v[l] += vec[S[i]][l]; }
      // cout << S[i] << " ";
    }
    // cout << "}" << endl;

    int count = 0;
    rep(l, M) {
      if (v[l] == k) count++;
    }

    // if (count > 1) {
    //   for (size_t i = 49; i < 75; ++i) {
    //     cout << v[i] << "; ";
    //   }
    //   cout << endl;
    // }

    // cout << count << endl;
    ans = max(ans, count);
  }

  cout << ans;

  return 0;
}