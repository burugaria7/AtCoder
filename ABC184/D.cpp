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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  double a, b, c;
  cin >> a >> b >> c;

  double ans;
  double kitai;
  double sousa = 0;

  int kazu[3];
  kazu[0] = a;
  kazu[1] = b;
  kazu[2] = c;

  double kaku[3];

  kaku[0] = a / a + b + c;
  kaku[1] = b / a + b + c;
  kaku[2] = c / a + b + c;
  while (kazu[0] < 100 && kazu[1] < 100 && kazu[2] < 100) {
    int hiku = rand() % 3 + 1;
    kazu[hiku]++;
    sousa++;
  }
  ans = sousa;

  vector<double> vec;
  vec.push_back(ans);
  rep(i, 10000000) {
    sousa = 0;
    kazu[0] = a;
    kazu[1] = b;
    kazu[2] = c;
    while (kazu[0] < 100 && kazu[1] < 100 && kazu[2] < 100) {
      int hiku = rand() % 3;
      kazu[hiku]++;
      sousa++;
    }
    vec.push_back(ans);
  }

  const double ave =
      std::accumulate(std::begin(vec), std::end(vec), 0.0) / std::size(vec);
  std::cout << ave << std::endl;

  return 0;
}