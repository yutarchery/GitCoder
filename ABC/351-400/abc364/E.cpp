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

int n, x, y, a[85], b[85], dp[85][85][int(1e4 + 5)];

int main() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= x; k++) {
        dp[i][j][k] = 1e9;
      }
    }
  }

  dp[0][0][0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k <= x; k++) {
        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);

        if (k + a[i] <= x && dp[i - 1][j][k] + b[i] <= y) {
          dp[i][j + 1][k + a[i]] =
              min(dp[i][j + 1][k + a[i]], dp[i - 1][j][k] + b[i]);
        }
      }
    }
  }

  for (int j = n; j >= 0; j--) {
    for (int k = 0; k <= x; k++) {
      if (dp[n][j][k] <= y) {
        cout << min(j + 1, n) << endl;
        return 0;
      }
    }
  }

  return 0;
}
