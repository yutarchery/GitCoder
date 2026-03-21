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

int n, k, u, v, a[105];

vector<int> graph[105];
int dist[105];
int ans[105][105][2];
bool visited[105][105][2];

void prepare(int start = 1) {
  queue<int> que;
  que.push(start);
  dist[start] = 1;

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int next : graph[q]) {
      if (dist[next] == 0) {
        dist[next] = dist[q] + 1;
        que.push(next);
      }
    }
  }

  return;
}

void solve(int node = 1) {
  visited[node][0][0] = true;

  ans[node][1][1] = a[node];
  visited[node][1][1] = true;

  for (int next : graph[node]) {
    if (dist[node] > dist[next]) {
      continue;
    }
    solve(next);

    queue<array<int, 3>> que;
    for (int i = 0; i <= k; i++) {
      for (int j = 0; i + j <= k; j++) {
        if (visited[node][i][0] && visited[next][j][0]) {
          que.push({i + j, 0, ans[node][i][0] + ans[next][j][0]});
        }
        if (visited[node][i][0] && visited[next][j][1]) {
          que.push({i + j, 0, ans[node][i][0] + ans[next][j][1]});
        }

        if (visited[node][i][1] && visited[next][j][0]) {
          que.push({i + j, 1, ans[node][i][1] + ans[next][j][0]});
        }
      }
    }

    while (!que.empty()) {
      array<int, 3> q = que.front();
      que.pop();
      ans[node][q[0]][q[1]] = max(ans[node][q[0]][q[1]], q[2]);
      visited[node][q[0]][q[1]] = true;
    }
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= n - 1; i++) {
    cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  prepare();
  solve();

  if (visited[1][k][0] || visited[1][k][1]) {
    cout << max(ans[1][k][0], ans[1][k][1]) << '\n';
  } else {
    cout << -1 << '\n';
  }

  return 0;
}
