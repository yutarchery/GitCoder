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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n;
ll p[int(1e5 + 5)], u[int(1e5 + 5)];
ll dp[int(1e5 + 5)][100];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> u[i];
  }
  fill((ll *)dp, (ll *)(dp + n + 1), -1e18);
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 100; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);

      dp[i][(j + p[i]) % 100] =
          max(dp[i][(j + p[i]) % 100],
              dp[i - 1][j] + u[i] + ((j + p[i]) / 100) * 20 - p[i]);
    }
  }

  ll ans = 0;
  for (int j = 0; j < 100; j++) {
    ans = max(ans, dp[n][j]);
  }
  cout << ans << endl;

  return 0;
}