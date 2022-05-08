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

  long long a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  long long kyori = max(a, b) - min(a, b);

  if (kyori == 0) {
    cout << "YES";
    return 0;
  }
  long long sa = v - w;
  if (v <= w) {
    cout << "NO";
    return 0;
  } else if (sa * t >= kyori) {
    cout << "YES";
    return 0;
  } else {
    cout << "NO";
  }

  return 0;
}