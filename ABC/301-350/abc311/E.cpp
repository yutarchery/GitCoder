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

int h, w, n, a[int(1e5 + 5)], b[int(1e5 + 5)];
ll dist[3005][3005];
bool visited[3005][3005];
queue<Pii> que;

const int di[3] = {-1, -1, 0}, dj[3] = {0, -1, -1};

int main() {
  cin >> h >> w >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    que.push({a[i], b[i]});
    visited[a[i]][b[i]] = true;
  }
  for (int i = 1; i <= h; i++) {
    que.push({i, w + 1});
    visited[i][w + 1] = true;
  }
  for (int j = 1; j <= w; j++) {
    que.push({h + 1, j});
    visited[h + 1][j] = true;
  }

  while (!que.empty()) {
    Pii now = que.front();
    que.pop();

    for (int k = 0; k < 3; k++) {
      int next_i = now.first + di[k], next_j = now.second + dj[k];

      if (!visited[next_i][next_j] && 1 <= next_i && next_i <= h &&
          1 <= next_j && next_j <= w) {
        que.push({next_i, next_j});
        visited[next_i][next_j] = true;
        dist[next_i][next_j] = dist[now.first][now.second] + 1;
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      ans += dist[i][j];
    }
  }
  cout << ans << endl;

  return 0;
}
