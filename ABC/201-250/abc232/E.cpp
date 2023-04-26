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

ll dp[int(1e6 + 5)][4];

int main() {
  ll h, w, i1, j1, i2, j2;
  int k;
  cin >> h >> w >> k;
  cin >> i1 >> j1 >> i2 >> j2;

  if (i1 == i2 && j1 == j2) {
    dp[0][3] = 1;
  } else if (j1 == j2) {
    dp[0][1] = 1;
  } else if (i1 == i2) {
    dp[0][2] = 1;
  } else {
    dp[0][0] = 1;
  }

  for (int i = 1; i <= k; i++) {
    dp[i][0] = dp[i - 1][0] * (h + w - 4) % MOD2 +
               dp[i - 1][1] * (w - 1) % MOD2 + dp[i - 1][2] * (h - 1) % MOD2;
    dp[i][1] = dp[i - 1][0] + dp[i - 1][1] * (h - 2) % MOD2 +
               dp[i - 1][3] * (h - 1) % MOD2;
    dp[i][2] = dp[i - 1][0] + dp[i - 1][2] * (w - 2) % MOD2 +
               dp[i - 1][3] * (w - 1) % MOD2;
    dp[i][3] = dp[i - 1][1] + dp[i - 1][2];

    for (int j = 0; j < 4; j++) {
      dp[i][j] %= MOD2;
    }
  }

  cout << dp[k][3] << endl;

  return 0;
}