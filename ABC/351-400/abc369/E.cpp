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

int n, m, u[int(4e5 + 5)], v[int(4e5 + 5)], q;
ll t[int(4e5 + 5)];

ll dist[405][405];

ll solve() {
  int k, b[5] = {};
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> b[i];
  }
  sort(b, b + k);

  ll ans = 1e16;
  do {

    for (int l = 0; l < (1 << k); l++) {
      int idx = l;
      for (int j = 0; j < k; j++) {
        if (idx % 2 == 1) {
          swap(u[b[j]], v[b[j]]);
        }
        idx /= 2;
      }

      ll now = dist[1][u[b[0]]];
      for (int i = 0; i < k; i++) {
        now += t[b[i]];
        if (i < k - 1) {
          now += dist[v[b[i]]][u[b[i + 1]]];
        }
      }
      now += dist[v[b[k - 1]]][n];
      ans = min(now, ans);

      idx = l;
      for (int j = 0; j < k; j++) {
        if (idx % 2 == 1) {
          swap(u[b[j]], v[b[j]]);
        }
        idx /= 2;
      }
    }
  } while (next_permutation(b, b + k));

  return ans;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      dist[i][j] = 1e16;
      dist[j][i] = 1e16;
    }
  }

  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i] >> t[i];
    dist[u[i]][v[i]] = min(dist[u[i]][v[i]], t[i]);
    dist[v[i]][u[i]] = min(dist[v[i]][u[i]], t[i]);
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  cin >> q;
  for (int i = 0; i < q; i++) {
    cout << solve() << endl;
  }

  return 0;
}
