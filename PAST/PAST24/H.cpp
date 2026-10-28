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

int n, q, l[int(3e5 + 5)], r[int(3e5 + 5)];
ll x[int(3e5 + 5)];

ll sum[int(3e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];

    if (x[i - 1] <= x[i]) {
      sum[i] = sum[i - 1] + x[i] * 4 - x[i - 1] * 2;
    } else {
      sum[i] = sum[i - 1] + x[i] * 2;
    }
  }

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> l[i] >> r[i];

    ll ans = sum[r[i]] - sum[l[i] - 1];
    ans += min(x[l[i] - 1], x[l[i]]) * 2;

    cout << ans << '\n';
  }

  return 0;
}
