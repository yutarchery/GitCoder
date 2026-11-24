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

int n, q, t[int(2e5 + 5)];
ll a[int(2e5 + 5)], x[int(2e5 + 5)];
ll u[int(2e5 + 5)], v[int(2e5 + 5)], w[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> t[i];
  }

  u[0] = 0, v[0] = -1e18, w[0] = 1e18;
  for (int i = 1; i <= n; i++) {
    ll now_u, now_v, now_w;
    if (t[i] == 1) {
      now_u = a[i], now_v = -1e18, now_w = 1e18;
    } else if (t[i] == 2) {
      now_u = 0, now_v = a[i], now_w = 1e18;
    } else {
      now_u = 0, now_v = -1e18, now_w = a[i];
    }

    u[i] = u[i - 1] + now_u;
    v[i] = max(now_v, min(now_w, now_u + v[i - 1]));
    w[i] = min(now_w, now_u + w[i - 1]);
  }

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x[i];
    cout << max(v[n], min(w[n], u[n] + x[i])) << '\n';
  }

  return 0;
}
