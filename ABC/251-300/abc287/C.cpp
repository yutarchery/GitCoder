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
vector<int> graph[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

void dfs(int node) {
  visited[node] = true;
  for (int next : graph[node]) {
    if (!visited[next]) {
      dfs(next);
    }
  }
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  dfs(1);

  for (int i = 1; i <= n; i++) {
    if (graph[i].size() > 2) {
      No();
      return 0;
    }

    if (!visited[i]) {
      No();
      return 0;
    }
  }

  if (m == n - 1) {
    Yes();
  } else {
    No();
  }

  return 0;
}