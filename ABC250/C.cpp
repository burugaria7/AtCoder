#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <iterator>
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

  int n, q;
  cin >> n >> q;

  vector<int> itr;
  itr.reserve(n);
  rep(i, n) { itr.push_back(i); }

  vector<int> v;
  v.reserve(n);
  rep(i, n) { v.push_back(i); }

  int in;
  rep(i, q) {
    cin >> in;
    in--;
    //入れ替える数字２つ取り出す
    int su1;
    int su2;
    if (itr[in] + 1 == n) {
      su1 = v[itr[in]];
      su2 = v[itr[in] - 1];
      std::iter_swap(v.begin() + itr[in], v.begin() + itr[in] - 1);
    } else {
      su1 = v[itr[in]];
      su2 = v[itr[in] + 1];
      std::iter_swap(v.begin() + itr[in], v.begin() + itr[in] + 1);
    }

    std::iter_swap(itr.begin() + su1, itr.begin() + su2);
  }

  for (auto i : v) {
    cout << i + 1 << " ";
  }

  return 0;
}