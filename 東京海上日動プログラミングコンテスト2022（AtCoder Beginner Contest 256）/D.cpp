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

  ll n;
  cin >> n;

  vector<pair<ll, int>> vec;
  ll tmp1, tmp2;
  rep(i, n) {
    cin >> tmp1;
    cin >> tmp2;
    vec.push_back(make_pair(tmp1, 0));
    vec.push_back(make_pair(tmp2, 1));
  }
  sort(vec.begin(), vec.end());

  ll open = 0;
  rep(i, 2 * n) {
    // cout << "now= " << vec[i].first << endl;
    if (open == 0 && vec[i].second == 0) {
      cout << vec[i].first << " ";
      open++;
    } else if (open == 1 && vec[i].second == 1) {
      cout << vec[i].first << endl;
      open--;
    } else if (vec[i].second == 1) {
      open--;
    } else if (vec[i].second == 0) {
      open++;
    }
    // cout << "OPN" << open << endl;
  }

  return 0;
}