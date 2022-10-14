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

int num[3][3];
int h[3], w[3];

bool check_h() {
  int h0 = num[0][0] + num[1][0] + num[2][0];
  int h1 = num[0][1] + num[1][1] + num[2][1];
  int h2 = num[0][2] + num[1][2] + num[2][2];
  if (h0 == h[0] && h1 == h[1] && h2 == h[2]) {
    return true;
  } else {
    return false;
  }
}
bool check_w() {
  int w0 = num[1][0] + num[1][1] + num[1][2];
  int w1 = num[2][0] + num[2][1] + num[2][2];
  int w2 = num[3][0] + num[3][2] + num[3][2];
  if (w0 == w[0] && w1 == w[1] && w2 == w[2]) {
    return true;
  } else {
    return false;
  }
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int tmp;
  rep(i, 3) {
    cin >> tmp;
    h[i] = tmp;
  }
  rep(i, 3) {
    cin >> tmp;
    w[i] = tmp;
  }

  int size = 9;
  int range_start = 0;
  int range_end = 9;

  //それぞれのhの制約をもとに数字を埋める
  //まずw_iのたてごとに決める
  rep(i,3){
    //まず num[0][i]を決める
    rep(k,10){
      num[0][i] = k;

      rep(kk.10){
        if()
      }

    }
  }



  return 0;
}