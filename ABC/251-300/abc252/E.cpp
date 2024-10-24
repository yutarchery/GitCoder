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

int n, m, a[int(2e5 + 5)], b[int(2e5 + 5)], c[int(2e5 + 5)];
vector<array<int, 3>> graph[int(2e5 + 5)];

bool visited[int(2e5 + 5)];
priority_queue<Pli, vector<Pli>, greater<Pli>> que;
ll dist[int(2e5 + 5)];
vector<int> ans;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    graph[a[i]].push_back({c[i], b[i], i});
    graph[b[i]].push_back({c[i], a[i], i});
  }

  visited[1] = true;
  for (array<int, 3> p : graph[1]) {
    que.push({p[0], p[1]});
  }
  while (!que.empty()) {
    Pli q = que.top();
    que.pop();
    if (visited[q.second]) {
      continue;
    }
    visited[q.second] = true;
    dist[q.second] = q.first;

    for (array<int, 3> next : graph[q.second]) {
      if (!visited[next[1]]) {
        que.push({q.first + next[0], next[1]});
      }
    }
  }

  fill(visited + 2, visited + n + 1, false);
  queue<int> que;
  que.push(1);
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (array<int, 3> next : graph[q]) {
      if (!visited[next[1]] && dist[next[1]] == dist[q] + next[0]) {
        visited[next[1]] = true;
        que.push(next[1]);
        ans.push_back(next[2]);
      }
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
    if (i == ans.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
