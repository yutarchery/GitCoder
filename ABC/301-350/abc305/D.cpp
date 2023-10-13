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

int n, q;
ll a[int(2e5 + 5)], sum[int(2e5 + 5)];

int search(ll t) {
  int l = 1, r = n + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;

    if (a[mid] <= t) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return l;
}

ll solve(ll l, ll r) {
  int idx_l = search(l), idx_r = search(r);
  ll ans = sum[idx_r] - sum[idx_l];

  if (idx_l % 2 == 0) {
    ans -= l - a[idx_l];
  }
  if (idx_r % 2 == 0) {
    ans += r - a[idx_r];
  }
  return ans;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[n + 1] = ll(1e16);

  for (int i = 2; i <= n; i++) {
    if (i % 2 != 0) {
      sum[i] = sum[i - 1] + (a[i] - a[i - 1]);
    } else {
      sum[i] = sum[i - 1];
    }
  }

  cin >> q;
  for (int i = 0; i < q; i++) {
    ll l, r;
    cin >> l >> r;
    cout << solve(l, r) << endl;
  }

  return 0;
}