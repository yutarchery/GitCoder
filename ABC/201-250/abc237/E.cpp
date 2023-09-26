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
ll h[int(2e5 + 5)];
vector<Pli> graph[int(2e5 + 5)];

ll p[int(2e5 + 5)];
bool visited[int(2e5 + 5)];
priority_queue<Pli, vector<Pli>, greater<Pli>> que;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;

    if (h[u] < h[v]) {
      swap(u, v);
    }

    graph[u].push_back({0, v});
    graph[v].push_back({h[u] - h[v], u});
  }

  que.push({-1 * h[1], 1});
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();
    if (visited[q.second]) {
      continue;
    }

    visited[q.second] = true;
    p[q.second] = q.first;

    for (Pli next : graph[q.second]) {
      if (visited[next.second]) {
        continue;
      }
      que.push({q.first + next.first, next.second});
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, -1 * (h[i] + p[i]));
  }
  cout << ans << endl;

  return 0;
}