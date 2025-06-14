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

ll n, m, a[int(2e5 + 5)];

set<ll> ans[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (ll i = 1; i <= n; i++) {
    cin >> a[i];

    if (a[i] >= n) {
      continue;
    }

    ll l = (a[i] >= 0) ? 0 : (-1 * a[i] - 1) / i + 1;
    l = min(l, m);

    for (ll j = l; j <= m; j++) {
      ll now = a[i] + i * j;
      if (now > n) {
        break;
      }
      if (now >= 0) {
        ans[j].insert(now);
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    for (ll j = 0; j <= n; j++) {
      if (ans[i].find(j) == ans[i].end()) {
        cout << j << endl;
        break;
      }
    }
  }

  return 0;
}
