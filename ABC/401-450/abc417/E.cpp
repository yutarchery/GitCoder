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

int n, m, x, y, u, v;
vector<int> graph[1005], ans;
bool visited[1005], tmp_visited[1005];

bool is_ok(int start) {
  for (int i = 1; i <= n; i++) {
    tmp_visited[i] = visited[i];
  }

  queue<int> que;
  que.push(start);
  tmp_visited[start] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    if (q == y) {
      return true;
    }

    for (int next : graph[q]) {
      if (!tmp_visited[next]) {
        tmp_visited[next] = true;
        que.push(next);
      }
    }
  }

  return false;
}

void solve() {
  cin >> n >> m >> x >> y;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  for (int i = 1; i <= n; i++) {
    sort(graph[i].begin(), graph[i].end());
  }

  visited[x] = true;
  queue<int> que;
  que.push(x);

  while (!que.empty()) {
    int q = que.front();
    que.pop();
    ans.push_back(q);
    if (q == y) {
      return;
    }

    for (int next : graph[q]) {
      if (visited[next]) {
        continue;
      }

      visited[next] = true;
      if (is_ok(next)) {
        que.push(next);
        break;
      }
    }
  }

  return;
}

void reset() {
  fill(visited, visited + n + 1, false);
  fill(tmp_visited, tmp_visited + n + 1, false);
  for (int i = 1; i <= n; i++) {
    graph[i].resize(0);
  }

  ans.resize(0);
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
    for (int a : ans) {
      cout << a << (a == y ? '\n' : ' ');
    }
    reset();
  }

  return 0;
}
