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

int vector_finder(std::vector<string> vec, string str) {
  auto itr = std::find(vec.begin(), vec.end(), str);
  size_t index = std::distance(vec.begin(), itr);
  if (index != vec.size()) {  // 発見できたとき
    return 1;
  } else {  // 発見できなかったとき
    return 0;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  ll m = -1;
  int ans;
  string inp;
  ll point;
  vector<string> vec;
  std::map<std::string, int> map;

  rep(i, n) {
    cin >> inp;
    cin >> point;

    if (map[inp] == 0 && point > m) {
      m = point;
      ans = i;
    }

    map[inp] = 1;
  }

  cout << ans + 1;

  return 0;
}