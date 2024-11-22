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

ll n, m, x[int(2e5 + 5)], a[int(2e5 + 5)];
Pll p[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x[i];
  }
  ll sum = 0;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
    sum += a[i];
  }

  if (sum != n) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 1; i <= m; i++) {
    p[i] = {x[i], a[i]};
  }
  sort(p + 1, p + m + 1);

  ll r = n, ans = 0;
  for (int i = m; i >= 1; i--) {
    ll cnt = min(p[i].second, r - p[i].first + 1);

    ans += ((r - p[i].first) + (r - p[i].first - (cnt - 1))) * cnt / 2;
    r -= cnt;
  }

  if (r == 0) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
