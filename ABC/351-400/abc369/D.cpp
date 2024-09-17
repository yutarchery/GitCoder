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
ll a[int(2e5 + 5)], dp[int(2e5 + 5)][2];
bool visited[int(2e5 + 5)][2];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  visited[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      if (visited[i - 1][j]) {
        visited[i][j] = true;
        dp[i][j] = max(dp[i][j], dp[i - 1][j]);

        if (j % 2 == 0) {
          visited[i][(j + 1) % 2] = true;
          dp[i][(j + 1) % 2] = max(dp[i][(j + 1) % 2], dp[i - 1][j] + a[i]);
        } else {
          visited[i][(j + 1) % 2] = true;
          dp[i][(j + 1) % 2] = max(dp[i][(j + 1) % 2], dp[i - 1][j] + a[i] * 2);
        }
      }
    }
  }

  ll ans = 0;
  for (int j = 0; j < 2; j++) {
    if (visited[n][j]) {
      ans = max(ans, dp[n][j]);
    }
  }
  cout << ans << endl;

  return 0;
}
