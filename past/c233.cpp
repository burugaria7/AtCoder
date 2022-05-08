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
  ll n;
  ll x;
  vector<ll> num;
  ll tmp;
  ll tmpp;
  cin >> n >> x;
  vector<vector<ll>> data(n, vector<ll>());

  cin >> tmp;
  rep(j, tmp) {
    cin >> tmpp;
    if (x >= tmpp && x % tmpp == 0) {
      data[0].push_back(x / tmpp);
    }
  }

  rep(i, n - 1) {  // i:深さ
    cin >> tmp;
    rep(j, tmp) {
      cin >> tmpp;
      // cout << "input=" << tmpp << endl;
      for (auto a : data[i]) {  //各数に対して処理
        if (a >= tmpp && a % tmpp == 0) {
          // cout << "a=" << a << " tmpp " << tmpp << endl;
          data[i + 1].push_back(a / tmpp);
        }
      }
    }
  }

  ll n_count = count(data[n - 1].begin(), data[n - 1].end(), 1);
  cout << n_count;
}