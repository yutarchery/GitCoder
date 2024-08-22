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

int h, w, y, a[1005][1005];
int ans = 0;

bool visited[1005][1005];
const int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};
priority_queue<pair<int, Pii>, vector<pair<int, Pii>>, greater<pair<int, Pii>>>
    que;

void solve(int now) {
  while (!que.empty()) {
    pair<int, Pii> p = que.top();
    if (p.first > now) {
      break;
    }

    que.pop();
    ans--;

    for (int k = 0; k < 4; k++) {
      int i = p.second.first + di[k], j = p.second.second + dj[k];

      if (!visited[i][j] && 1 <= i && i <= h && 1 <= j && j <= w) {
        visited[i][j] = true;
        que.push({a[i][j], {i, j}});
      }
    }
  }

  return;
}

int main() {
  cin >> h >> w >> y;
  ans = h * w;
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= h; i++) {
    if (!visited[i][1]) {
      visited[i][1] = true;
      que.push({a[i][1], {i, 1}});
    }

    if (!visited[i][w]) {
      visited[i][w] = true;
      que.push({a[i][w], {i, w}});
    }
  }
  for (int j = 1; j <= w; j++) {
    if (!visited[1][j]) {
      visited[1][j] = true;
      que.push({a[1][j], {1, j}});
    }
    if (!visited[h][j]) {
      visited[h][j] = true;
      que.push({a[h][j], {h, j}});
    }
  }

  for (int i = 1; i <= y; i++) {
    solve(i);
    cout << ans << endl;
  }

  return 0;
}
