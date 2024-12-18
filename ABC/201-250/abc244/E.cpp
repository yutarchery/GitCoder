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

int n, m, k, s, t, x, u, v;
vector<int> graph[2005];

ll dp[2005][2005][2];

int main() {
  cin >> n >> m >> k >> s >> t >> x;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dp[0][s][0] = 1;

  for (int i = 1; i <= k; i++) {
    for (int j = 1; j <= n; j++) {
      for (int next : graph[j]) {
        if (next == x) {
          dp[i][next][0] += dp[i - 1][j][1];
          dp[i][next][1] += dp[i - 1][j][0];
        } else {
          dp[i][next][0] += dp[i - 1][j][0];
          dp[i][next][1] += dp[i - 1][j][1];
        }

        dp[i][next][0] %= MOD2;
        dp[i][next][1] %= MOD2;
      }
    }
  }

  cout << dp[k][t][0] << endl;

  return 0;
}
