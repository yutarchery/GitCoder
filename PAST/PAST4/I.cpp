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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n;
ll a[int(4e5 + 5)], sum[int(4e5 + 5)];
ll ans = 1e18;

int solve(int idx) {
  int l = idx - n, r = idx;
  while (r - l > 1) {
    int mid = (l + r) / 2;

    if (sum[idx] - sum[mid] >= sum[n] / 2) {
      l = mid;
    } else {
      r = mid;
    }
  }

  ll value = sum[idx] - sum[l];
  ll rest = sum[n] - value;

  ans = min(ans, abs(value - rest));

  return 0;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[n + i] = a[i];
  }

  for (int i = 1; i <= 2 * n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }

  for (int i = n + 1; i <= 2 * n; i++) {
    solve(i);
  }
  cout << ans << endl;

  return 0;
}