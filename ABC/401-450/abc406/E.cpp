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

ll pows[65], fac[65], rev[65], nCr[65][65];

ll my_pow(ll a, ll n, ll mod) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a % mod, n / 2, mod);
  } else {
    return a * my_pow(a, n - 1, mod) % mod;
  }
}

void prepare() {
  pows[0] = 1;
  for (int i = 1; i <= 60; i++) {
    pows[i] = pows[i - 1] * 2;
  }

  fac[0] = 1;
  rev[0] = 1;
  for (ll i = 1; i <= 60; i++) {
    fac[i] = fac[i - 1] * i % MOD2;
    rev[i] = my_pow(fac[i], MOD2 - 2, MOD2);
  }

  for (int i = 0; i <= 60; i++) {
    for (int j = 0; j <= i; j++) {
      nCr[i][j] = fac[i] * rev[j] % MOD2;
      nCr[i][j] = nCr[i][j] * rev[i - j] % MOD2;
    }
  }

  return;
}

ll solve(ll num, int k) {
  ll rest = num, now = 0, ans = 0, cnt = 0;

  for (int i = 60; i >= 0; i--) {
    if (rest < pows[i]) {
      continue;
    }

    if (k - cnt - 1 >= 0 && i - 1 >= 0) {
      ans += (now % MOD2) * nCr[i][k - cnt] % MOD2;
      ans += ((pows[i] - 1) % MOD2) * nCr[i - 1][k - cnt - 1] % MOD2;
    }

    rest -= pows[i];
    now += pows[i];
    cnt++;

    ans %= MOD2;

    if (cnt >= k) {
      ans += now % MOD2;
      ans %= MOD2;
      break;
    }
  }

  return ans;
}

int main() {
  prepare();

  int t;
  cin >> t;

  while (t--) {
    ll n;
    int k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
  }

  return 0;
}
