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

int n, m, a, b;
vector<int> graph[105];
bool visited[105];

int dist[105];
ll dp[105];

void prepare_dist() {
  queue<int> que;
  que.push(a);
  visited[a] = true;
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
}

ll solve(int node) {
  if (visited[node]) {
    return dp[node];
  }
  visited[node] = true;
  if (node == a) {
    return dp[node] = 1;
  }

  ll ans = 0;
  for (int before : graph[node]) {
    if (dist[node] - 1 == dist[before]) {
      ans += solve(before);
      ans %= MOD;
    }
  }
  return dp[node] = ans;
}

int main() {
  cin >> n >> a >> b >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  prepare_dist();

  fill(visited, visited + n + 1, false);
  cout << solve(b) << endl;

  return 0;
}