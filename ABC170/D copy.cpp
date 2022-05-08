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
bool IsPrime(int num) {
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;  // 偶数はあらかじめ除く

  double sqrtNum = sqrt(num);
  for (int i = 3; i <= sqrtNum; i += 2) {
    if (num % i == 0) {
      // 素数ではない
      return false;
    }
  }

  // 素数である
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  long long n;
  cin >> n;
  vector<long long> vec;
  vector<set<long long>> sett;
  set<long long> set_;

  int tmp;
  rep(i, n) {
    cin >> tmp;
    if (set_.count(tmp)) {
    } else {
      vec.push_back(tmp);
      set_.insert(tmp);
      // sett.push_back(enum_divisors(tmp));
    }
  }

  if (vec.size() == 1) {
    cout << "0";
    return 0;
  }

  sort(vec.begin(), vec.end(), greater<int>());

  cout << "" << endl;

  set<long long> set;

  long long ans = 0;
  for (long long i = 0; i < vec.size(); i++) {
    for (long long k = vec.size() - 1; k >= 0; k--) {
      cout << i << ":" << vec[i] << "  " << k << ":" << vec[k] << endl;
      if (IsPrime(vec[i])) {
        ans++;
        break;
      }
      if (i != k && vec[i] % vec[k] == 0) {
        ans++;
        break;
      }
    }
  }

  cout << vec.size() - ans;

  return 0;
}