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

  multimap<ll, ll> mp;

  ll n, m;
  cin >> n >> m;

  std::set<int> st;

  ll tmp1;
  ll tmp2;
  rep(i, m) {
    cin >> tmp1;
    cin >> tmp2;
    st.insert(tmp1);
    st.insert(tmp2);
    mp.insert(std::pair<ll, ll>(tmp1, tmp2));
    mp.insert(std::pair<ll, ll>(tmp2, tmp1));
  }

  typedef std::multimap<ll, ll>
      MCI;  // C++03 では型名を何度も書く必要があるので typedef しておく
  MCI mm;
  // for (auto a : st) {
  //   cout << mp.count(a) << " ";
  //   std::pair<MCI::iterator, MCI::iterator> p = mp.equal_range(a);
  //   for (MCI::iterator it = p.first; it != p.second; ++it) {
  //     std::cout << it->second;
  //   }
  //   cout << "\n";
  // }

  set<int> stt;
  rep(i, n) {
    cout << mp.count(i + 1);
    std::pair<MCI::iterator, MCI::iterator> p = mp.equal_range(i + 1);

    for (MCI::iterator it = p.first; it != p.second; ++it) {
      // std::cout << " " << it->second;
      stt.insert(it->second);
    }
    for (auto aaa : stt) {
      cout << " " << aaa;
    }
    stt.clear();
    cout << "\n";
  }

  // vector<ll> vec;
  // for (auto i = mp.begin(); i != mp.end(); ++i) {
  //   std::cout << i->first << " " << i->second << "\n";
  // }

  return 0;
}