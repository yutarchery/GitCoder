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

int n, a[int(2e5 + 5)];
ll ans[int(2e5 + 5)], sum[int(2e5 + 5)];

ll solve(int idx) {
  if (idx == n) {
    return ans[idx] = 0;
  }

  ll now = (a[idx] + 1 + sum[idx + 1] - sum[idx + a[idx] + 1]) % MOD2;
  now = now * my_pow(a[idx], MOD2 - 2, MOD2) % MOD2;
  if (now < 0) {
    now += MOD2;
  }

  sum[idx] = (sum[idx + 1] + now) % MOD2;
  return ans[idx] = now;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 1; i--) {
    solve(i);
  }
  cout << ans[1] << endl;

  return 0;
}
