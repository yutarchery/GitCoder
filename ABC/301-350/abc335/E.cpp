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

int n, m, a[int(2e5 + 5)];
Pii edge[int(2e5 + 5)];
vector<int> graph[int(2e5 + 5)];

int group[int(2e5 + 5)];
int edge_count[int(2e5 + 5)];
int dp[int(2e5 + 5)];

int find_group(int u) {
  if (group[u] == u) {
    return u;
  } else {
    return find_group(group[u]);
  }
}

void unite(int u, int v) {
  int gu = find_group(u), gv = find_group(v);
  if (gu > gv) {
    swap(gu, gv);
  }

  group[gv] = gu;
  group[u] = gu;
  group[v] = gu;
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    group[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    edge[i] = {u, v};
    if (a[u] == a[v]) {
      unite(u, v);
    }
  }

  for (int i = 1; i <= n; i++) {
    group[i] = find_group(i);
  }

  for (int i = 1; i <= m; i++) {
    int u = edge[i].first, v = edge[i].second;
    if (group[u] == group[v]) {
      continue;
    }

    if (a[group[u]] > a[group[v]]) {
      swap(u, v);
    }

    graph[group[u]].push_back(group[v]);
    edge_count[group[v]]++;
  }

  queue<int> que;
  for (int i = 2; i <= n; i++) {
    if (i == group[i] && edge_count[i] == 0) {
      que.push(i);
    }
  }
  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int next : graph[now]) {
      edge_count[next]--;
      if (edge_count[next] == 0 && next != 1) {
        que.push(next);
      }
    }
  }

  dp[1] = 1;
  que.push(1);
  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (int next : graph[now]) {
      edge_count[next]--;
      dp[next] = max(dp[next], dp[now] + 1);

      if (edge_count[next] == 0) {
        que.push(next);
      }
    }
  }

  cout << dp[group[n]] << endl;

  return 0;
}
