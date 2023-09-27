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

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;

    if (!(1 <= u && u <= n && 1 <= v && v <= n)) {
      No();
      return 0;
    }

    if (u == v) {
      No();
      return 0;
    }

    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    if (graph[i].size() <= 1) {
      continue;
    }

    sort(graph[i].begin(), graph[i].end());
    for (int j = 0; j < graph[i].size() - 1; j++) {
      if (graph[i][j] == graph[i][j + 1]) {
        No();
        return 0;
      }
    }
  }
  Yes();

  return 0;
}