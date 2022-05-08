#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <functional>
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

int k_ = 2;

// vector<vector<int>> data(3, vector<int>(4));

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string str;
  cin >> str;

  for (size_t c = str.find_first_of("3"); c != string::npos;
       c = c = str.find_first_of("3")) {
    str.erase(c, 1);
  }
  for (size_t c = str.find_first_of("6"); c != string::npos;
       c = c = str.find_first_of("6")) {
    str.erase(c, 1);
  }
  for (size_t c = str.find_first_of("9"); c != string::npos;
       c = c = str.find_first_of("9")) {
    str.erase(c, 1);
  }

  int n = stoi(str);
  vector<int> vec;
  int sum = 0;
  for (int i = 0; i <= 5; i++) {
    sum += n % 10;
    vec.push_back(n % 10);
    n /= 10;
  }

  cout << str;
  vector<int> hai;
  // k個選ぶ

  int n = vec.size() - 1;

  // {0, 1, ..., n-1} の部分集合の全探索
  for (int bit = 0; bit < (1 << n); ++bit) {
    int sum_ = 0;

    vector<int> S;
    for (int i = 0; i < n; ++i) {
      if (bit & (1 << i)) {  // 列挙に i が含まれるか
        S.push_back(i);
      }
    }

    cout << bit << ": {";
    for (int i = 0; i < (int)S.size(); ++i) {
      cout << S[i] << " ";
      sum += vec[S[i]];
    }
    if (sum % 3 == 0) {
      for (int i = 0; i < (int)S.size(); ++i) {
        vec.erase(vec.begin() + S[i]);
        n--;
      }
    }
    cout << "}" << endl;
  }

  cout << vec.size();

  return 0;
}