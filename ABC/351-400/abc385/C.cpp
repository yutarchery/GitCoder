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

int n, h[3005], dp[3005][3005];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = max(1, dp[i][j]);
    }

    for (int j = 1; j < i; j++) {
      if (h[j] == h[i]) {
        dp[i][i - j] = max(dp[i][i - j], dp[j][i - j] + 1);
      }
    }

    for (int j = 1; j <= n; j++) {
      ans = max(ans, dp[i][j]);
    }
  }

  cout << ans << endl;

  return 0;
}
