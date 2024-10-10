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

int h, w;
char a[2005][2005];
bool obstacle[2005][2005], visited[2005][2005];
int ans[2005][2005];

int si, sj, gi, gj;
const char c[4] = {'>', 'v', '<', '^'};
const int di[4] = {0, 1, 0, -1}, dj[4] = {1, 0, -1, 0};

void make_obstacle(int i, int j, int k) {
  while (1 <= i && i <= h && 1 <= j && j <= w) {
    obstacle[i][j] = true;
    i += di[k];
    j += dj[k];

    if (a[i][j] != '.') {
      break;
    }
  }
  return;
}

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];

      if (a[i][j] == 'S') {
        si = i;
        sj = j;
      }
      if (a[i][j] == 'G') {
        gi = i;
        gj = j;
      }
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (a[i][j] == '#') {
        obstacle[i][j] = true;
      }

      for (int k = 0; k < 4; k++) {
        if (a[i][j] == c[k]) {
          make_obstacle(i, j, k);
        }
      }
    }
  }

  queue<Pii> que;
  que.push({si, sj});
  visited[si][sj] = true;

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    for (int k = 0; k < 4; k++) {
      int ni = q.first + di[k], nj = q.second + dj[k];

      if (1 <= ni && ni <= h && 1 <= nj && nj <= w && !visited[ni][nj] &&
          !obstacle[ni][nj]) {
        visited[ni][nj] = true;
        ans[ni][nj] = ans[q.first][q.second] + 1;
        que.push({ni, nj});
      }
    }
  }

  if (visited[gi][gj]) {
    cout << ans[gi][gj] << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
