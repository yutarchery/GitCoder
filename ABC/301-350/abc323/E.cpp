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

ll my_pow(ll a, ll b) {
  if (b == 0) {
    return 1;
  }
  if (b % 2 == 0) {
    return my_pow(a * a % MOD2, b / 2);
  } else {
    return a * my_pow(a, b - 1) % MOD2;
  }
}

ll frac(ll a, ll b) { return a * my_pow(b, MOD2 - 2) % MOD2; }

int n, x, t[1005];
ll dp[20005];

int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }

  dp[0] = 1;
  const ll f = frac(1, n);
  for (int i = 0; i <= x; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i + t[j]] += f * dp[i];
      dp[i + t[j]] %= MOD2;
    }
  }

  ll ans = 0;
  for (int i = 0; i <= x; i++) {
    if (i + t[1] > x) {
      ans += dp[i] * f;
      ans %= MOD2;
    }
  }
  cout << ans << endl;

  return 0;
}
