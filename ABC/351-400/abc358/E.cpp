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

int k, c[30];
ll fac[1005], rev[1005];

ll dp[30][1005];

int main() {
  cin >> k;
  for (int i = 1; i <= 26; i++) {
    cin >> c[i];
  }

  fac[0] = 1;
  rev[0] = 1;
  for (ll i = 1; i <= k; i++) {
    fac[i] = fac[i - 1] * i % MOD2;
    rev[i] = my_pow(fac[i], MOD2 - 2);
  }

  dp[0][0] = 1;
  for (int idx = 1; idx <= 26; idx++) {
    for (int i = 0; i <= k; i++) {
      for (int j = 0; i + j <= k && j <= c[idx]; j++) {
        ll now = fac[i + j] * dp[idx - 1][i] % MOD2;
        now = now * rev[i] % MOD2;
        now = now * rev[j] % MOD2;

        dp[idx][i + j] += now;
        dp[idx][i + j] %= MOD2;
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= k; i++) {
    ans += dp[26][i];
    ans %= MOD2;
  }
  cout << ans << endl;

  return 0;
}
