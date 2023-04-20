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

int n, k, a[105];
ll dp[105][int(1e5 + 5)], sum[105][int(1e5 + 5)];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dp[0][0] = 1;
  sum[0][0] = 1;
  for (int j = 1; j <= k; j++) {
    sum[0][j] = sum[0][j - 1] + dp[0][j];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (j - a[i] - 1 >= 0) {
        dp[i][j] = sum[i - 1][j] - sum[i - 1][j - a[i] - 1];
      } else {
        dp[i][j] = sum[i - 1][j];
      }
      dp[i][j] %= mod;
      if (dp[i][j] < 0) {
        dp[i][j] += mod;
      }
    }

    sum[i][0] = dp[i][0];
    for (int j = 1; j <= k; j++) {
      sum[i][j] = sum[i][j - 1] + dp[i][j];
      sum[i][j] %= mod;
    }
  }

  cout << dp[n][k] << endl;

  return 0;
}