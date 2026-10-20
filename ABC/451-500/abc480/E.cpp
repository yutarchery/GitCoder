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

ll n, ans = 0;
const double border = 4e18;

bool judge(ll start, ll num, ll diff) {
  double now = 1;
  for (int i = 0; i < num; i++) {
    now *= double(start + i * diff);

    if (now > border) {
      return false;
    }
  }

  ll res = 1;
  for (int i = 0; i < num; i++) {
    res *= start + i * diff;
  }
  return res <= n;
}

void solve(ll start, ll num) {
  if (!judge(start, num, 1)) {
    return;
  }

  ll ok = 1, ng = 1e10;
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    if (judge(start, num, mid)) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  ans += ok;
  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;

  for (int i = 3; i <= 20; i++) {
    if (!judge(1, i, 1)) {
      break;
    }

    for (ll j = 1; j <= ll(1e8); j++) {
      if (!judge(j, i, 1)) {
        break;
      }

      solve(j, i);
    }
  }

  cout << ans << '\n';

  return 0;
}
