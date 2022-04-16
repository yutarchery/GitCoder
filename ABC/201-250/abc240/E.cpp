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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, idx = 1;
vector<int> graph[int(2e5 + 5)];

bool visited[int(2e5 + 5)];
int l[int(2e5 + 5)], r[int(2e5 + 5)], treeLevel[int(2e5 + 5)];

void dfs(int node) {
  visited[node] = true;

  bool child = true;
  for (int next : graph[node]) {
    if (!visited[next]) {
      child = false;
      treeLevel[next] = treeLevel[node] + 1;
      dfs(next);
    }
  }

  if (child) {
    l[node] = idx;
    r[node] = idx;
    idx++;
  }
}

int dfsMin(int node) {
  for (int next : graph[node]) {
    if (treeLevel[node] + 1 == treeLevel[next]) {
      l[node] = min(l[node], dfsMin(next));
    }
  }
  return l[node];
}

int dfsMax(int node) {
  for (int next : graph[node]) {
    if (treeLevel[node] + 1 == treeLevel[next]) {
      r[node] = max(r[node], dfsMax(next));
    }
  }
  return r[node];
}

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  fill(l + 1, l + n + 1, int(1e9));

  dfs(1);
  dfsMin(1);
  dfsMax(1);

  for (int i = 1; i <= n; i++) {
    cout << l[i] << " " << r[i] << endl;
  }

  return 0;
}