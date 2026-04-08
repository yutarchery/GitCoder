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

int n, m;
ll a[int(5e5 + 5)], b[int(5e5 + 5)];

ll sum_a[int(5e5 + 5)], total_a = 0;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];

    sum_a[i] = (sum_a[i - 1] + a[i]) % MOD2;
    total_a = (total_a + ll(i) * a[i]) % MOD2;
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  ll ans = 0;
  for (int j = 1; j <= m; j++) {
    ans += b[j] * total_a;
    ans %= MOD2;

    for (int k = 0; k <= n; k++) {
      int l = j * k, r = min(j * (k + 1) - 1, n);

      if (l > r) {
        break;
      }

      ll now = ll(j) * ll(k) % MOD2;
      now = (now * b[j]) % MOD2;
      now = (now * (sum_a[r] - sum_a[l - 1])) % MOD2;
      ans = (ans - now) % MOD2;

      if (ans < 0) {
        ans += MOD2;
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
