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

int h, w, t;
char a[305][305];

int start_i, start_j, goal_i, goal_j;
int cnt = 0;
Pii p[20];
bool visited[305][305];
int d[305][305], dist[25][25];
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

ll dp[int(1 << 21)][20];

void calc_dist(int idx) {
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      visited[i][j] = false;
      d[i][j] = 0;
    }
  }

  queue<Pii> que;
  visited[p[idx].first][p[idx].second] = true;
  que.push(p[idx]);

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    for (int k = 0; k < 4; k++) {
      int i = q.first + di[k], j = q.second + dj[k];
      if (1 <= i && i <= h && 1 <= j && j <= w && !visited[i][j] &&
          a[i][j] != '#') {
        d[i][j] = d[q.first][q.second] + 1;
        visited[i][j] = true;
        que.push({i, j});
      }
    }
  }

  for (int j = 0; j <= cnt; j++) {
    if (visited[p[j].first][p[j].second]) {
      dist[idx][j] = d[p[j].first][p[j].second];
    } else {
      dist[idx][j] = 1e18;
    }
  }

  return;
}

int calc_point(int idx) {
  int res = 0;
  for (int i = 1; i <= cnt - 1; i++) {
    if ((idx & (1 << i)) != 0) {
      res++;
    }
  }
  return res;
}

int main() {
  cin >> h >> w >> t;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'o') {
        cnt++;
        p[cnt] = {i, j};
      } else if (a[i][j] == 'S') {
        p[0] = {i, j};
      } else if (a[i][j] == 'G') {
        goal_i = i;
        goal_j = j;
      }
    }
  }
  cnt++;
  p[cnt] = {goal_i, goal_j};

  for (int i = 0; i <= cnt; i++) {
    calc_dist(i);
  }

  if (dist[0][cnt] > t) {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < (1 << (cnt + 1)); i++) {
    for (int j = 0; j <= cnt; j++) {
      dp[i][j] = 1e18;
    }
  }

  for (int i = 0; i <= cnt; i++) {
    dp[(1 << i)][i] = dist[0][i];
  }

  for (int i = 0; i < (1 << (cnt + 1)); i++) {
    for (int j = 0; j <= cnt; j++) {
      for (int k = 0; k <= cnt; k++) {
        if ((i & (1 << k)) != 0) {
          continue;
        }
        int next = (i | (1 << k));
        dp[next][k] = min(dp[next][k], dp[i][j] + dist[j][k]);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < (1 << (cnt + 1)); i++) {
    if (dp[i][cnt] <= t) {
      ans = max(ans, calc_point(i));
    }
  }
  cout << ans << endl;

  return 0;
}
