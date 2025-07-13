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

ll n, ans;

int main() {
  cin >> n;
  ans = ((n % MOD2) * ((n - 1) % MOD2)) % MOD2;
  ans *= my_pow(2, MOD2 - 2, MOD2);
  ans %= MOD2;

  ll i = 1, k = n;
  while (k > 1) {
    i++;
    k = n / i;

    ll cnt = ((n / k) - (n / (k + 1))) * k % MOD2;
    ans -= cnt;
    ans %= MOD2;

    i = n / k;
  }

  if (ans < 0) {
    ans += MOD2;
  }
  cout << ans << endl;

  return 0;
}
