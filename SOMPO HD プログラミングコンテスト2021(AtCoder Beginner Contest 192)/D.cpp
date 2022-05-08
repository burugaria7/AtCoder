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

class Radix {
 private:
  const char* s;
  int a[128];

 public:
  Radix(const char* s = "0123456789ABCDEF") : s(s) {
    int i;
    for (i = 0; s[i]; ++i) a[(int)s[i]] = i;
  }
  std::string to(long long p, int q) {
    int i;
    if (!p) return "0";
    char t[64] = {};
    for (i = 62; p; --i) {
      t[i] = s[p % q];
      p /= q;
    }
    return std::string(t + i + 1);
  }
  std::string to(const std::string& t, int p, int q) { return to(to(t, p), q); }
  long long to(const std::string& t, int p) {
    int i;
    long long sm = a[(int)t[0]];
    for (i = 1; i < (int)t.length(); ++i) sm = sm * p + a[(int)t[i]];
    return sm;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  Radix r;

  unsigned long long x, m;
  // cin >> x >> m;

  scanf("%10llu", &x);
  scanf("%10llu", &m);

  unsigned long long xx = x;
  printf("%10llu\n", x);
  cout << to_string(x) << endl;

  unsigned long long maxx = 0;
  rep(i, log10(x) + 1) {
    maxx = fmax(maxx, x % 10);
    x /= 10;
  }

  unsigned long long ans = 0;

  maxx++;
  while (1) {
    // n 進文字列を 10 進数に

    unsigned long long sss = r.to(to_string(xx), maxx);
    // printf("%lld\n", sss);
    if (sss <= m) {
      ans++;
    } else {
      break;
    }

    maxx++;
  }

  cout << ans;

  return 0;
}