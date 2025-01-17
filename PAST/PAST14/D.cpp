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

ll h, a, b, c, d, ans = 1e16;

bool solve(ll num) {
  ll rest = h, cost = 0;

  for (int i = 0; i < num; i++) {
    cost += d;

    ll now_c = c;
    if (rest - c > 0) {
      now_c += (rest - c) / 2;
    }
    rest -= now_c;
  }

  if (rest <= 0) {
    ans = min(ans, cost);
    return true;
  }

  cost += b * ((rest - 1) / a + 1);
  ans = min(ans, cost);

  return false;
}

int main() {
  cin >> h >> a >> b >> c >> d;
  int now = 0;
  while (!solve(now)) {
    now++;
  }
  cout << ans << endl;

  return 0;
}
