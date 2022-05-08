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

// vector<vector<int>> data(3, vector<int>(4));
void recursive_comb(int *indexes, int s, int rest,
                    std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

vector<int> vec;

int ans = 0;

int nn;

int main() {
  cin >> nn;

  int buf;
  rep(i, nn) {
    cin >> buf;
    vec.push_back(buf);
  }

  foreach_comb(nn, 3, [](int *indexes) {
    int a = vec[indexes[0]];
    int b = vec[indexes[1]];
    int c = vec[indexes[2]];
    if (a != b && b != c && c != a && a + b > c && b + c > a && c + a > b) {
      // cout << "A" << endl;
      ans++;
    }
    // std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] <<
    // std::endl;
  });

  cout << ans;
}