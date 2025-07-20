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

int n, q, a[105][105];
ll k, dist[105][105], s[105], t[105];

void prepare() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  return;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (a[i][j] == 0) {
        dist[i][j] = ll(1e9);
      } else {
        dist[i][j] = a[i][j];
      }
    }
  }

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> s[i] >> t[i];
  }

  prepare();
  for (int i = 1; i <= q; i++) {
    ll now_s = s[i] % n, now_t = t[i] % n;
    if (now_s == 0) {
      now_s += n;
    }
    if (now_t == 0) {
      now_t += n;
    }

    if (dist[now_s][now_t] == 1e9) {
      cout << -1 << endl;
    } else {
      cout << dist[now_s][now_t] << endl;
    }
  }

  return 0;
}
