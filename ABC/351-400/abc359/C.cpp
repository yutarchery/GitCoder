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

ll sx, sy, tx, ty, px, qx, ans;

int main() {
  cin >> sx >> sy;
  cin >> tx >> ty;

  if ((sx + sy) % 2 == 1) {
    sx--;
  }
  if ((tx + ty) % 2 == 1) {
    tx--;
  }

  ans = abs(sy - ty);
  px = sx - abs(sy - ty);
  qx = sx + abs(sy - ty);

  if (px <= tx && tx <= qx) {
    cout << ans << endl;
  } else {
    ans += min(abs(px - tx), abs(qx - tx)) / 2;
    cout << ans << endl;
  }

  return 0;
}
