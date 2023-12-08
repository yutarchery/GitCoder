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

int n, k;
Pll s, t;
ll p[int(2e5 + 5)], q[int(2e5 + 5)], r[int(2e5 + 5)], w[int(2e5 + 5)];
ll cost[int(2e5 + 5)];

int main() {
  cin >> n >> k;
  cin >> s.first >> s.second >> t.first >> t.second;
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> q[i] >> r[i] >> w[i];
  }

  for (int i = 1; i <= n; i++) {
    ll s_value = p[i] * s.first + q[i] * s.second - r[i];
    ll t_value = p[i] * t.first + q[i] * t.second - r[i];

    if (s_value > 0 && t_value > 0) {
      cost[i] = 0;
    } else if (s_value < 0 && t_value < 0) {
      cost[i] = 0;
    } else {
      cost[i] = w[i];
    }
  }
  sort(cost + 1, cost + n + 1);

  ll ans = 0;
  for (int i = 1; i <= k; i++) {
    ans += cost[i];
  }
  cout << ans << endl;

  return 0;
}
