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

int n, a[105], b[105], p[105], q[105];
ll x;

ll min_cost(int idx, ll num) {
  ll cost = 1e16;
  for (ll i = 0; i <= b[idx]; i++) {
    ll rest = max(0ll, num - a[idx] * i);
    ll now = p[idx] * i;
    if (rest % b[idx] == 0) {
      now += rest / b[idx] * q[idx];
    } else {
      now += (rest / b[idx] + 1) * q[idx];
    }
    cost = min(cost, now);
  }

  for (ll i = 0; i <= a[idx]; i++) {
    ll rest = max(0ll, num - b[idx] * i);
    ll now = q[idx] * i;
    if (rest % a[idx] == 0) {
      now += (rest / a[idx]) * p[idx];
    } else {
      now += (rest / a[idx] + 1) * p[idx];
    }
    cost = min(now, cost);
  }

  return cost;
}

ll total_cost(ll num) {
  ll cost = 0;
  for (int i = 1; i <= n; i++) {
    cost += min_cost(i, num);
  }
  return cost;
}

int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> p[i] >> b[i] >> q[i];
  }

  ll l = 0, r = 1e9 + 5;
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (total_cost(mid) <= x) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << l << endl;

  return 0;
}
