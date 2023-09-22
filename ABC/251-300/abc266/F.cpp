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

int n, m, parent[int(2e5 + 5)];
vector<int> graph[int(2e5 + 5)];

int loop_start, loop_goal;
bool visited[int(2e5 + 5)];
vector<int> loop;

int find_parent(int node) {
  if (parent[node] == node) {
    return node;
  }
  return parent[node] = find_parent(parent[node]);
}

void loop_search() {
  fill(visited, visited + n + 1, false);
  queue<int> que;
  que.push(loop_start);

  int before_node[int(2e5 + 5)] = {};
  visited[loop_start] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : graph[q]) {
      if (!visited[next]) {
        que.push(next);
        before_node[next] = q;
        visited[next] = true;
      }
    }
  }

  int now = loop_goal;
  while (now != loop_start) {
    loop.push_back(now);
    now = before_node[now];
  }
  loop.push_back(loop_start);

  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;

    int pu = find_parent(u), pv = find_parent(v);
    if (pu == pv) {
      loop_start = u;
      loop_goal = v;
      loop_search();
    } else {
      parent[max(pu, pv)] = min(pu, pv);
    }
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  fill(visited + 1, visited + n + 1, false);
  for (int l : loop) {
    visited[l] = true;
  }
  for (int l : loop) {
    queue<int> que;
    que.push(l);

    while (!que.empty()) {
      int q = que.front();
      que.pop();

      parent[q] = l;

      for (int next : graph[q]) {
        if (!visited[next]) {
          visited[next] = true;
          que.push(next);
        }
      }
    }
  }

  cin >> m;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;

    if (parent[x] == parent[y]) {
      Yes();
    } else {
      No();
    }
  }

  return 0;
}