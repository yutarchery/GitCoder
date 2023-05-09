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
  }
  if (n % 2 == 0) {
    return my_pow(a * a % MOD2, n / 2);
  } else {
    return a * my_pow(a, n - 1) % MOD2;
  }
}

int n, m, k;
ll p, dp[1005][1005];

int main() {
  cin >> n >> m >> k;
  p = my_pow(m, MOD2 - 2);

  dp[0][0] = 1;
  for (int j = 1; j <= k; j++) {
    for (int i = 0; i < n; i++) {
      for (int cnt = 1; cnt <= m; cnt++) {
        int next = i + cnt;
        if (next > n) {
          next = n - (i + cnt - n);
        }

        dp[next][j] += dp[i][j - 1] * p;
        dp[next][j] %= MOD2;
      }
    }
  }

  ll ans = 0;
  for (int j = 0; j <= k; j++) {
    ans += dp[n][j];
    ans %= MOD2;
  }
  cout << ans << endl;

  return 0;
}