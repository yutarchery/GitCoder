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

int n, m, c;
ll x[5005], y, bonus[5005], dp[5005][5005];
bool visited[5005][5005];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> c >> y;
    bonus[c] = y;
  }

  visited[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (!visited[i - 1][j]) {
        continue;
      }

      visited[i][0] = true;
      dp[i][0] = max(dp[i][0], dp[i - 1][j]);

      visited[i][j + 1] = true;
      dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + x[i] + bonus[j + 1]);
    }
  }

  ll ans = 0;
  for (int j = 0; j <= n; j++) {
    ans = max(ans, dp[n][j]);
  }
  cout << ans << endl;

  return 0;
}