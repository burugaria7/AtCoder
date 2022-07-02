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

  ll n, k;
  cin >> n >> k;

  if (k == 1) {
    cout << "Yes";
    return 0;
  }

  vector<vector<ll>> data(k, vector<ll>());

  vector<ll> vec;
  ll tmp;
  rep(i, n) {
    cin >> tmp;
    vec.push_back(tmp);
  }

  // k個の配列に分ける
  rep(i, k) {
    rep(j, n / k + 1) {
      if (j * k + i >= n) {
        break;
      }
      data[i].push_back(vec[j * k + i]);
      // cout << j * k + i << " ";
    }
    // cout << "\n";
    sort(data[i].begin(), data[i].end());
  }

  vector<ll> ans;
  rep(i, n / k + 1) {
    rep(j, k) {
      if (i >= data[j].size()) {
        break;
      }
      // cout << j << "&" << i << " ";
      ans.push_back(data[j][i]);
    }
    // cout << "\n";
  }

  sort(vec.begin(), vec.end());

  if (vec == ans) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}