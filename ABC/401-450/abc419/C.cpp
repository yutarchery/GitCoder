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

int n;
ll r[int(2e5 + 5)], c[int(2e5 + 5)];

ll sum_r(ll r_now) {
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, abs(r[i] - r_now));
  }
  return ans;
}

ll sum_c(ll c_now) {
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, abs(c[i] - c_now));
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> r[i] >> c[i];
  }

  ll r_min = 0, r_max = 1e9;
  while (r_max - r_min > 2) {
    ll r1 = (r_min * 2 + r_max) / 3, r2 = (r_min + r_max * 2) / 3;
    if (sum_r(r1) >= sum_r(r2)) {
      r_min = r1;
    } else {
      r_max = r2;
    }
  }
  ll r_ans = 1e16;
  for (ll i = r_min; i <= r_max; i++) {
    r_ans = min(r_ans, sum_r(i));
  }

  ll c_min = 0, c_max = 1e9;
  while (c_max - c_min > 2) {
    ll c1 = (c_min * 2 + c_max) / 3, c2 = (c_min + c_max * 2) / 3;
    if (sum_c(c1) >= sum_c(c2)) {
      c_min = c1;
    } else {
      c_max = c2;
    }
  }
  ll c_ans = 1e16;
  for (ll i = c_min; i <= c_max; i++) {
    c_ans = min(c_ans, sum_c(i));
  }

  cout << max(r_ans, c_ans) << endl;

  return 0;
}
