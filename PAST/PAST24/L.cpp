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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n;
ll x[int(2e5 + 5)], y[int(2e5 + 5)];

Pli x_idx[int(2e5 + 5)], y_idx[int(2e5 + 5)];
vector<Pli> graph[int(2e5 + 5)];
map<Pii, bool> visited;

ll cost = 0;
bool graph_visited[int(2e5 + 5)];
priority_queue<Pli, vector<Pli>, greater<Pli>> que;

void unite(int u, int v) {
  if (visited[{u, v}]) {
    return;
  }

  visited[{u, v}] = true;
  visited[{v, u}] = true;

  ll dist = min(abs(x[u] - x[v]), abs(y[u] - y[v]));
  graph[u].push_back({dist, v});
  graph[v].push_back({dist, u});

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];

    x_idx[i] = {x[i], i};
    y_idx[i] = {y[i], i};
  }
  sort(x_idx + 1, x_idx + n + 1);
  sort(y_idx + 1, y_idx + n + 1);

  for (int i = 1; i + 1 <= n; i++) {
    unite(x_idx[i].second, x_idx[i + 1].second);
    unite(y_idx[i].second, y_idx[i + 1].second);
  }

  que.push({0, 1});
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();

    if (graph_visited[q.second]) {
      continue;
    }

    graph_visited[q.second] = true;
    cost += q.first;

    for (Pli next : graph[q.second]) {
      que.push(next);
    }
  }
  cout << cost << '\n';

  return 0;
}
