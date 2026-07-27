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
    return (a * my_pow(a, n - 1)) % MOD2;
  }
}

int n;
ll a[int(5e5 + 5)], sum[int(5e5 + 5)];

ll cnt[int(5e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }

  for (int i = 1; i <= n; i++) {
    if (i <= n + 1 - i) {
      cnt[i] = (cnt[i - 1] + (sum[n + 1 - i] - sum[i - 1])) % MOD2;
    } else {
      cnt[i] = cnt[n - i + 1];
    }

    if (cnt[i] < 0) {
      cnt[i] += MOD2;
    }
  }

  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    ans += (cnt[i] * my_pow(i, MOD2 - 2)) % MOD2;
    ans %= MOD2;
  }
  cout << ans << '\n';

  return 0;
}
