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

int h, w, d;
char s[15][15];

int ans = 0, dist[15][15];
bool visited[15][15];
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
int solve(int ai, int aj, int bi, int bj) {
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      visited[i][j] = false;
      dist[i][j] = 0;
    }
  }

  queue<Pii> que;
  que.push({ai, aj});
  visited[ai][aj] = true;
  que.push({bi, bj});
  visited[bi][bj] = true;

  while (!que.empty()) {
    Pii now = que.front();
    que.pop();

    for (int k = 0; k < 4; k++) {
      int next_i = now.first + di[k];
      int next_j = now.second + dj[k];

      if (!visited[next_i][next_j] && 1 <= next_i && next_i <= h &&
          1 <= next_j && next_j <= w) {
        que.push({next_i, next_j});
        visited[next_i][next_j] = true;
        dist[next_i][next_j] = dist[now.first][now.second] + 1;
      }
    }
  }

  int res = 0;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (dist[i][j] <= d && s[i][j] == '.') {
        res++;
      }
    }
  }

  return res;
}

int main() {
  cin >> h >> w >> d;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      for (int ii = 1; ii <= h; ii++) {
        for (int jj = 1; jj <= w; jj++) {
          if (s[i][j] == '.' && s[ii][jj] == '.') {
            ans = max(ans, solve(i, j, ii, jj));
          }
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}
