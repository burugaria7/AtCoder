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

  ll N;
  cin >> N;

  vector<bool> S;
  vector<int> otona;
  vector<int> kodomo;
  ll tmp;
  string str;
  cin >> str;

  ll oto = 0;
  ll kodo = 0;
  rep(i, N) {
    tmp = stoi(str.substr(i, 1));
    if (tmp == 0) {
      S.push_back(false);
      kodomo.push_back(i);
      oto++;
    } else {
      S.push_back(true);
      otona.push_back(i);
      kodo++;
    }
  }
  if (kodo == N || oto == N) {
    cout << N;
    return 0;
  }

  ll otona_max = -1;
  ll otona_min = INF;
  ll kodomo_min = INF;
  ll kodomo_max = -1;
  vector<ll> W;
  vector<ll> otona_W;
  vector<ll> kodomo_W;
  rep(i, N) {
    cin >> tmp;
    W.push_back(tmp);
    if (S[i]) {
      otona_min = min(otona_min, tmp);
      otona_max = max(otona_max, tmp);
      otona_W.push_back(tmp);
    } else {
      kodomo_min = min(kodomo_min, tmp);
      kodomo_max = max(kodomo_max, tmp);
      kodomo_W.push_back(tmp);
    }
  }
  // cout << otona_max << endl;
  ll center = otona_min + abs(kodomo_max - otona_min) / 2;
  cout << center << endl;
  sort(otona_W.begin(), otona_W.end());
  sort(kodomo_W.begin(), kodomo_W.end());
  auto it = lower_bound(kodomo_W.begin(), kodomo_W.end(), center);
  ll ans = 0;
  ll index = it - kodomo_W.begin();
  cout << index << endl;
  ans += index;
  it = lower_bound(otona_W.begin(), otona_W.end(), center);
  index = it - otona_W.begin();
  cout << oto - index << endl;
  ans += oto - index;

  // cout << otona_max << endl;
  center = otona_min + abs(kodomo_max - otona_min) / 2 + 1;
  cout << center << endl;
  sort(otona_W.begin(), otona_W.end());
  sort(kodomo_W.begin(), kodomo_W.end());
  it = lower_bound(kodomo_W.begin(), kodomo_W.end(), center);
  ll ans1 = 0;
  index = it - kodomo_W.begin();
  cout << index << endl;
  ans1 += index;
  it = lower_bound(otona_W.begin(), otona_W.end(), center);
  index = it - otona_W.begin();
  cout << oto - index << endl;
  ans1 += oto - index;

  // cout << otona_max << endl;
  center = otona_min + abs(kodomo_max - otona_min) / 2 - 1;
  cout << center << endl;
  sort(otona_W.begin(), otona_W.end());
  sort(kodomo_W.begin(), kodomo_W.end());
  it = lower_bound(kodomo_W.begin(), kodomo_W.end(), center);
  ll ans2 = 0;
  index = it - kodomo_W.begin();
  cout << index << endl;
  ans2 += index;
  it = lower_bound(otona_W.begin(), otona_W.end(), center);
  index = it - otona_W.begin();
  cout << oto - index << endl;
  ans2 += oto - index;

  ll ansss = min(ans, ans1);
  ansss = min(ansss, ans2);
  cout << ansss;

  return 0;
}