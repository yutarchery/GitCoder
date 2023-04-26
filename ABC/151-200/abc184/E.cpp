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

int h, w, si, sj, gi, gj;
int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
char a[2005][2005];
vector<Pii> warp[26];
bool visited[2005][2005], usedWarp[26];
int dist[2005][2005];

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];

      if (a[i][j] == 'S') {
        si = i, sj = j;
      }
      if (a[i][j] == 'G') {
        gi = i, gj = j;
      }
      if ('a' <= a[i][j] && a[i][j] <= 'z') {
        warp[a[i][j] - 'a'].push_back({i, j});
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
      int iNext = q.first + di[k], jNext = q.second + dj[k];
      if (1 <= iNext && iNext <= h && 1 <= jNext && jNext <= w) {
        if (!visited[iNext][jNext] && a[iNext][jNext] != '#') {
          dist[iNext][jNext] = dist[q.first][q.second] + 1;
          visited[iNext][jNext] = true;
          que.push({iNext, jNext});
        }
      }
    }

    if ('a' <= a[q.first][q.second] && a[q.first][q.second] <= 'z') {
      if (!usedWarp[a[q.first][q.second] - 'a']) {
        usedWarp[a[q.first][q.second] - 'a'] = true;
        for (Pii next : warp[a[q.first][q.second] - 'a']) {
          if (!visited[next.first][next.second]) {
            dist[next.first][next.second] = dist[q.first][q.second] + 1;
            visited[next.first][next.second] = true;
            que.push(next);
          }
        }
      }
    }
  }

  if (visited[gi][gj]) {
    cout << dist[gi][gj] << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}