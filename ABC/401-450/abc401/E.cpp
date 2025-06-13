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

int n, m, u, v;
vector<int> graph[int(2e5 + 5)];

set<int> reached, erasing;
int ans[int(2e5 + 5)];
bool visited[int(2e5 + 5)], solved[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  erasing.insert(1);
  while (!erasing.empty()) {
    auto iter = erasing.begin();
    int now = *iter;
    visited[now] = true;
    reached.insert(now);
    erasing.erase(now);

    for (int next : graph[now]) {
      if (!visited[next]) {
        erasing.insert(next);
      }
    }

    iter = reached.end();
    iter--;
    int bottom = *iter;

    if (bottom == int(reached.size())) {
      ans[bottom] = erasing.size();
      solved[bottom] = true;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << (solved[i] ? ans[i] : -1) << endl;
  }

  return 0;
}
