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

int n, gx, gy, x[805], y[805];
const int dx[6] = {1, 0, -1, 1, -1, 0}, dy[6] = {1, 1, 1, 0, 0, -1};

const int offset = 500;
bool visited[2005][2005], disabled[2005][2005];
int dist[2005][2005];

priority_queue<pair<int, Pii>, vector<pair<int, Pii>>, greater<pair<int, Pii>>>
    que;

int main() {
  cin >> n >> gx >> gy;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    disabled[x[i] + offset][y[i] + offset] = true;
  }

  que.push({0, {offset, offset}});
  while (!que.empty()) {
    pair<int, Pii> q = que.top();
    que.pop();
    if (visited[q.second.first][q.second.second]) {
      continue;
    }

    visited[q.second.first][q.second.second] = true;
    dist[q.second.first][q.second.second] = q.first;

    if (q.second.first == gx + offset && q.second.second == gy + offset) {
      cout << q.first << endl;
      return 0;
    }

    for (int k = 0; k < 6; k++) {
      int next_x = q.second.first + dx[k];
      int next_y = q.second.second + dy[k];

      if (!visited[next_x][next_y] && !disabled[next_x][next_y] &&
          0 <= next_x && next_x <= 1000 && 0 <= next_y && next_y <= 1000) {
        que.push({q.first + 1, {next_x, next_y}});
      }
    }
  }
  cout << -1 << endl;

  return 0;
}
