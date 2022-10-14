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

#include <stdio.h>

#define N 200

// vector<vector<int>> data(3, vector<int>(4));

// 頂点
typedef struct vtex {
  double x, y;
  // 座標値
} VTEX;

// ２次元ベクトル
typedef struct vec2 {
  double x, y;
  // ベクトルのｘ、ｙ成分
} VEX2;

// 線分（辺）
typedef struct edge {
  VTEX s, e;
  // 始点、終点
} EDGE;

// 線分をベクトル形式に変換する
VEX2 vector_(EDGE ln) {
  VEX2 v;
  v.x = ln.e.x - ln.s.x;
  v.y = ln.e.y - ln.s.y;
  return v;
}

// ２次元ベクトルの外積を返す
double exterp(VEX2 vi, VEX2 vj) {
  double p;
  return p = vi.x * vj.y - vi.y * vj.x;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x[4];
  int y[4];

  int x_;
  int y_;
  rep(i, 4) {
    cin >> x_;
    cin >> y_;
    x[i] = x_;
    y[i] = y_;
  }

  int n = 4;
  // 多角形の頂点数
  EDGE ln[N] =  // 多角形の辺集合：
      {
          {{x[0], y[0]}, {x[1], y[1]}},
          // No.1 辺
          {{x[1], y[1]}, {x[2], y[2]}},
          // No.2 辺
          {{x[2], y[2]}, {x[3], y[3]}},
          // No.3 辺
          {{x[3], y[3]}, {x[0], y[0]}},
          // No.4 辺
      };
  int convex;
  // 凹多角形判定フラグ
  int i, j;
  // 辺要素インデクス
  VEX2 vi;
  // 辺ｉのベクトル
  VEX2 vj;
  // 辺ｊのベクトル

  convex = 0;
  for (j = 1; j < n; j++) {
    i = j - 1;
    vi = vector_(ln[i]);
    vj = vector_(ln[j]);
    convex = exterp(vi, vj) < 0;
    if (convex) break;
  }
  if (convex) {
    printf("Yes\n");

  } else {
    printf("No\n");
  }

  return 0;
}