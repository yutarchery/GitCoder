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
ll l, r, a[int(2e5 + 5)];

ll sum_l[int(2e5 + 5)], sum_r[int(2e5 + 5)];

int main() {
  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll now_l = 0;
  for (int i = 1; i <= n; i++) {
    now_l += l;
    sum_l[i] = min(now_l, sum_l[i - 1] + a[i]);
  }

  ll now_r = 0;
  for (int i = n; i >= 1; i--) {
    now_r += r;
    sum_r[i] = min(now_r, sum_r[i + 1] + a[i]);
  }

  ll ans = 1e16;
  for (int i = 0; i <= n; i++) {
    ans = min(ans, sum_l[i] + sum_r[i + 1]);
  }
  cout << ans << endl;

  return 0;
}
