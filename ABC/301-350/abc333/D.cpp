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

int n, dp[int(3e5 + 5)];
vector<int> graph[int(3e5 + 5)];

int dfs(int now_node, int before_node = -1) {
  dp[now_node] = 1;
  for (int next_node : graph[now_node]) {
    if (next_node == before_node) {
      continue;
    }
    dp[now_node] += dfs(next_node, now_node);
  }

  return dp[now_node];
}

int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int m = 0;
  for (int i : graph[1]) {
    m = max(m, dfs(i, 1));
  }
  cout << n - m << endl;

  return 0;
}
