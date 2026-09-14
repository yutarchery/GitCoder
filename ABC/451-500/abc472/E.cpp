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

int n, m, a, b;

bool visited[int(2e5 + 5)], color[int(2e5 + 5)];
vector<int> graph[int(2e5 + 5)], tree[int(2e5 + 5)];
int dist[int(2e5 + 5)], parent[int(2e5 + 5)];

void display(int start, int goal) {
  dist[start] = 1;

  queue<int> que;
  que.push(start);

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int next : tree[q]) {
      if (dist[next] == 0) {
        dist[next] = dist[q] + 1;
        parent[next] = q;
        que.push(next);
      }
    }
  }

  vector<int> ans;
  int now = goal;
  ans.emplace_back(goal);
  while (now != start) {
    now = parent[now];
    ans.emplace_back(now);
  }

  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
  }
  return;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  queue<int> que;
  for (int i = 1; i <= n; i++) {
    if (visited[i]) {
      continue;
    }

    que.push(i);
    visited[i] = true;

    bool flag = false;
    int start, goal;

    while (!que.empty()) {
      int q = que.front();
      que.pop();

      for (int next : graph[q]) {
        if (!visited[next]) {
          color[next] = !color[q];
          visited[next] = true;
          que.push(next);

          tree[q].emplace_back(next);
          tree[next].emplace_back(q);
        } else {
          if (color[next] == color[q]) {
            start = next;
            goal = q;
            flag = true;
          }
        }
      }
    }

    if (!flag) {
      continue;
    } else {
      display(start, goal);
      return;
    }
  }

  cout << -1 << '\n';
  return;
}

void reset() {
  fill(visited + 1, visited + n + 1, false);
  fill(color + 1, color + n + 1, false);
  fill(dist + 1, dist + n + 1, 0);
  fill(parent + 1, parent + n + 1, 0);

  for (int i = 1; i <= n; i++) {
    graph[i].resize(0);
    tree[i].resize(0);
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
