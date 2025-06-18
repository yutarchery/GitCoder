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

ll my_pow(ll a, ll n) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a % MOD2, n / 2);
  } else {
    return a * my_pow(a, n - 1) % MOD2;
  }
}

int n;
char s[1005];
ll dp[1005][1024][10];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (1 << 10); j++) {
      for (int k = 0; k < 10; k++) {
        if (s[i] - 'A' == k) {
          if ((j & (1 << k)) == 0) {
            if (j == 0) {
              dp[i][(1 << k)][k]++;
            } else {
              dp[i][j | (1 << k)][k] += dp[i - 1][j][k];
              dp[i][j | (1 << k)][k] %= MOD2;
            }
          } else {
            dp[i][j][k] += dp[i - 1][j][k] * 2;
          }
        } else {
          if ((j & (1 << (s[i] - 'A'))) == 0) {
            dp[i][j | (1 << (s[i] - 'A'))][s[i] - 'A'] += dp[i - 1][j][k];
            dp[i][j | (1 << (s[i] - 'A'))][s[i] - 'A'] %= MOD2;
            dp[i][j][k] += dp[i - 1][j][k];
          } else {
            dp[i][j][k] += dp[i - 1][j][k];
          }
        }

        dp[i][j][k] %= MOD2;
      }
    }
  }

  ll ans = 0;
  for (int j = 1; j < (1 << 10); j++) {
    for (int k = 0; k < 10; k++) {
      ans += dp[n][j][k];
      ans %= MOD2;
    }
  }
  cout << ans << endl;

  return 0;
}
