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
ll r[int(2e5 + 5)], sum[int(2e5 + 5)];

int solve(ll x) {
  if (sum[n] <= x) {
    return n;
  }

  int l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (sum[mid] <= x) {
      l = mid;
    } else {
      r = mid;
    }
  }
  return l;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> r[i];
  }
  sort(r + 1, r + n + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + r[i];
  }

  for (int i = 1; i <= q; i++) {
    ll x;
    cin >> x;
    cout << solve(x) << endl;
  }

  return 0;
}
