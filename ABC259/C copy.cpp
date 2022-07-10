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

  bool renzoku = false;
  char mae = ' ';
  for (char c : str1) {
    if (renzoku && c == mae) {
      //文字を追加しない
    } else if (c == mae) {
      renzoku = true;
      v1.push_back(c);
    } else {
      v1.push_back(c);
      renzoku = false;
    }
    mae = c;
  }
  // for (char c : v1) {
  //   cout << c << endl;
  // }
  renzoku = false;
  mae = ' ';
  for (char c : str2) {
    if (renzoku && c == mae) {
      //文字を追加しない
    } else if (c == mae) {
      renzoku = true;
      v2.push_back(c);
    } else {
      v2.push_back(c);
      renzoku = false;
    }
    mae = c;
  }
  // for (auto a : v2) {
  //   cout << a << endl;
  // }

  bool equal =
      v1.size() == v2.size() && std::equal(v1.cbegin(), v1.cend(), v2.cbegin());

  if (equal) {
    cout << "Yes";
  } else {
    cout << "No";
  }

  return 0;
}