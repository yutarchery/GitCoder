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

int di[4] = {-1, 0, 1, 0}, dj[4] = {0, -1, 0, 1};

int n, m;
char c[15][15];

int ans = 0;
bool visited[15][15];

bool solve(int start_i, int start_j) {
  c[start_i][start_j] = '.';

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      visited[i][j] = false;
    }
  }

  queue<Pii> que;
  que.push({start_i, start_j});

  while (!que.empty()) {
    Pii now = que.front();
    que.pop();

    if (visited[now.first][now.second]) {
      continue;
    }

    visited[now.first][now.second] = true;
    for (int k = 0; k < 4; k++) {
      int next_i = now.first + di[k], next_j = now.second + dj[k];

      if (!visited[next_i][next_j] && c[next_i][next_j] == '.') {
        que.push({next_i, next_j});
      }
    }
  }

  c[start_i][start_j] = '#';
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (c[i][j] == '.' && !visited[i][j]) {
        return false;
      }
    }
  }

  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (c[i][j] == '#') {
        if (solve(i, j)) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}