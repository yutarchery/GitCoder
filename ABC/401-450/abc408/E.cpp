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

int n, m, u, v, w;
vector<Pli> graph[int(2e5 + 5)];

bool visited[int(2e5 + 5)];

ll solve(int idx, ll val) {
  if (idx < 0) {
    return val;
  }

  ll v = val - (1ll << idx);

  fill(visited, visited + n + 1, false);
  queue<int> que;
  que.push(1);
  visited[1] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (Pli next : graph[q]) {
      if (visited[next.second]) {
        continue;
      }

      if ((next.first | v) == v) {
        visited[next.second] = true;
        que.push(next.second);
      }
    }
  }

  if (!visited[n]) {
    return solve(idx - 1, val);
  } else {
    return solve(idx - 1, v);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    graph[u].push_back({w, v});
    graph[v].push_back({w, u});
  }

  cout << solve(31, (1ll << 32) - 1) << endl;

  return 0;
}
