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

ll n, m, a[2005], dp[2005][2005];

int main() {
  cin >> n >> m;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    if (i <= m) {
      dp[i][i] = dp[i - 1][i - 1] + i * a[i];
    }

    for (int k = i + 1; k <= n; k++) {
      dp[k][i] = dp[k - 1][i];
    }
  }

  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= min(i - 1, m); j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
    }

    for (ll j = 1; j <= min(i, m); j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + j * a[i]);
    }
  }

  cout << dp[n][m] << endl;

  return 0;
}