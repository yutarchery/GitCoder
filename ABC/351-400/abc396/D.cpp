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
ll w;
bool visited[15][15];
ll graph[15][15];

int order[15];
ll ans = (1ll << 60);

void solve() {
  ll now = 0;
  for (int i = 1; i + 1 <= n; i++) {
    if (!visited[order[i]][order[i + 1]]) {
      return;
    }

    now ^= graph[order[i]][order[i + 1]];

    if (order[i + 1] == n) {
      break;
    }
  }

  ans = min(ans, now);
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    visited[u][v] = true;
    visited[v][u] = true;
    graph[u][v] = w;
    graph[v][u] = w;
  }
  for (int i = 1; i <= n; i++) {
    order[i] = i;
  }

  do {
    solve();
  } while (next_permutation(order + 2, order + n + 1));
  cout << ans << endl;

  return 0;
}
