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

ll n, q, a[int(3e5 + 5)], x, y;
ll ans[int(3e5 + 5)];
map<ll, bool> visited;

ll cnt(ll num) {
  if (a[n] <= num) {
    return num - n;
  }

  int ok = 0, ng = n + 1;
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if (a[mid] <= num) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  return num - ok;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a, a + n + 1);

  for (int i = 1; i <= q; i++) {
    cin >> x >> y;

    ll ng = 0, ok = ll(1e10);
    while (ok - ng > 1) {
      ll mid = (ok + ng) / 2;
      if (cnt(mid) - (cnt(x - 1)) < y) {
        ng = mid;
      } else {
        ok = mid;
      }
    }

    ans[i] = ok;
  }

  for (int i = 1; i <= q; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
