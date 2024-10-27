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

int n, m, u[int(2e5 + 5)], v[int(2e5 + 5)];
int k, x[int(2e5 + 5)], y[int(2e5 + 5)];
int cq, p[int(2e5 + 5)], q[int(2e5 + 5)];

int par[int(2e5 + 5)];
map<Pii, bool> visited;

int find_parent(int p) {
  if (par[p] == p) {
    return p;
  }
  int res = find_parent(par[p]);
  return par[p] = res;
}

void unite(int u, int v) {
  int pu = find_parent(u), pv = find_parent(v);
  par[u] = min(pu, pv);
  par[v] = min(pu, pv);
  par[max(pu, pv)] = min(pu, pv);
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    par[i] = i;
  }

  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i];
    unite(u[i], v[i]);
  }

  cin >> k;
  for (int i = 1; i <= k; i++) {
    cin >> x[i] >> y[i];
    int px = find_parent(x[i]), py = find_parent(y[i]);
    visited[{px, py}] = true;
    visited[{py, px}] = true;
  }

  cin >> cq;
  for (int i = 1; i <= cq; i++) {
    cin >> p[i] >> q[i];
  }
  for (int i = 1; i <= cq; i++) {
    int pp = find_parent(p[i]), pq = find_parent(q[i]);
    if (visited[{pp, pq}]) {
      No();
    } else {
      Yes();
    }
  }

  return 0;
}
