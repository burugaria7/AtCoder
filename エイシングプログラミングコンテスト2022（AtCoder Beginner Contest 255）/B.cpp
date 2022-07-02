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

double calculateDistance(ll x_1, ll x_2, ll y_1, ll y_2) {
  return sqrt(pow(x_1 - x_2, 2) + pow(y_1 - y_2, 2));
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  set<int> vec;

  ll tmp;
  rep(i, k) {
    cin >> tmp;
    vec.insert(tmp - 1);
  }

  vector<ll> ten_x;
  vector<ll> ten_y;
  vector<ll> right_x;
  vector<ll> right_y;

  ll x, y;
  rep(i, n) {
    cin >> x >> y;
    ten_x.push_back(x);
    ten_y.push_back(y);
    if (vec.count(i)) {
      right_x.push_back(x);
      right_y.push_back(y);
    }
  }

  // double max_dis = -1;

  // rep(i, right_x.size()) {
  //   rep(k, ten_x.size()) {
  //     double kyori =
  //         calculateDistance(right_x[i], ten_x[k], right_y[i], ten_y[k]);
  //     cout << kyori << endl;
  //     max_dis = fmax(max_dis, kyori);
  //   }
  // }

  double min_dis = INF;
  vector<double> min_;
  rep(k, ten_x.size()) {
    double min_dis = INF;
    rep(i, right_x.size()) {
      double kyori =
          calculateDistance(right_x[i], ten_x[k], right_y[i], ten_y[k]);
      min_dis = fmin(min_dis, kyori);
    }
    min_.push_back(min_dis);
  }

  double maxx = *max_element(min_.begin(), min_.end());

  printf("%12.12lf", maxx);

  return 0;
}