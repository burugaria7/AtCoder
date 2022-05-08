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
typedef pair<int, int> P;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define FOR(i, a, b) for (int i = (a), i##_len = (b); i <= i##_len; ++i)
#define REV(i, a, b) for (int i = (a); i >= (b); --i)
#define CLR(a, b) memset((a), (b), sizeof(a))
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define INF 1001001001001001001ll
#define fcout cout << fixed << setprecision(12)

// vector<vector<int>> data(3, vector<int>(4));

string toStr(int num) {
  num--;
  switch (num) {
    case 0:
      return "a";
    case 1:
      return "b";
    case 2:
      return "c";
    case 3:
      return "d";
    case 4:
      return "e";
    case 5:
      return "f";
    case 6:
      return "g";
    case 7:
      return "h";
    case 8:
      return "i";
    case 9:
      return "j";
    case 10:
      return "k";
    case 11:
      return "l";
    case 12:
      return "m";
    case 13:
      return "n";
    case 14:
      return "o";
    case 15:
      return "p";
    case 16:
      return "q";
    case 17:
      return "r";
    case 18:
      return "s";
    case 19:
      return "t";
    case 20:
      return "u";
    case 21:
      return "v";
    case 22:
      return "w";
    case 23:
      return "x";
    case 24:
      return "y";
    case 25:
      return "z";

    default:
      return "";
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  if (n <= 26) {
    cout << toStr(n);
    return 0;
  } else if (n <= 702) {
    int a = (n - 1) / (double)26;
    int b = n - (a * 26);
    cout << toStr(a) << toStr(b);
    return 0;
  } else if (n <= 18278) {
    int a = (n - 2) / (double)(26 * 26);
    n -= a;
    int b = (n - 1) / (double)26;
    int c = n - (a * 26);
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << toStr(a) << toStr(b) << toStr(c);
    return 0;
  }
}