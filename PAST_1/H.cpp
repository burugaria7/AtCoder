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
set<int> zaikogire;
int minmin;
int min_;
int ans = 0;

void uru(int x, int a) {
  if (x % 2 == 0) {
    if (!zaikogire.count(x)) {
      if (cards[x / 2] > a) {
        cards[x / 2] -= a;
        ans += a;
        min_ = min(min_, cards[x / 2]);
      } else if (cards[x / 2] == a) {
        cards[x / 2] -= a;
        ans += a;
        zaikogire.insert(x);
      }
    }
  } else {
    if (!zaikogire.count(x)) {
      if (cards_[x / 2] > a) {
        cards_[x / 2] -= a;
        ans += a;
        min_ = min(min_, cards_[x / 2]);
      } else if (cards_[x / 2] == a) {
        cards[x / 2] -= a;
        ans += a;
        zaikogire.insert(x);
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
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

      cout << "1: " << ans << endl;

    } else if (buf == 2) {
      cin >> a;

      vector<int> vec = cards;
      sort(vec.begin(), vec.end());

      if (a <= vec[0]) {
        rep(i, n) {
          if (i % 2 == 0) {
            uru(i, a);
          }
        }
      }
      cout << "2: " << ans << endl;
    } else {
      cin >> a;
      if (zaikogire.empty() && min_ >= a) {
        rep(i, n) { uru(i, a); }
      }
      cout << "3: " << ans << endl;
      for (auto aa : cards) {
        cout << aa << ":";
      }
    }
  }

  cout << ans;

  return 0;
}