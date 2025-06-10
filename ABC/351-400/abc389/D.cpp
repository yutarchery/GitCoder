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

int main() {
  ll r;
  cin >> r;

  ll ans = 0;
  for (ll y = r; y >= 0; y--) {
    if ((2 * y + 1) * (2 * y + 1) > 4 * r * r) {
      continue;
    }

    ll ok = 0, ng = 1e9;
    while (ng - ok > 1) {
      ll mid = (ok + ng) / 2;

      if ((2 * y + 1) * (2 * y + 1) + (2 * mid + 1) * (2 * mid + 1) <=
          4 * r * r) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    if (y == 0) {
      ans *= 2;
    }
    ans += 2 * ok + 1;
  }
  cout << ans << endl;

  return 0;
}
