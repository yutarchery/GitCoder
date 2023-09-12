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

int n, q;
bool graph[105][105];

void solve(int u, int v) {
  bool visited[105];
  fill(visited + 1, visited + n + 1, false);

  queue<int> que;
  que.push(u);
  visited[u] = true;
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int i = 1; i <= n; i++) {
      if (graph[q][i] && !visited[i]) {
        visited[i] = true;
        que.push(i);
      }
    }
  }

  if (visited[v]) {
    Yes();
  } else {
    No();
  }
  return;
}

int main() {
  cin >> n >> q;
  for (int i = 0; i < q; i++) {
    int t, u, v;
    cin >> t >> u >> v;

    if (t == 1) {
      graph[u][v] = !graph[u][v];
      graph[v][u] = !graph[v][u];
    } else {
      solve(u, v);
    }
  }

  return 0;
}