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
ll dp[int(1e6 + 5)][15];

int main() {
  cin >> n;
  for (int j = 1; j <= 9; j++) {
    dp[1][j] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= 9; j++) {
      dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD2;
    }
  }

  ll ans = 0;
  for (int j = 1; j <= 9; j++) {
    ans += dp[n][j];
    ans %= MOD2;
  }
  cout << ans << endl;

  return 0;
}
