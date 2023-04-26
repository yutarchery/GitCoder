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

ll my_pow(ll a, ll n, ll m) {
  if (n == 0) {
    return 1 % m;
  }
  if (n % 2 == 0) {
    return my_pow(a * a % m, n / 2, m);
  } else {
    return a * my_pow(a, n - 1, m) % m;
  }
}

ll solve(ll a, ll x, ll m) {
  if (x == 0) {
    return 1 % m;
  }

  if (x % 2 != 0) {
    ll ans = 1 + my_pow(a, (x + 1) / 2, m);
    return solve(a, (x - 1) / 2, m) * ans % m;
  } else {
    return (my_pow(a, x, m) + solve(a, x - 1, m)) % m;
  }
}

int main() {
  ll a, x, m;
  cin >> a >> x >> m;

  cout << solve(a, x - 1, m) << endl;
  return 0;
}