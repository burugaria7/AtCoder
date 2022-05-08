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

// vector<vector<int>> data(3, vector<int>(4));

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll h, w, m;
  cin >> h >> w >> m;

  int h_, w_;
  vector<ll> h_vec(h, 0);
  vector<ll> w_vec(w, 0);

  int max_h = -1;
  int max_w = -1;

  int max_hh;
  int max_ww;

  ll ans = 0;

  typedef std::pair<int, int> pair;
  std::vector<pair> pair_vec;

  ll max = 0;
  rep(i, m) {
    cin >> h_ >> w_;
    h_--;
    w_--;

    pair_vec.push_back(pair(h_, w_));

    h_vec[h_]++;
    w_vec[w_]++;

    if (max_h < h_vec[h_]) {
      max_h = h_vec[h_];
      max_hh = h_;
    }
    if (max_w < w_vec[w_]) {
      max_w = w_vec[w_];
      max_ww = w_;
    }

    if (std::find(pair_vec.begin(), pair_vec.end(), pair(max_hh, max_ww)) !=
        pair_vec.end()) {
      /* v contains x */
      ans = fmax(ans, max_w + max_h - 1);
    } else {
      /* v does not contain x */
      ans = fmax(ans, max_w + max_h);
    }
  }

  // cout << max;
  printf("%lld", ans);

  return 0;
}