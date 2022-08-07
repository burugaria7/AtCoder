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

  int n, p;
  cin >> n;

  vector<int> ko_to_oya;
  ko_to_oya.push_back(-1);
  rep(i, n - 1) {
    cin >> p;
    ko_to_oya.push_back(p - 1);
  }

  int ans = 0;
  int ko = n - 1;
  rep(i, n) {
    int oya = ko_to_oya[ko];
    if (oya == 0) {
      cout << ans;
      return 0;
    } else {
      ans++;
      ko = oya;
    }
  }
  cout << ans;

  return 0;
}