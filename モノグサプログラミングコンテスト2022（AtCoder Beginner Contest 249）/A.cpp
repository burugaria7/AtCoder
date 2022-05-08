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

  vector<ll> vec;

  int n;
  rep(i, 7) {
    cin >> n;
    vec.push_back(n);
  }

  int taka;
  int taka_root = (vec[6] / (vec[0] + vec[2]) * vec[1] * vec[0]);

  if (vec[6] % (vec[0] + vec[2]) >= vec[0]) {
    taka = taka_root + vec[1] * vec[0];
  } else {
    taka = taka_root + vec[1] * (vec[6] % (vec[0] + vec[2]));
  }

  int aoki;
  int aoki_root =
      (vec[6] / (vec[0 + 3] + vec[2 + 3]) * vec[1 + 3] * vec[0 + 3]);
  if (vec[6] % (vec[0 + 3] + vec[2 + 3]) >= vec[0 + 3]) {
    aoki = aoki_root + vec[1 + 3] * vec[0 + 3];
  } else {
    aoki = aoki_root + vec[1 + 3] * (vec[6] % (vec[0 + 3] + vec[2 + 3]));
  }

  if (taka == aoki) {
    cout << "Draw";
  } else if (taka > aoki) {
    cout << "Takahashi";
  } else {
    cout << "Aoki";
  }

  return 0;
}