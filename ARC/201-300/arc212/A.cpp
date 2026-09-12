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

ll k;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> k;

  ll ans = 0;
  for (ll a = 2; a <= k - 4; a++) {
    for (ll b = 2; a + b <= k - 2; b++) {
      ll c = k - (a + b);

      ll now = (a - 1) * (b - 1) % MOD2;
      now = now * (c - 1) % MOD2;
      now = now * (k - max(a, max(b, c))) % MOD2;

      ans += now;
      ans %= MOD2;
    }
  }
  cout << ans << '\n';

  return 0;
}
