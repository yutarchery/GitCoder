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

ll n, a, b;

ll solve() {
  cin >> n >> a >> b;

  ll ok = 0, ng = ll(2e9);
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;

    ll rest = n - b * mid;
    if (rest < 0) {
      ng = mid;
      continue;
    }

    if (mid - 1 <= 0) {
      ok = mid;
      continue;
    }

    rest /= (mid * (mid - 1) / 2);
    if (a <= rest) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  return ok;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int q;
  cin >> q;
  while (q--) {
    cout << solve() << '\n';
  }

  return 0;
}
