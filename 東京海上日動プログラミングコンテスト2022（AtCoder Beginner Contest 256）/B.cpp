#include <string.h>

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

  int n;
  cin >> n;

  int tmp;
  int p = 0;

  int masu[4] = {0, 0, 0, 0};

  rep(i, n) {
    masu[0] = 1;
    cin >> tmp;
    if (tmp >= 4) {
      p += masu[0] + masu[1] + masu[2] + masu[3];
      masu[0] = 0;
      masu[1] = 0;
      masu[2] = 0;
      masu[3] = 0;
    } else if (tmp == 3) {
      p += masu[1] + masu[2] + masu[3];
      int old[4];
      old[0] = masu[0];
      old[1] = masu[1];
      old[2] = masu[2];
      old[3] = masu[3];
      masu[0] = 0;
      masu[1] = 0;
      masu[2] = 0;
      masu[3] = old[0];
    } else if (tmp == 2) {
      p += masu[2] + masu[3];
      int old[4];
      old[0] = masu[0];
      old[1] = masu[1];
      old[2] = masu[2];
      old[3] = masu[3];
      masu[0] = 0;
      masu[1] = 0;
      masu[2] = old[0];
      masu[3] = old[1];
    } else if (tmp == 1) {
      p += masu[3];
      int old[4];
      old[0] = masu[0];
      old[1] = masu[1];
      old[2] = masu[2];
      old[3] = masu[3];
      masu[0] = 0;
      masu[1] = old[0];
      masu[2] = old[1];
      masu[3] = old[2];
    }
    // cout << masu[0] << " " << masu[1] << " " << masu[2] << " " << masu[3]
    //      << endl;
    // cout << p << endl;
  }

  cout << p;

  return 0;
}