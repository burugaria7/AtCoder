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

  string str1, str2;
  cin >> str1 >> str2;
  vector<char> v1;
  vector<char> v2;

  typedef std::pair<char, int> pair;
  std::vector<pair> pair_vec1;
  std::vector<pair> pair_vec2;

  char mae = ' ';
  int ren = 0;
  for (char c : str1) {
    if (c == mae) {
      ren++;
      pair_vec1[pair_vec1.size() - 1].second += 1;
    } else {
      pair_vec1.push_back(pair(c, 1));
      ren = 0;
    }
    mae = c;
  }
  mae = ' ';
  ren = 0;
  for (char c : str2) {
    if (c == mae) {
      ren++;
      pair_vec2[pair_vec2.size() - 1].second += 1;
    } else {
      pair_vec2.push_back(pair(c, 1));
      ren = 0;
    }
    mae = c;
  }
  // for (auto a : pair_vec1) {
  //   cout << a.first << " " << a.second << endl;
  // }

  if (pair_vec1.size() == pair_vec2.size()) {
    rep(i, pair_vec1.size()) {
      if (pair_vec1[i].first == pair_vec2[i].first) {
      } else {
        cout << "No";
        return 0;
      }
      if (pair_vec1[i].second == pair_vec2[i].second) {
        continue;
      } else if ((pair_vec1[i].second >= 2 &&
                  pair_vec1[i].second <= pair_vec2[i].second)) {
        continue;
      } else {
        cout << "No";
        return 0;
      }
    }
  } else {
    cout << "No";
    return 0;
  }
  cout << "Yes";
  return 0;
}