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

ll a[6], p[6];

ll calc_cost(ll num_5) {
  ll rest = -2 * a[1] - 1 * a[2] + 1 * a[4] + 2 * (a[5] + num_5);
  ll num_4 = max(-1 * rest, 0ll);
  return p[4] * num_4 + p[5] * num_5;
}

ll solve() {
  for (int i = 1; i <= 5; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= 5; i++) {
    cin >> p[i];
  }

  ll num5_min = 0, num5_max = ll(1e9);
  while (num5_max - num5_min > 2) {
    ll n5_1 = (num5_min * 2 + num5_max) / 3,
       n5_2 = (num5_min + num5_max * 2) / 3;

    ll c1 = calc_cost(n5_1), c2 = calc_cost(n5_2);
    if (c1 <= c2) {
      num5_max = n5_2;
    } else {
      num5_min = n5_1;
    }
  }

  ll ans = 1e18;
  for (ll i = num5_min; i <= num5_max; i++) {
    ans = min(ans, calc_cost(i));
  }
  return ans;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}
