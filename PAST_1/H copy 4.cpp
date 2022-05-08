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
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
typedef pair<long long, long long> P;

#define REP(i, n) for (long long i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (long long i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (long long i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

// vector<vector<long long>> data(3, vector<long long>(4));
// vector<long long> cards;  // odd
// vector<long long> cards_;
vector<long long> card;
// set<long long> zaikogire;
long long minmin = 1000000005;
long long min_;
long long min_odd = 1000000005;
long long unsigned ans = 0;
long long buy_all = 0;
long long buy_odd = 0;

long long n;

void uru(long long x, long long a) {
  long long buf;
  if (x % 2 == 0) {
    buf = buy_all + buy_odd;
  } else {
    buf = buy_all;
  }

  if (card[x] - buf >= a) {
    card[x] -= a;
    ans += a;
    min_ = min(min_, card[x]);
    if (x % 2 == 0) {
      min_odd = min(min_odd, card[x]);
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;

  long long buf;
  rep(i, n) {
    cin >> buf;
    minmin = min(minmin, buf);
    if (i % 2 == 0) {
      min_odd = min(min_odd, buf);
    }
    card.push_back(buf);
  }

  min_ = minmin;

  long long q;
  cin >> q;

  long long x, a;
  for (; q > 0; q--) {
    cin >> buf;

    if (buf == 1) {
      cin >> x >> a;
      x--;

      uru(x, a);

      // cout << "1: " << ans << endl;

    } else if (buf == 2) {
      cin >> a;
      if (min_odd - buy_all - buy_odd >= a) {
        buy_odd += a;
        ans += a * (n / 2);
      }
      // cout << "2: " << ans << endl;
    } else {
      cin >> a;
      if (min_ - buy_all >= a && min_odd - buy_odd - buy_all >= a) {
        buy_all += a;
        ans += a * n;
      }
      // cout << "3: " << ans << endl;
    }

    // rep(i, n) {
    //   if (i % 2 == 0) {
    //     cout << "AA: " << card[i]
    //   }
    // }
    // cout << "" << endl;
  }

  // cout << ans;
  printf("%llu", ans);

  return 0;
}