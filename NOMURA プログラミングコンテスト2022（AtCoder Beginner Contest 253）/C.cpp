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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  map<ll, ll> mp;
  set<ll> st;
  ll q;
  cin >> q;

  ll inp;
  ll tmp;
  ll tmp2;
  rep(i, q) {
    cin >> inp;
    if (inp == 1) {
      cin >> tmp;
      st.insert(tmp);
      mp[tmp]++;
    } else if (inp == 2) {
      cin >> tmp >> tmp2;
      if (mp[tmp] <= tmp2) {
        mp[tmp] = 0;
        st.erase(tmp);
      } else {
        mp[tmp] -= tmp2;
      }
    } else {
      cout << *st.rbegin() - *st.begin() << "\n";
    }
  }

  return 0;
}