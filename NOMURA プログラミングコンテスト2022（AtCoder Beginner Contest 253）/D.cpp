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

int gcd(unsigned long long a, unsigned long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int lcm(unsigned long long a, unsigned long long b) {
  return a * b / gcd(a, b);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  unsigned long long n, a, b;
  cin >> n >> a >> b;

  unsigned long long aa = n / a;
  unsigned long long bb = n / b;
  unsigned long long cc = 0;
  unsigned long long c = lcm(a, b);
  unsigned long long aaa = a * b;
  if (n >= aaa) {
    cc = n / c;
  }

  unsigned long long kou1 = (2 * n + n * (n - 1)) / 2;
  unsigned long long kou2 = aa * (2 * a + (aa - 1) * a) / 2;
  unsigned long long kou3 = bb * (2 * b + (bb - 1) * b) / 2;
  unsigned long long kou4 = cc * (2 * c + (cc - 1) * c) / 2;
  unsigned long long kou5 = aaa % c;
  unsigned long long kou6 = kou5 * (2 * c + (kou5 - 1) * c) / 2;

  printf("%llu", (kou1 - kou2 - kou3 + kou4 + kou6));

  return 0;
}