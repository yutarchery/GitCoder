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

ll n, num = 1;

void prepare(ll start) {
  while (start > 0) {
    start /= 10;
    num *= 10;
    num %= MOD2;
  }

  return;
}

ll solve() {
  ll ans = n % MOD2;

  ans *= my_pow(num - 1, MOD2 - 2);
  ans %= MOD2;

  ans *= my_pow(num, n) - 1;
  ans %= MOD2;

  return ans;
}

int main() {
  cin >> n;
  prepare(n);
  cout << solve() << endl;

  return 0;
}
