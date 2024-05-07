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

int n, m, c[2005], dist[int(5e6 + 5)];
bool visited[int(5e6 + 5)];
vector<int> original[2005], graph[int(5e6 + 5)];

void prepare() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    original[u].push_back(v);
    original[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (c[i] == c[j]) {
        continue;
      }

      for (int ii : original[i]) {
        for (int jj : original[j]) {
          if (c[ii] == c[jj]) {
            continue;
          }
          graph[i * (n + 1) + j].push_back(ii * (n + 1) + jj);
        }
      }
    }
  }
  return;
}

void solve() {
  prepare();
  queue<int> que;
  que.push(1 * (n + 1) + n);
  visited[1 * (n + 1) + n] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int next : graph[q]) {
      if (!visited[next]) {
        visited[next] = true;
        dist[next] = dist[q] + 1;
        que.push(next);
      }
    }
  }

  if (visited[n * (n + 1) + 1]) {
    cout << dist[n * (n + 1) + 1] << endl;
  } else {
    cout << -1 << endl;
  }

  return;
}

void reset() {
  fill(c, c + n + 1, 0);
  for (int i = 1; i <= n; i++) {
    original[i].resize(0);
  }
  for (int i = 1; i <= (n + 1) * (n + 1); i++) {
    graph[i].resize(0);
  }
  fill(visited, visited + (n + 1) * (n + 1) + 1, false);
  fill(dist, dist + (n + 1) * (n + 1) + 1, 0);

  return;
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    solve();
    reset();
  }

  return 0;
}
