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

int n, q, p[5005], v[5005];
bool l[5005], r[5005];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> p[i] >> v[i];
  }

  fill(l + 1, l + q + 1, true);
  fill(r + 1, r + q + 1, true);

  ll ans = 1;
  for (int i = 1; i <= q; i++) {
    for (int j = i + 1; j <= q; j++) {
      if (v[i] <= v[j]) {
        continue;
      }

      if (p[i] < p[j]) {
        r[i] = false;
        l[j] = false;
      } else if (p[i] == p[j]) {
        ans = 0;
      } else {
        l[i] = false;
        r[j] = false;
      }
    }
  }

  for (int i = 1; i <= q; i++) {
    ll now = ll(l[i]) + ll(r[i]);
    ans *= now;
    ans %= MOD2;
  }

  cout << ans << '\n';

  return 0;
}
