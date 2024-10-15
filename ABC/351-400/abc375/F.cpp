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

int n, m, q, a[int(2e5 + 5)], b[int(2e5 + 5)];
ll c[int(2e5 + 5)];
vector<int> queries[int(2e5 + 5)];

ll dist[305][305];
bool disabled[int(2e5 + 5)];
ll ans[int(2e5 + 5)];

void prepare_query() {
  cin >> n >> m >> q;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 1; i <= q; i++) {
    int num;
    cin >> num;
    if (num == 1) {
      int j;
      cin >> j;
      disabled[j] = true;
      queries[i] = {num, j};
    } else {
      int x, y;
      cin >> x >> y;
      queries[i] = {num, x, y};
    }
  }
  return;
}

void prepare_dist() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = ll(1e16);
    }
    dist[i][i] = 0;
  }

  for (int i = 1; i <= m; i++) {
    if (disabled[i]) {
      continue;
    }
    dist[a[i]][b[i]] = c[i];
    dist[b[i]][a[i]] = c[i];
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  return;
}

void connect(int idx) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = min(dist[i][j], dist[i][a[idx]] + c[idx] + dist[b[idx]][j]);
      dist[i][j] = min(dist[i][j], dist[i][b[idx]] + c[idx] + dist[a[idx]][j]);
    }
  }

  return;
}

int main() {
  prepare_query();
  prepare_dist();

  for (int i = q; i >= 1; i--) {
    if (queries[i][0] == 1) {
      connect(queries[i][1]);
    } else {
      ans[i] = dist[queries[i][1]][queries[i][2]];

      if (ans[i] == ll(1e16)) {
        ans[i] = -1;
      }
    }
  }

  for (int i = 1; i <= q; i++) {
    if (queries[i][0] == 2) {
      cout << ans[i] << endl;
    }
  }

  return 0;
}
