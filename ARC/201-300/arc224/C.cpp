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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, m, u, v;

int ans[int(3e5 + 5)];
vector<int> graph[int(3e5 + 5)];
bool visited[int(3e5 + 5)];

void search(int now = 1) {
  for (int next : graph[now]) {
    if (visited[next]) {
      continue;
    }

    visited[next] = true;
    ans[next] = ans[now] + 1;
    search(next);
  }

  return;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  visited[1] = true;
  ans[1] = 0;
  search();

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return;
}

void reset() {
  fill(visited + 1, visited + n + 1, false);
  fill(ans + 1, ans + n + 1, 0);

  for (int i = 1; i <= n; i++) {
    graph[i].resize(0);
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
    reset();
  }

  return 0;
}
