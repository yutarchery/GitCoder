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
vector<int> graph[int(2e5 + 5)];

ll ans[int(2e5 + 5)][4];

ll solve(int start, int k) {
  if (ans[start][k] > 0) {
    return ans[start][k];
  }

  bool visited[int(2e5 + 5)] = {};
  int dist[int(2e5 + 5)] = {};

  priority_queue<Pii, vector<Pii>, greater<Pii>> que;
  que.push({0, start});

  while (!que.empty()) {
    Pii now = que.top();
    que.pop();

    if (visited[now.second]) {
      continue;
    }

    visited[now.second] = true;
    dist[now.second] = now.first;

    for (int j = now.first; j <= 3; j++) {
      ans[start][j] += now.second;
    }

    if (now.first <= 2) {
      for (int next : graph[now.second]) {
        if (!visited[next]) {
          que.push({now.first + 1, next});
        }
      }
    }
  }
  return ans[start][k];
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x, k;
    cin >> x >> k;
    cout << solve(x, k) << endl;
  }

  return 0;
}