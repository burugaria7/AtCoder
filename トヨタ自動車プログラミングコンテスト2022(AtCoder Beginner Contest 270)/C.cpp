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

  ll n, x, y;
  cin >> n >> x >> y;

  x--;
  y--;

  // n個目の頂点の繋がってる頂点配列
  vector<vector<ll>> vec(n, vector<ll>());

  ll u, v;
  rep(i, n - 1) {
    cin >> u >> v;
    u--;
    v--;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }

  if (n == 1) {
    cout << y + 1;
    return 0;
  } else if (n == 2) {
    cout << x + 1 << " " << y + 1;
    return 0;
  }

  //次に訪れる頂点を入れるキュー
  queue<int> que;

  //経路を保存していくキュー
  // vector<vector<ll>> kero(n, vector<ll>());
  // kero[x].push_back(x);

  //どこから来たかを保存
  vector<ll> come(n, -1);

  //頂点ｎに訪れてなければ-1
  vector<ll> dist(n, -1);  // 全頂点を「未訪問」に初期化

  que.push(x);

  while (!que.empty()) {
    //キューの戦闘にある頂点に訪れる
    int ten = que.front();
    que.pop();
    for (ll nv : vec[ten]) {
      if (dist[nv] != -1) continue;  // すでに発見済みの頂点は探索しない

      come[nv] = ten;
      //今の頂点への経路に先の頂点を加える
      // vector<ll> tmp(kero[ten]);
      // tmp.push_back(nv);
      //先の頂点に経路を保存
      // kero[nv] = tmp;
      // kero[nv] = vector<ll>(tmp.size());
      // copy(tmp.begin(), tmp.end(), kero[nv].begin());
      // cout << nv << " ";

      if (nv == y) {
        // cout << "test";
        vector<ll> ans;
        ans.push_back(y);
        ll tmp = y;
        while (true) {
          ll from = come[tmp];
          ans.push_back(from);
          tmp = from;
          if (tmp == x) {
            std::reverse(ans.begin(), ans.end());
            for (auto at : ans) {
              cout << at + 1 << " ";
            }
            return 0;
          }
        }
      }

      dist[nv] = dist[ten] + 1;
      que.push(nv);
    }
  }

  return 0;
}