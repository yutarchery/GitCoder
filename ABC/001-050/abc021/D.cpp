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
    return my_pow(a * a % MOD, n / 2);
  } else {
    return a * my_pow(a, n - 1) % MOD;
  }
}

int main() {
  ll n, k;
  cin >> n >> k;

  ll ans = 1;
  for (ll i = n; i <= n + k - 1; i++) {
    ans *= i;
    ans %= MOD;
  }
  for (ll i = 1; i <= k; i++) {
    ans *= my_pow(i, MOD - 2);
    ans %= MOD;
  }
  cout << ans << endl;

  return 0;
}