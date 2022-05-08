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

  ll x, k, d;
  cin >> x >> k >> d;

  //まず0にちかづける
  //今の場所が０になったら
  if (x == 0) {
    if (k == 0 || k % 2 == 0) {
      cout << 0;
      return 0;
    } else {
      cout << abs(x + d);
      return 0;
    }
  } else {  //できるだけ近づける
    if (x > 0) {
      //動かしたほうが０に近い
      if (abs(x) > d) {
        ll waru = x / d;
        if (k > waru) {
          x -= d * waru;
          k -= waru;
        } else {
          x -= k * d;
          k = 0;
        }
      }
    } else {
      if (abs(x) > d) {
        ll waru = abs(x) / d;
        if (k > waru) {
          x += d * waru;
          k -= waru;
        } else {
          x += k * d;
          k = 0;
        }
      }
    }

    if (k == 0 || k % 2 == 0) {
      cout << abs(x);
      return 0;
    } else {
      if (x > 0) {
        cout << abs(x - d);
        return 0;
      } else {
        cout << abs(x + d);
        return 0;
      }
    }
  }

  return 0;
}