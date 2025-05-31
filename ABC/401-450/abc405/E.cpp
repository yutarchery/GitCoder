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

ll my_pow(ll a, ll n, ll mod) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a % mod, n / 2, mod);
  } else {
    return a * my_pow(a, n - 1, mod) % mod;
  }
}

ll a, b, c, d;
ll fac[int(4e6 + 5)], rev[int(4e6 + 5)];
bool visited[int(4e6 + 5)];

ll calc_rev(int idx) {
  if (visited[idx]) {
    return rev[idx];
  } else {
    visited[idx] = true;
    return rev[idx] = my_pow(fac[idx], MOD2 - 2, MOD2);
  }
}

int main() {
  cin >> a >> b >> c >> d;

  fac[0] = 1;
  for (ll i = 1; i <= a + b + c + d; i++) {
    fac[i] = fac[i - 1] * i % MOD2;
  }

  ll ans = 0;
  for (ll i = 0; i <= c; i++) {
    ll now1 = fac[a + b + i] * calc_rev(b) % MOD2;
    now1 = now1 * calc_rev(a + i) % MOD2;

    ll now2 = fac[c + d - (i + 1)] * calc_rev(d - 1) % MOD2;
    now2 = now2 * calc_rev(c - i) % MOD2;

    ans += now1 * now2 % MOD2;
    ans %= MOD2;
  }
  cout << ans << endl;

  return 0;
}
