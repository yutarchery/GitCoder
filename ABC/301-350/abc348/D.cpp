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

int h, w, n, r, c, e;
char a[205][205];

int start_i, start_j, goal_i, goal_j;
bool ans[205][205];

const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
vector<Pii> graph[205][205];

void create_graph(int r, int c, int e) {
  bool visited[205][205] = {};
  int dist[205][205] = {};

  queue<Pii> que;
  que.push({r, c});
  visited[r][c] = true;

  while (!que.empty()) {
    Pii now = que.front();
    que.pop();

    for (int k = 0; k < 4; k++) {
      int next_i = now.first + di[k], next_j = now.second + dj[k];

      if (visited[next_i][next_j]) {
        continue;
      }
      if (a[next_i][next_j] == '#') {
        continue;
      }

      if (1 <= next_i && next_i <= h && 1 <= next_j && next_j <= w) {
        dist[next_i][next_j] = dist[now.first][now.second] + 1;
        visited[next_i][next_j] = true;
        que.push({next_i, next_j});
      }
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (visited[i][j] && dist[i][j] <= e) {
        graph[r][c].push_back({i, j});
      }
    }
  }

  return;
}

bool solve() {
  queue<Pii> que;
  que.push({start_i, start_j});
  ans[start_i][start_j] = true;

  while (!que.empty()) {
    Pii now = que.front();
    que.pop();
    for (Pii next : graph[now.first][now.second]) {
      if (!ans[next.first][next.second]) {
        ans[next.first][next.second] = true;
        que.push(next);
      }
    }
  }

  return ans[goal_i][goal_j];
}

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'S') {
        start_i = i, start_j = j;
      }
      if (a[i][j] == 'T') {
        goal_i = i, goal_j = j;
      }
    }
  }
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> r >> c >> e;
    create_graph(r, c, e);
  }

  if (solve()) {
    Yes();
  } else {
    No();
  }

  return 0;
}
