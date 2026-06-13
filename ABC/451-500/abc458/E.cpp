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

ll my_pow(ll a, ll n) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a % MOD2, n / 2);
  } else {
    return a * my_pow(a, n - 1) % MOD2;
  }
}

ll x1, x2, x3;
ll fac[int(3e6 + 5)], rev[int(3e6 + 5)];

void prepare() {
  fac[0] = 1;
  rev[0] = 1;
  for (int i = 1; i <= x1 + x2 + x3; i++) {
    fac[i] = fac[i - 1] * i % MOD2;
    rev[i] = my_pow(fac[i], MOD2 - 2);
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> x1 >> x2 >> x3;
  prepare();

  ll ans = 0;
  for (ll x = min(1ll, x1); x <= min(x1, x2); x++) {
    ll now = fac[x2 + 1];

    now = now * rev[x] % MOD2;
    now = now * rev[x2 + 1 - x] % MOD2;

    now = now * fac[x1 - 1] % MOD2;
    now = now * rev[x1 - x] % MOD2;
    now = now * rev[x - 1] % MOD2;

    now = now * fac[x2 + x3 - x] % MOD2;
    now = now * rev[x3] % MOD2;
    now = now * rev[x2 - x] % MOD2;

    ans = (ans + now) % MOD2;
  }
  cout << ans << '\n';

  return 0;
}
