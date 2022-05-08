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
vector<int> cards;  // odd
vector<int> cards_;
// set<int> zaikogire;
int minmin = 1000000005;
int min_;
int ans = 0;

int n;

void buy_all(int a) {
  rep(i, n / 2) {
    cards[i] -= a;
    cards_[i] -= a;
    ans += 2 * a;
  }
  min_ -= a;
}

void buy_odd(int a) {
  rep(i, n / 2) {
    cards[i] -= a;
    ans += a;
    min_ = min(min_, cards[i]);
  }
}

void uru(int x, int a) {
  if (x % 2 == 0) {
    if (cards[x / 2] >= a) {
      cards[x / 2] -= a;
      ans += a;
      min_ = min(min_, cards[x / 2]);
    }
  } else {
    if (cards_[x / 2] >= a) {
      cards_[x / 2] -= a;
      ans += a;
      min_ = min(min_, cards_[x / 2]);
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;

  int buf;
  rep(i, n) {
    cin >> buf;
    minmin = min(minmin, buf);
    if (i % 2 == 0) {
      cards.push_back(buf);
    } else {
      cards_.push_back(buf);
    }
  }

  min_ = minmin;

  int q;
  cin >> q;

  int x, a;
  for (; q > 0; q--) {
    cin >> buf;

    if (buf == 1) {
      cin >> x >> a;
      x--;

      uru(x, a);

      // cout << "1: " << ans << endl;

    } else if (buf == 2) {
      cin >> a;

      int min__ = *min_element(cards.begin(), cards.end());

      if (a <= min__) {
        buy_odd(a);
      }
      // cout << "2: " << ans << endl;
    } else {
      cin >> a;
      if (min_ >= a) {
        buy_all(a);
      }
      // cout << "3: " << ans << endl;
    }
    // for (auto aa : cards) {
    //   cout << aa << ":";
    // }
    // for (auto bb : cards_) {
    //   cout << bb << ":";
    // }
    // cout << "" << endl;
  }

  cout << ans;

  return 0;
}