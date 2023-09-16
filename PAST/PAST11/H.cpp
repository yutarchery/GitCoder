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

int n, a, b, w[105];
ll v[105], dp[105][305][305];
bool visited[105][305][305];

int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }

  visited[0][0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= a; j++) {
      for (int k = 0; k <= b; k++) {
        if (!visited[i - 1][j][k]) {
          continue;
        }

        visited[i][j][k] = true;
        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);

        if (j + w[i] <= a) {
          visited[i][j + w[i]][k] = true;
          dp[i][j + w[i]][k] = max(dp[i][j + w[i]][k], dp[i - 1][j][k] + v[i]);
        }

        if (k + w[i] <= b) {
          visited[i][j][k + w[i]] = true;
          dp[i][j][k + w[i]] = max(dp[i][j][k + w[i]], dp[i - 1][j][k] + v[i]);
        }
      }
    }
  }

  ll ans = 0;
  for (int j = 0; j <= a; j++) {
    for (int k = 0; k <= b; k++) {
      ans = max(ans, dp[n][j][k]);
    }
  }
  cout << ans << endl;

  return 0;
}