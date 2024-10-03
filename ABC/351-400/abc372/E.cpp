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

int n, q, num, u, v, k, group[int(2e5 + 5)];
set<int> edges[int(2e5 + 5)];

int find_parent(int u) {
  if (group[u] == u) {
    return u;
  } else {
    return find_parent(group[u]);
  }
}

void unite(int u, int v) {
  int pu = find_parent(u), pv = find_parent(v);
  if (pu == pv) {
    return;
  }

  if (edges[pu].size() >= edges[pv].size()) {
    swap(pu, pv);
  }

  for (int next : edges[pu]) {
    edges[pv].insert(next);
  }
  group[u] = pv;
  group[v] = pv;
  group[pu] = pv;

  return;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    edges[i].insert(i);
    group[i] = i;
  }

  while (q--) {
    cin >> num;
    if (num == 1) {
      cin >> u >> v;
      unite(u, v);
    } else {
      cin >> v >> k;

      int pv = find_parent(v);
      if (edges[pv].size() < k) {
        cout << -1 << endl;
      } else {
        auto iter = edges[pv].end();
        for (int j = 1; j <= k; j++) {
          iter--;
        }
        cout << *iter << endl;
      }
    }
  }
  return 0;
}
