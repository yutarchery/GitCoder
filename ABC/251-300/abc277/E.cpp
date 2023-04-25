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

int n, m, k, u, v, a, s;
vector<Pii> graph[int(4e5 + 5)];

bool visited[int(4e5 + 5)];
int dist[int(4e5 + 5)];
int main() {
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> a;
    if (a == 0) {
      graph[u + n].push_back({1, v + n});
      graph[v + n].push_back({1, u + n});
    } else {
      graph[u].push_back({1, v});
      graph[v].push_back({1, u});
    }
  }
  for (int i = 0; i < k; i++) {
    cin >> s;
    graph[s].push_back({0, s + n});
    graph[s + n].push_back({0, s});
  }

  priority_queue<Pii, vector<Pii>, greater<Pii>> que;
  que.push({0, 1});

  while (!que.empty()) {
    Pii q = que.top();
    que.pop();
    if (visited[q.second]) {
      continue;
    }
    visited[q.second] = true;
    dist[q.second] = q.first;
    for (Pii next : graph[q.second]) {
      if (!visited[next.second]) {
        que.push({q.first + next.first, next.second});
      }
    }
  }

  if (visited[n] && visited[n * 2]) {
    cout << min(dist[n], dist[n * 2]) << endl;
  } else if (visited[n]) {
    cout << dist[n] << endl;
  } else if (visited[n * 2]) {
    cout << dist[n * 2] << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}