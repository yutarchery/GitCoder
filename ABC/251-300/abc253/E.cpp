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

int n, m, k;
ll dp[1005][5005], sum[1005][5005];

int main() {
  cin >> n >> m >> k;
  for (int j = 1; j <= m; j++) {
    dp[1][j] = 1;
  }
  for (int j = 1; j <= m; j++) {
    sum[1][j] = (sum[1][j - 1] + dp[1][j]) % MOD2;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (k > 0) {
        if (j - k >= 1) {
          dp[i][j] += sum[i - 1][j - k];
          dp[i][j] %= MOD2;
        }

        if (j + k <= m) {
          dp[i][j] += sum[i - 1][m] - sum[i - 1][j + k - 1];
          dp[i][j] %= MOD2;
          if (dp[i][j] < 0) {
            dp[i][j] += MOD2;
          }
        }
      } else {
        dp[i][j] += sum[i - 1][m];
        dp[i][j] %= MOD2;
      }
    }

    for (int j = 1; j <= m; j++) {
      sum[i][j] = (sum[i][j - 1] + dp[i][j]) % MOD2;
    }
  }

  ll ans = 0;
  for (int j = 1; j <= m; j++) {
    ans += dp[n][j];
    ans %= MOD2;
  }
  cout << ans << endl;

  return 0;
}
