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
ll a[int(6e5 + 5)], dp[int(6e5 + 5)][2];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll ans = 1e16;
  for (int j = 0; j <= 1; j++) {
    if (j == 0) {
      dp[1][0] = 0;
      dp[1][1] = 1e16;
    } else {
      dp[1][0] = 1e16;
      dp[1][1] = a[1];
    }

    for (int i = 2; i <= n; i++) {
      dp[i][0] = dp[i - 1][1];
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + a[i];
    }

    if (j == 0) {
      ans = min(ans, dp[n][1]);
    } else {
      ans = min(ans, min(dp[n][0], dp[n][1]));
    }
  }
  cout << ans << endl;

  return 0;
}