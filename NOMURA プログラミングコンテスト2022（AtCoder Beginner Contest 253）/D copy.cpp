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

  unsigned long long n, a, b;
  cin >> n >> a >> b;

  unsigned long long aa = n / a;
  unsigned long long bb = n / b;

  set<ll> st;
  for (ll l; l < n; l++) {
    st.insert(l + 1);
  }
  set<ll> st1;
  for (ll l; l < aa; l++) {
    st1.insert((l + 1) * a);
  }
  set<ll> st2;
  for (ll l; l < bb; l++) {
    st2.insert((l + 1) * b);
  }

  std::multiset<unsigned long long> result;

  // a - bの差集合を作る
  std::set_difference(st.begin(), st.end(), st1.begin(), st1.end(),
                      std::inserter(result, result.end()));

  std::multiset<unsigned long long> result1;

  // a - bの差集合を作る
  std::set_difference(result.begin(), result.end(), st2.begin(), st2.end(),
                      std::inserter(result1, result1.end()));

  unsigned long long sum = std::accumulate(result1.begin(), result1.end(), 0);

  printf("%llu", sum);

  return 0;
}