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

int n, q, l[int(2e5 + 5)];
ll x[int(2e5 + 5)];

ll a[int(2e5 + 5)];
ll s[int(2e5 + 5)], c[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> l[i] >> x[i];
  }

  for (int i = 1; i <= q; i++) {
    s[l[i]] += x[i];

    c[l[i]] = max(c[l[i]], s[l[i]] - s[l[i] + 1]);
    c[l[i] - 1] = max(c[l[i] - 1], s[l[i] - 1] - s[l[i]]);
  }

  a[1] = 1;
  ll ans = 1;
  for (int i = 1; i + 1 <= n; i++) {
    a[i + 1] = a[i] + c[i] + 1;
    ans += a[i + 1];
  }
  cout << ans << '\n';

  return 0;
}
