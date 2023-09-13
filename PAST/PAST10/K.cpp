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
vector<Pli> graph[int(2e5 + 5)], rev_graph[int(2e5 + 5)];

bool visited1[int(2e5 + 5)], visited2[int(2e5 + 5)];
ll dist1[int(2e5 + 5)], dist2[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;

    graph[u].push_back({w, v});
    rev_graph[v].push_back({w, u});
  }

  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  que.push({0, 1});
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();

    if (visited1[q.second]) {
      continue;
    }
    visited1[q.second] = true;
    dist1[q.second] = q.first;

    for (Pli next : graph[q.second]) {
      if (visited1[next.second]) {
        continue;
      }
      que.push({q.first + next.first, next.second});
    }
  }

  que.push({0, n});
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();

    if (visited2[q.second]) {
      continue;
    }
    visited2[q.second] = true;
    dist2[q.second] = q.first;

    for (Pli next : rev_graph[q.second]) {
      if (visited2[next.second]) {
        continue;
      }
      que.push({q.first + next.first, next.second});
    }
  }

  for (int i = 1; i <= n; i++) {
    if (visited1[i] && visited2[i]) {
      cout << dist1[i] + dist2[i] << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}