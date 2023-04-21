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

struct UnionFind {
private:
  int n;
  vector<int> group;

  int search(int u) {
    int tmp = group[u];
    if (tmp == group[tmp]) {
      return group[u] = tmp;
    } else {
      return group[u] = search(tmp);
    }
  }

public:
  void prepare(int node_size) {
    n = node_size;
    group.resize(n);
    for (int i = 0; i < n; i++) {
      group[i] = i;
    }
  }

  void unite(int u, int v) {
    int gu = search(u), gv = search(v);
    group[max(gu, gv)] = min(gu, gv);
    return;
  }

  bool isSame(int u, int v) {
    int gu = search(u), gv = search(v);
    return gu == gv;
  }
};

int n, q;
UnionFind unionFind;

int main() {
  cin >> n >> q;
  unionFind.prepare(n);

  for (int i = 0; i < q; i++) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t == 0) {
      unionFind.unite(u, v);
    } else {
      cout << unionFind.isSame(u, v) << endl;
    }
  }

  return 0;
}