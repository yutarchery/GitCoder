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

ll n;
vector<Pil> graph[int(2e5 + 5)];

Pll range[int(2e5 + 5)];
bool visited[int(2e5 + 5)];

void dfs(int start) {
  visited[start] = true;
  queue<int> que;
  que.push(start);

  while (!que.empty()) {
    int now = que.front();
    que.pop();

    for (Pil next : graph[now]) {
      int next_node = next.first;
      ll next_edge = next.second;

      if (visited[next_node]) {
        continue;
      }

      visited[next_node] = true;
      que.push(next_node);

      range[next_node].first = min(range[now].first, next_edge);
      range[next_node].second = max(range[now].second, next_edge);
    }
  }

  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;

    graph[u].push_back({v, i});
    graph[v].push_back({u, i});
  }

  range[1] = {n - 1, 1};
  dfs(1);

  ll ans = (n - 1) * n / 2;
  for (int i = 2; i <= n; i++) {
    ans += range[i].first * (n - range[i].second);
  }
  cout << ans << endl;

  return 0;
}
