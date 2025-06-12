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

int n;
char c[105][105];

vector<int> graph[26][105], rev_graph[26][105];

priority_queue<pair<int, Pii>, vector<pair<int, Pii>>, greater<pair<int, Pii>>>
    que;

int ans[105][105];
bool visited[105][105];

void prepare(int idx) {
  int dist[105][105];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = int(1e9);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j : graph[idx][i]) {
      dist[i][j] = 1;
    }
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] < int(1e9)) {
        que.push({dist[i][j], {i, j}});
        ans[i][j] = min(ans[i][j], dist[i][j]);
      }
    }
  }

  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> c[i][j];

      if ('a' <= c[i][j] && c[i][j] <= 'z') {
        graph[c[i][j] - 'a'][i].push_back(j);
        rev_graph[c[i][j] - 'a'][j].push_back(i);
      }

      ans[i][j] = int(1e9);
    }
  }

  for (int i = 0; i < 26; i++) {
    prepare(i);
  }
  for (int i = 1; i <= n; i++) {
    ans[i][i] = 0;
    visited[i][i] = true;
  }

  while (!que.empty()) {
    pair<int, Pii> q = que.top();
    int i = q.second.first, j = q.second.second;
    que.pop();

    if (visited[i][j]) {
      continue;
    }
    visited[i][j] = true;
    ans[i][j] = q.first;

    for (int k = 0; k < 26; k++) {
      for (int ni : rev_graph[k][i]) {
        for (int nj : graph[k][j]) {
          if (!visited[ni][nj] && q.first + 2 < ans[ni][nj]) {
            que.push({q.first + 2, {ni, nj}});
          }
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << (ans[i][j] == int(1e9) ? -1 : ans[i][j]) << (j == n ? '\n' : ' ');
    }
  }

  return 0;
}
