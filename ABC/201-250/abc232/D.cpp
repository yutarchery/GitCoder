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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int h, w, dist[105][105], ans = 1;
int di[2] = {0, 1}, dj[2] = {1, 0};
char c[105][105];
bool visited[105][105];

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> c[i][j];
    }
  }

  dist[1][1] = 1;
  queue<Pii> que;
  que.push({1, 1});
  while (!que.empty()) {
    Pii now = que.front();
    que.pop();

    if (visited[now.fi][now.se]) {
      continue;
    }

    visited[now.fi][now.se] = true;
    for (int k = 0; k < 2; k++) {
      int nextI = now.fi + di[k];
      int nextJ = now.se + dj[k];

      if (c[nextI][nextJ] != '.') {
        continue;
      }

      que.push({nextI, nextJ});
      dist[nextI][nextJ] = max(dist[nextI][nextJ], dist[now.fi][now.se] + 1);
      ans = max(dist[nextI][nextJ], ans);
    }
  }

  cout << ans << endl;
  return 0;
}