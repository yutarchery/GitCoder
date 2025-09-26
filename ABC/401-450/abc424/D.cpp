#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int h, w, dp[10][(1 << 10)];
char s[10][10];

int calc_cost(int i, int before_idx, int next_idx) {
  bool is_black[10][2] = {};
  for (int j = 1; j <= w; j++) {
    if (before_idx % 2 == 1) {
      is_black[j][0] = true;
    }
    before_idx /= 2;
  }
  for (int j = 1; j <= w; j++) {
    if (next_idx % 2 == 1) {
      is_black[j][1] = true;
    }
    next_idx /= 2;
  }

  for (int j = 1; j <= w; j++) {
    if (is_black[j][0] && is_black[j + 1][0] && is_black[j][1] &&
        is_black[j + 1][1]) {
      return 1e9;
    }
  }

  int ans = 0;
  for (int j = 1; j <= w; j++) {
    if (s[i][j] == '.' && is_black[j][1]) {
      return 1e9;
    } else if (s[i][j] == '#' && !is_black[j][1]) {
      ans++;
    }
  }

  return ans;
}

int solve() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 0; i <= h; i++) {
    for (int j = 0; j < (1 << w); j++) {
      dp[i][j] = 1e9;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= h; i++) {
    for (int j = 0; j < (1 << w); j++) {
      for (int k = 0; k < (1 << w); k++) {
        dp[i][k] = min(dp[i][k], dp[i - 1][j] + calc_cost(i, j, k));
      }
    }
  }

  int ans = 1e9;
  for (int j = 0; j < (1 << w); j++) {
    ans = min(ans, dp[h][j]);
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
