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

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (ll q = 1; q * q <= n; q++) {
    ll p_min = q, p_max = n / q;

    if (p_min > p_max) {
      continue;
    }

    if (q % 2 == 0) {
      ans += p_max / 2 - (p_min - 1) / 2;
    } else {
      ans += (p_max + 1) / 2 - p_min / 2;
    }

    ans %= MOD2;
  }

  cout << ans << '\n';

  return 0;
}
