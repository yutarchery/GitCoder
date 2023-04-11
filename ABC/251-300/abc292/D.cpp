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
int group[int(2e5 + 5)], edge_count[int(2e5 + 5)];
int node_total[int(2e5 + 5)], edge_total[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

int union_find(int node) {
  if (visited[node]) {
    return group[node];
  }

  visited[node] = true;
  int ans = node;
  for (int next : graph[node]) {
    if (next < node) {
      ans = min(ans, union_find(next));
    }
  }
  return group[node] = ans;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    group[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);

    edge_count[u]++;
    edge_count[v]++;
  }

  for (int i = 1; i <= n; i++) {
    union_find(i);
  }

  for (int i = 1; i <= n; i++) {
    int g = group[i];
    node_total[g]++;
    edge_total[g] += edge_count[i];
  }

  for (int i = 1; i <= n; i++) {
    if (node_total[i] * 2 != edge_total[i]) {
      No();
      return 0;
    }
  }

  Yes();
  return 0;
}