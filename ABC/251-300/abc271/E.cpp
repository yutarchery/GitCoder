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

int n, m, k, a[int(2e5 + 5)], b[int(2e5 + 5)], e[int(2e5 + 5)];
ll c[int(2e5 + 5)], dist[int(2e5 + 5)];

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }
  for (int i = 1; i <= k; i++) {
    cin >> e[i];
  }
  fill(dist + 2, dist + n + 1, 1e16);

  for (int i = 1; i <= k; i++) {
    dist[b[e[i]]] = min(dist[b[e[i]]], dist[a[e[i]]] + c[e[i]]);
  }

  if (dist[n] == 1e16) {
    cout << -1 << endl;
  } else {
    cout << dist[n] << endl;
  }

  return 0;
}