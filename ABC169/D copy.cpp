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
struct cww {
  cww() {
    ios::sync_with_stdio(false);
    cin.tie(0);
  }
} star;
// vector<vector<int>> data(3, vector<int>(4));

std::vector<int> Eratosthenes(const int N) {
  std::vector<bool> is_prime(N + 1);
  for (int i = 0; i <= N; i++) {
    is_prime[i] = true;
  }
  std::vector<int> P;
  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) {
      for (int j = 2 * i; j <= N; j += i) {
        is_prime[j] = false;
      }
      P.emplace_back(i);
    }
  }
  return P;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  long long n;
  cin >> n;

  long long n_ = n;

  long long z;

  long long ans = 0;

  set<long long> vec;

  if (n == 1) {
    cout << ans;

    return 0;
  }
  long long N = n;
  for (int i = 2; i < N; i++) {
    if (N % i == 0) {
      cout << "1";
      return 0;
    }
  }

  while (true) {
    for (const auto &x : Eratosthenes(n)) {
      // cout << x << " ";
      FOR(i, 1, INF) {
        z = pow(x, i);
        if (z > n) {
          break;
        } else if (vec.count(z) == 0 && n % z == 0) {
          n = n / z;
          ans++;
          vec.insert(z);
        }
      }

      if (x > n) {
        cout << ans;

        return 0;
      }
    }
  }
}