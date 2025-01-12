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
ll a[int(2e5 + 5)], sum[int(2e5 + 5)], x;

ll solve(ll num) {
  if (a[n] <= num) {
    return num * n - sum[n];
  } else if (num <= a[1]) {
    return sum[n] - num * n;
  }

  ll l = 0, r = n;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (a[mid] <= num) {
      l = mid;
    } else {
      r = mid;
    }
  }

  return (num * l - sum[l]) + ((sum[n] - sum[l]) - num * (n - l));
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a, a + n + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1] + a[i];
  }

  for (int i = 1; i <= q; i++) {
    cin >> x;
    cout << solve(x) << endl;
  }

  return 0;
}
