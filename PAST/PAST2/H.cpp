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

int n, m;
char a[55][55];

vector<Pii> grids[15];
vector<pair<int, Pii>> graph[55][55];

priority_queue<pair<int, Pii>, vector<pair<int, Pii>>, greater<pair<int, Pii>>>
    que;
bool visited[55][55];
int ans[55][55];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];

      if (a[i][j] == 'S') {
        grids[0].push_back({i, j});
      } else if (a[i][j] == 'G') {
        grids[10].push_back({i, j});
        ans[i][j] = -1;
      } else {
        grids[a[i][j] - '0'].push_back({i, j});
      }
    }
  }

  for (int i = 0; i <= 9; i++) {
    for (Pii p : grids[i]) {
      for (Pii q : grids[i + 1]) {
        int dist = abs(p.first - q.first) + abs(p.second - q.second);
        graph[p.first][p.second].push_back({dist, q});
      }
    }
  }

  que.push({0, grids[0][0]});
  while (!que.empty()) {
    pair<int, Pii> q = que.top();
    que.pop();
    if (visited[q.second.first][q.second.second]) {
      continue;
    }
    ans[q.second.first][q.second.second] = q.first;
    visited[q.second.first][q.second.second] = true;

    for (pair<int, Pii> next : graph[q.second.first][q.second.second]) {
      que.push({q.first + next.first, next.second});
    }
  }

  cout << ans[grids[10][0].first][grids[10][0].second] << endl;

  return 0;
}
