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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, m, a[int(2e5 + 5)], b[int(2e5 + 5)], c[int(2e5 + 5)];

vector<int> tree[int(2e5 + 5)];
int parent[int(2e5 + 5)];

int find_parent(int u) {
  if (parent[u] == u) {
    return u;
  }

  int pu = find_parent(parent[u]);
  return parent[u] = pu;
}

void unite(int u, int v) {
  int pu = find_parent(u), pv = find_parent(v);

  parent[u] = min(pu, pv);
  parent[v] = min(pu, pv);
  parent[max(pu, pv)] = min(pu, pv);

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }

  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  for (int i = 1; i <= m; i++) {
    if (c[a[i]] != c[b[i]]) {
      tree[a[i]].emplace_back(b[i]);
      tree[b[i]].emplace_back(a[i]);
      unite(a[i], b[i]);
    }
  }

  for (int i = 1; i <= m; i++) {
    if (c[a[i]] == c[b[i]]) {
      if (find_parent(a[i]) == find_parent(b[i])) {
        Yes();
        return 0;
      }
    }
  }

  No();

  return 0;
}
