#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <functional>
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

using ll = long long;
using P = pair<int, int>;
using namespace std;
using LL = long long;
using PII = pair<LL, LL>;
using VI = vector<LL>;
using VVI = vector<VI>;
using VB = vector<bool>;
using VS = vector<string>;
using VP = vector<PII>;
#define VV(T) vector<vector<T>>
#define PB push_back
#define MP make_pair
#define SZ(a) LL((a).size())
#define EACH(x, c) for (auto x : (c))
#define ALL(c) (c).begin(), (c).end()
#define REVERSE(c) reverse(ALL(c))
#define SORT(c) stable_sort(ALL(c))
#define RSORT(c) stable_sort((c).rbegin(), (c).rend())
#define FOR(i, a, b) for (LL i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define $(x) \
  { cout << #x << " = " << (x) << endl; }

#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

// vector<vector<int>> data(3, vector<int>(4));

template <class T>
void combination(const vector<T>& seed, int target_size,
                 bool (*callback)(const vector<T>&)) {
  vector<int> indices(target_size);
  const int seed_size = seed.size();
  int start_index = 0;
  int size = 0;

  while (size >= 0) {
    for (int i = start_index; i < seed_size; ++i) {
      indices[size++] = i;
      if (size == target_size) {
        vector<T> comb(target_size);
        for (int x = 0; x < target_size; ++x) {
          comb[x] = seed[indices[x]];
        }
        if (callback(comb)) return;
        break;
      }
    }
    --size;
    if (size < 0) break;
    start_index = indices[size] + 1;
  }
}

bool my_callback(const vector<int>& comb) {
  int n = comb.size();
  for (int i = 0; i < n; ++i) cout << comb[i] << " ";
  cout << endl;
  return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<int> vec;
  rep(i, m) { vec.push_back(i + 1); }

  combination(vec, n, my_callback);

  return 0;
}