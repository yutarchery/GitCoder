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

int n, a[int(2e5 + 5)], b[int(2e5 + 5)];

vector<int> graph[int(2e5 + 5)];
int dist[int(2e5 + 5)], child_count[int(2e5 + 5)];

bool visited[int(2e5 + 5)];
ll ans[int(2e5 + 5)];

int dfs(int start = 1) {
  if (visited[start]) {
    return child_count[start];
  }

  visited[start] = true;
  int res = 0;
  for (int next : graph[start]) {
    if (visited[next]) {
      continue;
    }
    dist[next] += dist[start] + 1;
    res += dfs(next);
  }

  return child_count[start] = res + 1;
}

void solve(int start = 1) {
  if (visited[start]) {
    return;
  }

  visited[start] = true;
  for (int next : graph[start]) {
    if (visited[next]) {
      continue;
    }

    ans[next] += ans[start];
    solve(next);
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> a[i] >> b[i];
    graph[a[i]].emplace_back(b[i]);
    graph[b[i]].emplace_back(a[i]);
  }
  dfs();

  for (int i = 1; i <= n - 1; i++) {
    if (dist[a[i]] > dist[b[i]]) {
      swap(a[i], b[i]);  // b[i] is child
    }

    if (n - child_count[b[i]] < child_count[b[i]]) {
      ans[b[i]] += i;
    } else {
      ans[1] += i;
      ans[b[i]] -= i;
    }
  }

  fill(visited, visited + n + 1, false);
  solve();

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
