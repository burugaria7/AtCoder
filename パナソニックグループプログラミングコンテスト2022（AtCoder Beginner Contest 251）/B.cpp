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

ll n, w;

vector<ll> vec;
vector<ll> v;

ll ans = 0;

void recursive_comb(int *indexes, int s, int rest,
                    std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> w;
  v = vector<ll>(w + 10, 0);
  int tmp;
  rep(i, n) {
    cin >> tmp;
    vec.push_back(tmp);
  }

  if (n > 2) {
    foreach_comb(n, 3, [](int *indexes) {
      ll www = vec[indexes[0]] + vec[indexes[1]] + vec[indexes[2]];
      if (www <= w && v[www] != 1) v[www]++;
    });
  }

  if (n > 1) {
    foreach_comb(n, 2, [](int *indexes) {
      ll www = vec[indexes[0]] + vec[indexes[1]];
      if (www <= w && v[www] != 1) v[www]++;
    });
  }

  foreach_comb(n, 1, [](int *indexes) {
    ll www = vec[indexes[0]];
    if (www <= w && v[www] != 1) v[www]++;
  });

  for (auto t : v) {
    if (t == 1) ans++;
  }

  cout << ans;

  return 0;
}