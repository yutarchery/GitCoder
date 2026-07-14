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

ll n;

ll solve() {
  cin >> n;

  ll ok = 1, ng = ll(1e9 + 5);
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    if (mid * mid <= n) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  ll ans = ok * (ok - 1) * 2;
  ll rest = n - ok * ok;

  if (0 < rest && rest <= ok) {
    ans += 2 * rest - 1;
  } else if (ok < rest) {
    ans += (2 * ok - 1) + (2 * (rest - ok) - 1);
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
