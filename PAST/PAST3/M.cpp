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

int n, m, u, v, s, k, t[20];
vector<int> graph[int(1e5 + 5)];

int dist[20][20], ans[int(1 << 20)][20];
bool visited[int(1e5 + 5)];
int now_dist[int(1e5 + 5)];

void make_dist(int idx) {
  fill(visited, visited + n + 1, false);
  fill(now_dist, now_dist + n + 1, 0);
  queue<int> que;
  que.push(t[idx]);
  visited[t[idx]] = true;
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : graph[q]) {
      if (!visited[next]) {
        visited[next] = true;
        now_dist[next] = now_dist[q] + 1;
        que.push(next);
      }
    }
  }

  for (int j = 0; j < k; j++) {
    dist[idx][j] = now_dist[t[j]];
  }
  return;
}

void prepare() {
  for (int i = 1; i < (1 << k); i++) {
    for (int j = 0; j < k; j++) {
      ans[i][j] = 1e9;
    }
  }

  fill(visited, visited + n + 1, false);
  fill(now_dist, now_dist + n + 1, 0);

  queue<int> que;
  que.push(s);
  visited[s] = true;
  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : graph[q]) {
      if (!visited[next]) {
        visited[next] = true;
        now_dist[next] = now_dist[q] + 1;
        que.push(next);
      }
    }
  }

  for (int i = 0; i < k; i++) {
    ans[(1 << i)][i] = now_dist[t[i]];
  }

  for (int i = 0; i < k; i++) {
    make_dist(i);
  }

  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  cin >> s;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> t[i];
  }
  prepare();

  for (int i = 1; i < (1 << k); i++) {
    for (int j = 0; j < k; j++) {
      if (ans[i][j] == int(1e9)) {
        continue;
      }

      for (int jj = 0; jj < k; jj++) {
        if ((i & (1 << jj)) == 0) {
          ans[(i | (1 << jj))][jj] =
              min(ans[(i | (1 << jj))][jj], ans[i][j] + dist[j][jj]);
        }
      }
    }
  }

  int res = 1e9;
  for (int j = 0; j < k; j++) {
    res = min(res, ans[(1 << k) - 1][j]);
  }
  cout << res << endl;

  return 0;
}
