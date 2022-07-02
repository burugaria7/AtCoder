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

  int N, K, Q;
  cin >> N >> K >> Q;

  vector<int> A, L;
  vector<bool> MASU(N, 0);

  int tmp;
  rep(i, K) {
    cin >> tmp;
    MASU[tmp - 1] = true;
    A.push_back(tmp - 1);
  }
  rep(i, Q) {
    cin >> tmp;
    tmp--;
    if (A[tmp] == N - 1) {
      continue;
    } else if (!MASU[A[tmp] + 1]) {
      MASU[A[tmp] + 1] = true;
      MASU[A[tmp]] = false;
      A[tmp]++;
    }
  }

  rep(i, N) {
    if (MASU[i]) {
      cout << i + 1 << " ";
    }
  }

  return 0;
}