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

int n;
ll d[105], l[2], c[2], k[2], dp[105][1005];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  for (int i = 0; i < 2; i++) {
    cin >> l[i] >> c[i] >> k[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k[0]; j++) {
      dp[i][j] = ll(1e16);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k[0]; j++) {
      for (int jj = 0; jj <= j; jj++) {
        ll rest = max(0ll, d[i] - l[0] * (j - jj));
        ll next = (rest - 1) / l[1] + 1;
        if (rest == 0) {
          next = 0;
        }
        dp[i][j] = min(dp[i][j], dp[i - 1][jj] + next);
      }
    }
  }

  ll ans = 1e16;
  for (ll j = 0; j <= k[0]; j++) {
    if (dp[n][j] <= k[1]) {
      ans = min(ans, c[0] * j + c[1] * dp[n][j]);
    }
  }

  if (ans == 1e16) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
