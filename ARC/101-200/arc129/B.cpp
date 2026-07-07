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

int n;
ll l[int(2e5 + 5)], r[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }

  ll max_l = l[1], min_r = r[1];
  for (int i = 1; i <= n; i++) {
    max_l = max(max_l, l[i]);
    min_r = min(min_r, r[i]);

    ll now = (max_l + min_r) / 2;
    ll ans = ll(2e9);
    for (ll k = -1; k <= 1; k++) {
      ans = min(ans, max(((now + k) - min_r), (max_l - (now + k))));
    }
    ans = max(ans, 0ll);
    cout << ans << '\n';
  }

  return 0;
}
