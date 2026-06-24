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

int n, m, u[int(2e5 + 5)], v[int(2e5 + 5)];
ll y, t[int(2e5 + 5)], x[int(2e5 + 5)];

vector<Pli> graph[int(2e5 + 5)];
ll dist[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m >> y;
  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i] >> t[i];

    graph[u[i]].push_back({t[i], v[i]});
    graph[v[i]].push_back({t[i], u[i]});
  }

  for (int i = 1; i <= n; i++) {
    cin >> x[i];

    graph[i].push_back({x[i] + y, n + 1});
    graph[n + 1].push_back({x[i], i});
  }

  fill(dist + 2, dist + n + 2, ll(1e16));
  priority_queue<Pli, vector<Pli>, greater<Pli>> que;
  for (Pli p : graph[1]) {
    que.push(p);
  }

  while (!que.empty()) {
    Pli q = que.top();
    que.pop();
    if (dist[q.second] < ll(1e16)) {
      continue;
    }

    dist[q.second] = q.first;
    for (Pli next : graph[q.second]) {
      que.push({q.first + next.first, next.second});
    }
  }

  for (int i = 2; i <= n; i++) {
    cout << dist[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
