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

int n, k, a[int(2e5 + 5)], b[int(2e5 + 5)];
bool dp[int(2e5 + 5)][2];

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  dp[1][0] = true;
  dp[1][1] = true;

  for (int i = 2; i <= n; i++) {
    if (dp[i - 1][0]) {
      if (abs(a[i - 1] - a[i]) <= k) {
        dp[i][0] = true;
      }
      if (abs(a[i - 1] - b[i]) <= k) {
        dp[i][1] = true;
      }
    }
    if (dp[i - 1][1]) {
      if (abs(b[i - 1] - a[i]) <= k) {
        dp[i][0] = true;
      }
      if (abs(b[i - 1] - b[i]) <= k) {
        dp[i][1] = true;
      }
    }
  }

  if (dp[n][0] || dp[n][1]) {
    Yes();
  } else {
    No();
  }

  return 0;
}
