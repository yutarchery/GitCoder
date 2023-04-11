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
int dist[2005][2005];
vector<int> graph[2005];

priority_queue<Pii, vector<Pii>, greater<Pii>> que;
void calc_dist(int start) {
  que.push({0, start});
  while (!que.empty()) {
    Pii node = que.top();
    que.pop();

    if (dist[start][node.second] < MOD) {
      continue;
    }

    dist[start][node.second] = node.first;
    for (int next : graph[node.second]) {
      if (dist[start][next] == MOD) {
        que.push({node.first + 1, next});
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = MOD;
    }
  }

  for (int i = 1; i <= n; i++) {
    calc_dist(i);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (1 < dist[i][j] && dist[i][j] < MOD) {
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}