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
  vector<long> vec(n, 0);

  long buf;
  long kara;
  long made;
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

  vector<long> vec_(n, 0);
  rep(i, n) {
    buf = vec[i];
    kara = i - buf - k;
    if (kara < 0) kara = 0;
    made = i + buf + k;
    if (made >= n) made = n - 1;
    for (int k = kara; k <= made; k++) {
      vec_[k]++;
    }
  }
  vec = vec_;

  for (long i : vec) {
    cout << i << " ";
  }

  return 0;
}