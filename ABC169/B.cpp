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

bool is_product_overflow(long long unsigned a, long long unsigned b) {
  long long prod = a * b;

  return (prod / b == a);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  long long unsigned a;

  long long unsigned n;
  cin >> n;
  vector<long long unsigned> vec;

  for (long long unsigned i = 0; i < n; i++) {
    cin >> a;
    if (a == 0) {
      cout << "0";
      return 0;
    }
    if (a > 1000000000000000000) {
      cout << "-1";
      return 0;
    }
    vec.push_back(a);
  }
  sort(vec.begin(), vec.end(), std::greater<int>());

  long long unsigned ans = 1;
  for (long long unsigned i = 0; i < n; i++) {
    if (!is_product_overflow(ans, vec[i])) {
      // cout << "test";
      cout << "-1";
      return 0;
    }
    ans *= vec[i];
    // printf("%llu\n", ans);
    if (ans > 1000000000000000000 && ans < 0) {
      cout << "-1";
      return 0;
    }
  }

  if (ans > 1000000000000000000) {
    cout << "-1";
    return 0;
  }
  printf("%llu", ans);

  return 0;
}