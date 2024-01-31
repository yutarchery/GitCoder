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
ll dist[25][25];
bool is_exist[25][25];

ll dp[(1 << 21)][25];
bool visited[(1 << 21)][25];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = 1e16;
    }
  }

  for (int i = 1; i <= m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    is_exist[u][v] = true;
    dist[u][v] = w;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {
        if (dist[i][k] == 1e16 || dist[k][j] == 1e16) {
          continue;
        }

        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] < 1e16) {
        is_exist[i][j] = true;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    dp[(1 << (i - 1))][i] = 0;
    visited[(1 << (i - 1))][i] = true;
  }

  for (int i = 1; i <= (1 << n) - 1; i++) {
    for (int j = 1; j <= n; j++) {
      if (!visited[i][j]) {
        continue;
      }

      for (int k = 1; k <= n; k++) {
        if (!is_exist[j][k]) {
          continue;
        }

        int next = i | (1 << (k - 1));

        if (visited[next][k]) {
          dp[next][k] = min(dp[next][k], dp[i][j] + dist[j][k]);
        } else {
          dp[next][k] = dp[i][j] + dist[j][k];
          visited[next][k] = true;
        }
      }
    }
  }

  ll ans = 1e16;
  for (int j = 1; j <= n; j++) {
    if (visited[(1 << n) - 1][j]) {
      ans = min(ans, dp[(1 << n) - 1][j]);
    }
  }

  if (ans == 1e16) {
    No();
  } else {
    cout << ans << endl;
  }

  return 0;
}
