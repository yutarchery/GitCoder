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
    return (a * my_pow(a, n - 1)) % MOD2;
  }
}

ll n, k, a[int(2e5 + 5)], fac[int(2e5 + 5)];

int main() {
  cin >> n >> k;
  fac[0] = 1;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];
    fac[i] = fac[i - 1] * i % MOD2;
  }
  sort(a + 1, a + n + 1);

  ll ans = 0;
  for (ll i = 1; n - i - k + 1 >= 0; i++) {
    ll sum = (a[n + 1 - i] - a[i]) * k % MOD2;
    if (sum < 0) {
      sum += MOD2;
    }

    sum = sum * fac[n - i] % MOD2;
    sum = sum * fac[n - k] % MOD2;
    sum = sum * my_pow(fac[n], MOD2 - 2) % MOD2;
    sum = sum * my_pow(fac[n - i - k + 1], MOD2 - 2) % MOD2;

    ans = (ans + sum) % MOD2;
  }

  cout << ans << endl;

  return 0;
}