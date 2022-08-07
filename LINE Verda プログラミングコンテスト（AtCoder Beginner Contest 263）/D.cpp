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

  ll n, l, r;
  cin >> n >> l >> r;

  vector<ll> vec;
  vector<ll> wa;
  vector<ll> sa;

  ll a;
  cin >> a;
  vec.push_back(a);
  wa.push_back(a);
  rep(i, n - 1) {
    cin >> a;
    vec.push_back(a);
    wa.push_back(wa[i] + a);
    sa.push_back(l * (i + 1) - wa[i]);
  }

  auto itt = std::minmax_element(sa.begin(), sa.end());
  ll min_idx = std::distance(sa.begin(), itt.first);

  //置き換えるか置き換えないか
  if (sa[min_idx] < 0) {
    rep(i, min_idx + 1) { vec[i] = l; }
  }

  // for (auto a : vec) {
  //   cout << a << " ";
  // }
  // cout << "\n";

  vector<ll> saka;
  saka.push_back(vec[n - 1]);
  vector<ll> sasa;
  rep(i, n - 1) {
    saka.push_back(saka[i] + vec[n - 1 - i]);
    sasa.push_back(r * (i + 1) - saka[i]);
  }

  auto itt_ = std::minmax_element(sasa.begin(), sasa.end());
  ll min_idx_ = std::distance(sasa.begin(), itt_.first);
  // cout << min_idx_;
  // 置き換えるか置き換えないか
  if (sasa[min_idx_] < 0) {
    // rep(i, min_idx_ + 1) { cout << "a"; }
    rep(i, min_idx_ + 1) { vec[n - 1 - i] = r; }
  }

  // for (auto a : vec) {
  //   cout << a << " ";
  // }
  // cout << "\n";

  ll su = std::accumulate(vec.begin(), vec.end(), 0);
  cout << su;

  return 0;
}