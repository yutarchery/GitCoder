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

ll c, d;

ll calc_digit(ll num) {
  ll res = 0;
  while (num > 0) {
    res++;
    num /= 10;
  }
  return res;
}

ll my_sqrt(ll num) {
  ll ok = 0, ng = 1e10;
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    if (mid * mid <= num) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

ll my_pow(ll a, ll b) {
  ll res = 1;
  for (int i = 1; i <= b; i++) {
    res *= a;
  }
  return res;
}

ll solve() {
  cin >> c >> d;
  ll m = calc_digit(c + 1), n = calc_digit(c + d);

  ll ans = 0;
  for (ll i = m; i <= n; i++) {
    ll now_min =
        max(c * my_pow(10, m) + c + 1, c * my_pow(10, i) + my_pow(10, i - 1));
    ll now_max =
        min(c * my_pow(10, i) + my_pow(10, i) - 1, c * my_pow(10, n) + c + d);

    ll x_min = my_sqrt(now_min), x_max = my_sqrt(now_max);
    while (x_min * x_min < now_min) {
      x_min++;
    }

    ans += max(0ll, x_max - x_min + 1);
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
