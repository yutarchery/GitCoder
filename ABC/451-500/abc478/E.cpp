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

int n, q, t[int(2e5 + 5)], u[int(2e5 + 5)], v[int(2e5 + 5)];

vector<int> graph[int(2e5 + 5)], rev_graph[int(2e5 + 5)],
    group_graph[int(2e5 + 5)];

vector<int> dfs_reached;
bool visited[int(2e5 + 5)];
int group[int(2e5 + 5)], cnt[int(2e5 + 5)];
int group_ans[int(2e5 + 5)];

void dfs(int now) {
  visited[now] = true;

  for (int next : graph[now]) {
    if (!visited[next]) {
      dfs(next);
    }
  }

  dfs_reached.emplace_back(now);
  return;
}

void group_search() {
  for (int i = 1; i <= n; i++) {
    if (visited[i]) {
      continue;
    }
    dfs(i);
  }

  reverse(dfs_reached.begin(), dfs_reached.end());
  fill(visited + 1, visited + n + 1, false);
  for (int v : dfs_reached) {
    if (visited[v]) {
      continue;
    }
    visited[v] = true;

    queue<int> que;
    que.push(v);

    while (!que.empty()) {
      int now = que.front();
      que.pop();
      group[now] = v;

      for (int next : rev_graph[now]) {
        if (!visited[next]) {
          visited[next] = true;
          que.push(next);
        }
      }
    }
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> t[i] >> u[i] >> v[i];

    if (t[i] == 0) {
      graph[u[i]].emplace_back(v[i]);
      rev_graph[v[i]].emplace_back(u[i]);
    }
  }

  group_search();
  for (int i = 1; i <= q; i++) {
    if (group[u[i]] == group[v[i]]) {
      if (t[i] == 1) {
        No();
        return 0;
      } else {
        continue;
      }
    }

    group_graph[group[u[i]]].emplace_back(group[v[i]]);
    cnt[group[v[i]]]++;
  }

  queue<int> que;
  vector<int> reached;
  for (int i = 1; i <= n; i++) {
    if (i == group[i] && cnt[i] == 0) {
      que.push(i);
    }
  }

  while (!que.empty()) {
    int now = que.front();
    reached.emplace_back(now);
    que.pop();
    for (int next : group_graph[now]) {
      cnt[next]--;

      if (cnt[next] == 0) {
        que.push(next);
      }
    }
  }

  for (int i = 0; i < reached.size(); i++) {
    group_ans[reached[i]] = i + 1;
  }

  for (int i = 1; i <= n; i++) {
    if (cnt[i] > 0) {
      No();
      return 0;
    }
  }

  Yes();
  for (int i = 1; i <= n; i++) {
    cout << group_ans[group[i]] << (i == n ? '\n' : ' ');
  }

  return 0;
}
