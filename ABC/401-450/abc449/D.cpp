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

ll l, r, d, u;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> l >> r >> d >> u;

  ll ans = 0;
  if (l <= 0 && 0 <= r && d <= 0 && 0 <= u) {
    ans++;
  }

  for (ll i = 2; i <= ll(1e6); i += 2) {
    if (l <= -1 * i && -1 * i <= r) {
      ans += max(0ll, min(i, u) - max(-1 * i, d) + 1);
    }
    if (l <= i && i <= r) {
      ans += max(0ll, min(i, u) - max(-1 * i, d) + 1);
    }
    if (d <= -1 * i && -1 * i <= u) {
      ans += max(0ll, min(i, r) - max(-1 * i, l) + 1);
    }
    if (d <= i && i <= u) {
      ans += max(0ll, min(i, r) - max(-1 * i, l) + 1);
    }

    for (int j = -1; j <= 1; j += 2) {
      for (int k = -1; k <= 1; k += 2) {
        if (l <= j * i && j * i <= r && d <= k * i && k * i <= u) {
          ans--;
        }
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
