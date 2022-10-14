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
ll findIndex2(const vector<ll> &arr, ll item) {
  auto ret = std::find(arr.begin(), arr.end(), item);

  if (ret != arr.end()) return ret - arr.begin();
  return -1;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, q;
  vector<ll> vec;
  cin >> n >> q;

  string str;
  cin >> str;
  rep(i, n) { vec.push_back(i); }

  ll inp1, inp2;
  rep(i, q) {
    cin >> inp1 >> inp2;

    // cout << inp1 << " " << inp2 << endl;

    if (inp1 == 1) {
      rep(k, n - inp2) { vec[k] += inp2; }
      ll tmp = 0;
      for (ll k = n - inp2; k < n; k++) {
        vec[k] = tmp;
        tmp++;
      }
      for (auto a : vec) {
        cout << a<<" ";
      }
      cout << "\n";
    } else {
      const int wanted =
          inp2 - 1;  // 2に対応するindex(この例では1)を取って来たい
      auto itr = std::find(vec.begin(), vec.end(), wanted);
      // cout << *itr << endl;
      const int wanted_index = std::distance(vec.begin(), itr);
      std::cout << str[wanted_index] << std::endl;
    }
  }

  return 0;
}