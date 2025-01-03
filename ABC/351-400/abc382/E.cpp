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

int n, x, p[5005];

double dp[5005][5005], ans[5005];

int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] += dp[i - 1][j - 1] * p[i] / 100;
      dp[i][j - 1] += dp[i - 1][j - 1] * (100 - p[i]) / 100;
    }
  }

  for (int i = 1; i <= x; i++) {
    double now = 1;
    for (int j = 1; j <= n && i - j >= 0; j++) {
      now += dp[n][j] * ans[i - j];
    }
    ans[i] = now / ((double)1 - dp[n][0]);
  }

  cout << fixed << setprecision(32) << ans[x] << endl;

  return 0;
}
