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

int n, q, a[int(2e5 + 5)], b[int(2e5 + 5)];
ll t[int(2e5 + 5)];

int next_node[int(2e5 + 5)][40];
ll dist[int(2e5 + 5)][40];

ll solve(ll rest, int idx) {
  if (rest == 0) {
    return 0;
  }

  for (int j = 39; j >= 0; j--) {
    ll now = (1ll << j);
    if (rest >= now) {
      return solve(rest - now, next_node[idx][j]) + dist[idx][j];
    }
  }

  return 0;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    next_node[i][0] = a[i];
    dist[i][0] = i;
  }

  for (int j = 1; j < 40; j++) {
    for (int i = 1; i <= n; i++) {
      int tmp = next_node[i][j - 1];
      next_node[i][j] = next_node[tmp][j - 1];
      dist[i][j] = dist[i][j - 1] + dist[tmp][j - 1];
    }
  }

  for (int i = 1; i <= q; i++) {
    cin >> t[i] >> b[i];
    cout << solve(t[i], b[i]) << '\n';
  }

  return 0;
}
