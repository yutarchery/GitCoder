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

int n;
ll x, y, a[int(2e5 + 5)];

ll solve(ll num) {
  if (num == a[1]) {
    return a[1];
  }

  if ((y * a[1] - x * num) % (y - x) != 0) {
    return -1;
  }

  ll q = (y * a[1] - x * num) / (y - x);
  ll p = num - q;

  if (p >= 0 && q >= 0) {
    return q;
  } else {
    return -1;
  }
}

int main() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (solve(a[i]) == -1) {
      cout << -1 << endl;
      return 0;
    } else {
      ans += solve(a[i]);
    }
  }
  cout << ans << endl;

  return 0;
}
