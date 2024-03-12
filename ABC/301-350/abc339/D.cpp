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
int p_x1 = -1, p_y1 = -1, p_x2 = -1, p_y2 = -1;
string s[65];
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

int ans = 1e9;
bool visited[65][65][65][65];
int dist[65][65][65][65];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];

    for (int j = 0; j < n; j++) {
      if (s[i][j] == 'P') {
        if (p_x1 == -1) {
          p_x1 = i, p_y1 = j;
        } else {
          p_x2 = i, p_y2 = j;
        }
      }
    }
  }

  queue<array<int, 4>> que;
  que.push({p_x1, p_y1, p_x2, p_y2});
  visited[p_x1][p_y1][p_x2][p_y2] = true;

  while (!que.empty()) {
    array<int, 4> now = que.front();
    que.pop();

    if (now[0] == now[2] && now[1] == now[3]) {
      ans = min(ans, dist[now[0]][now[1]][now[2]][now[3]]);
    }

    for (int k = 0; k < 4; k++) {
      int x1 = now[0] + di[k];
      int y1 = now[1] + dj[k];
      int x2 = now[2] + di[k];
      int y2 = now[3] + dj[k];

      if (!(0 <= x1 && x1 < n)) {
        x1 = now[0];
      }
      if (!(0 <= y1 && y1 < n)) {
        y1 = now[1];
      }
      if (s[x1][y1] == '#') {
        x1 = now[0], y1 = now[1];
      }
      if (!(0 <= x2 && x2 < n)) {
        x2 = now[2];
      }
      if (!(0 <= y2 && y2 < n)) {
        y2 = now[3];
      }
      if (s[x2][y2] == '#') {
        x2 = now[2], y2 = now[3];
      }

      if (visited[x1][y1][x2][y2]) {
        continue;
      }
      que.push({x1, y1, x2, y2});
      visited[x1][y1][x2][y2] = true;
      dist[x1][y1][x2][y2] = dist[now[0]][now[1]][now[2]][now[3]] + 1;
    }
  }

  if (ans == 1e9) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
