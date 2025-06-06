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
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;

  if (abs(x1 - x2) >= 10 || abs(y1 - y2) >= 10) {
    No();
    return 0;
  }

  for (ll x = min(x1, x2) - 10; x <= max(x1, x2) + 10; x++) {
    for (ll y = min(y1, y2) - 10; y <= max(y1, y2) + 10; y++) {
      ll d1 = (x1 - x) * (x1 - x) + (y1 - y) * (y1 - y);
      ll d2 = (x2 - x) * (x2 - x) + (y2 - y) * (y2 - y);

      if (d1 == 5 && d2 == 5) {
        Yes();
        return 0;
      }
    }
  }

  No();

  return 0;
}
