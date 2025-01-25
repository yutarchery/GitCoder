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

int n, m;
bool visited[3005][3005][2];
ll a[3005], dp[3005][3005][2];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  visited[0][0][0] = true;
  visited[0][0][1] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (visited[i - 1][j][0]) {
        dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0] + a[i]);
        visited[i][j][0] = true;
      }

      if (visited[i - 1][j][1]) {
        dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][1] + a[i]);
        visited[i][j][0] = true;
      }

      if (j >= 1 && visited[i - 1][j - 1][0]) {
        dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0]);
        visited[i][j][1] = true;
      }
    }
  }

  ll ans = 0;
  for (int j = m; j <= n; j++) {
    if (visited[n][j][0]) {
      ans = max(ans, dp[n][j][0]);
    }
    if (visited[n][j][1]) {
      ans = max(ans, dp[n][j][1]);
    }
  }
  cout << ans << endl;

  return 0;
}
