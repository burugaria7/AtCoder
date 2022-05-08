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
typedef pair<int, int> P;

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

  int n, k;
  cin >> n >> k;
  vector<int> vec(n, 0);

  int buf;
  int kara;
  int made;
  rep(i, n) {
    cin >> buf;
    kara = i - buf;
    if (kara < 0) kara = 0;
    made = i + buf;
    if (made > n) made = n;
    for (int k = kara; k <= made; k++) {
      vec[k]++;
    }
  }
  k--;
  int minn = 9999999999;
  while (k > 0) {
    vector<int> vec_(n, 0);
    rep(i, n) {
      minn = min(minn, vec[i]);
      buf = vec[i];
      kara = i - buf;
      if (kara < 0) kara = 0;
      made = i + buf;
      if (made >= n) made = n - 1;
      for (int k = kara; k <= made; k++) {
        vec_[k]++;
      }
    }
    vec = vec_;
    k--;
    if (minn >= n) {
      rep(i, n) { cout << n << " "; }
    }
  }

  for (int i : vec) {
    cout << i << " ";
  }

  return 0;
}