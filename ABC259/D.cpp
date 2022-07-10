#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
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

class SegmentMap : public std::map<signed, signed> {
 private:
  bool flagToMergeAdjacentSegment;

 public:
  // if merge [l, c] and [c+1, r], set flagToMergeAdjacentSegment to true
  SegmentMap(bool flagToMergeAdjacentSegment)
      : flagToMergeAdjacentSegment(flagToMergeAdjacentSegment) {}
  // __exist -> iterator pair(l, r) (contain p)
  // noexist -> map.end()
  auto get(signed p) const {
    auto it = upper_bound(p);
    if (it == begin() || (--it)->second < p) return end();
    return it;
  }
  // insert segment [l, r]
  void insert(signed l, signed r) {
    auto itl = upper_bound(l),
         itr = upper_bound(r + flagToMergeAdjacentSegment);
    if (itl != begin()) {
      if ((--itl)->second < l - flagToMergeAdjacentSegment) ++itl;
    }
    if (itl != itr) {
      l = std::min(l, itl->first);
      r = std::max(r, std::prev(itr)->second);
      erase(itl, itr);
    }
    (*this)[l] = r;
  }
  // remove segment [l, r]
  void remove(signed l, signed r) {
    auto itl = upper_bound(l), itr = upper_bound(r);
    if (itl != begin()) {
      if ((--itl)->second < l) ++itl;
    }
    if (itl == itr) return;
    int tl = std::min(l, itl->first), tr = std::max(r, std::prev(itr)->second);
    erase(itl, itr);
    if (tl < l) (*this)[tl] = l - 1;
    if (r < tr) (*this)[r + 1] = tr;
  }
  // Is p and q in same segment?
  bool same(signed p, signed q) const {
    const auto&& it = get(p);
    return it != end() && it->first <= q && q <= it->second;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  SegmentMap map2(true);
  SegmentMap map1(true);

  int n;
  cin >> n;

  ll s1, s2, t1, t2;
  cin >> s1 >> s2 >> t1 >> t2;

  map1.insert(min(s1, t1), max(s1, t1));
  map2.insert(min(s2, t2), max(s2, t2));

  ll x, y, r;
  rep(i, n) {
    cin >> x >> y >> r;
    map1.remove(x - r, x + r);
    map2.remove(y - r, y + r);
  }

  return 0;
}