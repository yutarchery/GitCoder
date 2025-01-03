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
char s[1005][1005];

const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
queue<Pii> que;
int dist[1005][1005];
bool visited[1005][1005];

int main() {
  cin >> h >> w >> d;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> s[i][j];

      if (s[i][j] == 'H') {
        que.push({i, j});
        visited[i][j] = true;
      }
    }
  }

  while (!que.empty()) {
    Pii now = que.front();
    que.pop();

    for (int k = 0; k < 4; k++) {
      int next_i = now.first + di[k], next_j = now.second + dj[k];
      if (!visited[next_i][next_j] && s[next_i][next_j] == '.') {
        visited[next_i][next_j] = true;
        dist[next_i][next_j] = dist[now.first][now.second] + 1;
        que.push({next_i, next_j});
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      if (visited[i][j] && dist[i][j] <= d) {
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
