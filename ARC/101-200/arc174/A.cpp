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
ll c, a[int(3e5 + 5)];
ll sum[int(3e5 + 5)];

int main() {
  cin >> n >> c;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }

  ll sum_min = 0, sum_max = 0, val_min = 0, val_max = 0;
  for (int i = 1; i <= n; i++) {
    val_min = min(sum[i] - sum_max, val_min);
    val_max = max(sum[i] - sum_min, val_max);

    sum_min = min(sum[i], sum_min);
    sum_max = max(sum[i], sum_max);
  }

  ll ans = sum[n];
  if (c <= 0) {
    ans -= val_min;
    ans += val_min * c;
  } else {
    ans -= val_max;
    ans += val_max * c;
  }
  cout << ans << endl;

  return 0;
}
