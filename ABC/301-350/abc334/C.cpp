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

int n, k;
ll a[int(2e5 + 5)];
ll dp[int(2e5 + 5)];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
  }

  if (k % 2 == 0) {
    ll ans = 0;
    for (int i = 1; i <= k; i += 2) {
      ans += abs(a[i] - a[i + 1]);
    }
    cout << ans << endl;
    return 0;
  }

  for (int i = 2; i <= k; i += 2) {
    dp[1] += abs(a[i] - a[i + 1]);
  }

  ll ans = dp[1];
  for (int j = 2; j <= k; j++) {
    dp[j] = dp[j - 1];
    if (j % 2 == 0) {
      dp[j] -= abs(a[j] - a[j + 1]);
      dp[j] += abs(a[j - 1] - a[j + 1]);
    } else {
      dp[j] -= abs(a[j - 2] - a[j]);
      dp[j] += abs(a[j - 2] - a[j - 1]);
    }
    ans = min(ans, dp[j]);
  }
  cout << ans << endl;

  return 0;
}
