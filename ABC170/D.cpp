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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  long long n;
  cin >> n;
  vector<long long> vec;
  set<long long> set_;

  int tmp;
  rep(i, n) {
    cin >> tmp;
    if (set_.count(tmp)) {
    } else {
      vec.push_back(tmp);
      set_.insert(tmp);
    }
  }

  if (vec.size() == 1) {
    cout << "0";
    return 0;
  }

  sort(vec.begin(), vec.end());

  for (auto aa : vec) {
    cout << aa << endl;
  }
  cout << "" << endl;

  set<long long> set;

  long long ans = 0;
  for (long long i = 0; i < vec.size(); i++) {
    for (long long k = i + 1; k < vec.size(); k++) {
      // cout << k << ":" << vec[k] << "  " << i << ":" << vec[i] << endl;
      if (vec[k] % vec[i] == 0) {
        set.insert(k);
      }
    }
  }
  cout << vec.size() - set.size();

  return 0;
}