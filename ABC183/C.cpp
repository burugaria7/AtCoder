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

long ans = 0;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<vector<long>> data(n, vector<long>(n));

  long time;
  rep(i, n) {
    rep(j, n) {
      cin >> time;
      data[i][j] = time;
    }
  }

  vector<int> nums;
  rep(i, n - 1) { nums.push_back(i + 1); }
  do {
    long time = 0;
    int ikkomae = 0;

    for (int value : nums) {
      cout << value << " ";
      time += data[ikkomae][value];
      ikkomae = value;
    }
    time += data[ikkomae][0];
    if (time == k) ans++;
    // cout << endl;

  } while (next_permutation(nums.begin(), nums.end()));

  cout << ans;

  return 0;
}