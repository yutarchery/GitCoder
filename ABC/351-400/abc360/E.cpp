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

ll my_frac(ll a, ll b) { return a * my_pow(b, MOD2 - 2) % MOD2; }

ll n, k, f1, f2;

ll p[2][int(1e5 + 5)];

int main() {
  cin >> n >> k;
  p[0][0] = 1;
  f1 = my_frac(2, n * n % MOD2);
  f2 = my_frac(n - 2, n);

  for (int j = 1; j <= k; j++) {
    for (int i = 0; i < 2; i++) {
      p[i][j] = (f1 + f2 * p[i][j - 1]) % MOD2;
      if (p[i][j] < 0) {
        p[i][j] += MOD2;
      }
    }
  }

  ll ans = ((n + 2) * (n - 1) / 2) % MOD2;
  ans = ans * p[1][k] % MOD2;
  ans = (ans + p[0][k]) % MOD2;
  cout << ans << endl;

  return 0;
}
