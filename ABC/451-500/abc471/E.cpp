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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

ll my_pow(ll a, ll n, ll mod = MOD2) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a % mod, n / 2) % mod;
  } else {
    return a * my_pow(a, n - 1, mod) % mod;
  }
}

int n, k;
ll a[int(2e5 + 5)], sum[int(2e5 + 5)];

ll fac[int(2e5 + 5)], rev[int(2e5 + 5)];

void prepare() {
  fac[0] = 1;
  for (ll i = 1; i <= n; i++) {
    fac[i] = fac[i - 1] * i % MOD2;
  }
  for (int i = 0; i <= n; i++) {
    rev[i] = my_pow(fac[i], MOD2 - 2);
  }

  return;
}

ll nCk(ll n, ll k) {
  if (n < 0 || k < 0) {
    return 0;
  }
  if (k == 0) {
    return 1;
  }

  ll res = fac[n] * rev[k] % MOD2;
  res *= rev[n - k];
  res %= MOD2;

  return res;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  prepare();

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= MOD2;
    sum[i] = (sum[i - 1] + a[i]) % MOD2;
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ll now = a[i] * nCk(n - 1, k - 1) % MOD2;
    now += (sum[n] - a[i]) * nCk(n - 2, k - 2) % MOD2;
    now %= MOD2;
    if (now < 0) {
      now += MOD2;
    }

    ans += now * a[i] % MOD2;
    ans %= MOD2;
  }
  cout << ans << '\n';

  return 0;
}
