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
ll p[3005], ncr[3005][3005], coef[3005][3005];

ll my_pow(ll x, ll y) {
  if (y == 0) {
    return 1;
  }
  if (y % 2 == 0) {
    return my_pow(x * x % MOD2, y / 2);
  } else {
    return x * my_pow(x * x % MOD2, y / 2) % MOD2;
  }
}

ll frac(ll a, ll b) { return a * my_pow(b, MOD2 - 2) % MOD2; }

int main() {
  for (ll i = 0; i <= 3000; i++) {
    ncr[i][0] = 1;
    for (ll j = 1; j <= i; j++) {
      ncr[i][j] = frac(i - j + 1, j) * ncr[i][j - 1] % MOD2;
    }
  }

  for (ll i = 1; i <= 3000; i++) {
    ll exp = my_pow(frac(1, 2), i - 1);
    for (ll j = 0; j <= i - 1; j++) {
      coef[i][j] = (coef[i - 1][j] + ncr[i - 1][j] * exp) % MOD2;
    }
  }

  for (ll i = 1; i <= 3000; i++) {
    ll res = 1;
    for (ll j = 1; j <= i - 1; j++) {
      res -= (p[i - j] * coef[i][j]) % MOD2;
      if (res < 0) {
        res += MOD2;
      }
    }
    p[i] = frac(res, coef[i][0]);
  }

  cin >> n;
  for (ll i = 1; i <= n; i++) {
    ll ans = 0;
    ll exp = my_pow(frac(1, 2), i - 1);
    for (ll j = 0; j <= i - 1; j++) {
      ll now = (ncr[i - 1][j] * exp) % MOD2;
      now = (now * p[n - j]) % MOD2;
      ans = (ans + now) % MOD2;
    }

    cout << ans;
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
