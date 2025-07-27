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

int n, m, k, a[int(1e5 + 5)], b[int(1e5 + 5)], d[505];
ll c[int(1e5 + 5)], t;
int q, op, x, y;
ll tt;

ll dist[505][505];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 1; j <= n + 1; j++) {
      if (i != j) {
        dist[i][j] = 1e16;
      }
    }
  }

  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i];
    dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
    dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
  }

  cin >> k >> t;
  for (int i = 1; i <= k; i++) {
    cin >> d[i];
    dist[d[i]][n + 1] = t;
    dist[n + 1][d[i]] = 0;
  }

  for (int l = 1; l <= n + 1; l++) {
    for (int i = 1; i <= n + 1; i++) {
      for (int j = 1; j <= n + 1; j++) {
        dist[i][j] = min(dist[i][j], dist[i][l] + dist[l][j]);
      }
    }
  }

  cin >> q;
  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y >> tt;
      dist[x][y] = min(dist[x][y], tt);
      dist[y][x] = min(dist[y][x], tt);

      for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n + 1; j++) {
          dist[i][j] = min(dist[i][j], dist[i][x] + dist[x][y] + dist[y][j]);
          dist[i][j] = min(dist[i][j], dist[i][y] + dist[y][x] + dist[x][j]);
        }
      }
    } else if (op == 2) {
      cin >> x;
      dist[x][n + 1] = min(dist[x][n + 1], t);
      dist[n + 1][x] = min(dist[n + 1][x], 0ll);

      for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n + 1; j++) {
          dist[i][j] =
              min(dist[i][j], dist[i][x] + dist[x][n + 1] + dist[n + 1][j]);
          dist[i][j] =
              min(dist[i][j], dist[i][n + 1] + dist[n + 1][x] + dist[x][j]);
        }
      }
    } else {
      ll ans = 0;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          ans += (dist[i][j] == 1e16 ? 0 : dist[i][j]);
        }
      }
      cout << ans << endl;
    }
  }

  return 0;
}
