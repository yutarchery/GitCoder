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
  ll n;
  cin >> n;

  for (ll d = 1; d * d * d <= n; d++) {
    if (n % d != 0) {
      continue;
    }

    ll rest = n / d - d * d;
    if (rest % 3 != 0 || rest <= 0) {
      continue;
    }
    ll xy = rest / 3;

    ll ok = 0, ng = ll(2e9);
    while (ng - ok > 1) {
      ll mid = (ok + ng) / 2;

      if (mid * mid <= d * d + 4 * xy) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    if (ok * ok == d * d + 4 * xy) {
      if ((d + ok) % 2 == 0) {
        ll x = (d + ok) / 2, y = (ok - d) / 2;
        if (x > 0 && y > 0 && x * y == xy) {
          cout << x << " " << y << endl;
          return 0;
        }
      }
    }
  }
  cout << -1 << endl;

  return 0;
}
