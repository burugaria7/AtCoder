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

  while (sum % 3 != 0) {
    sum--;
    if (sum < 0) break;
  }

  for (int i = sum; i >= 3; sum -= 3) {
  }

  cout << str;

  return 0;
}