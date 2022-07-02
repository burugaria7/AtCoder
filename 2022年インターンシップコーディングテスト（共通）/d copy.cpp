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

  ll a, b, n;
  cin >> a >> b >> n;

  ll p = 0;
  ll day = -1;
  while (p < n) {
    day++;
    p += a;
    // std::string str = std::to_string(day);
    // char const *num_char = str.c_str();

    ll day_ = day;

    while (day_ > 9) {
      int keta = day_ % 10;
      if (keta == 7) {
        p += b;
        break;
      }
      day_ /= 10;
    }
  }

  cout << day;

  return 0;
}