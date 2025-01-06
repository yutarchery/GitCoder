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

struct LazySegmentTree {
private:
  int n;
  vector<ll> node, lazy;
  vector<bool> lazy_flag;
  const ll MAX = 1e18;

public:
  LazySegmentTree(int _n) {
    int sz = 1;
    while (sz < _n) {
      sz *= 2;
    }
    n = sz;
    node.resize(n * 2 - 1, 0);
    lazy.resize(n * 2 - 1, 0);
    lazy_flag.resize(n * 2 - 1, false);
  }

  void lazy_evaluate(int k, int l, int r) {
    if (lazy_flag[k]) {
      node[k] = lazy[k];

      if (r - l > 1) {
        lazy[2 * k + 1] = lazy[k];
        lazy_flag[2 * k + 1] = true;
        lazy[2 * k + 2] = lazy[k];
        lazy_flag[2 * k + 2] = true;
      }
    }
    lazy[k] = 0;
    lazy_flag[k] = false;
    return;
  }

  void insert(int a, int b, ll val, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    lazy_evaluate(k, l, r);

    if (r <= a || b <= l) {
      return;
    }

    if (a <= l && r <= b) {
      lazy[k] = val;
      lazy_flag[k] = true;
      lazy_evaluate(k, l, r);
    } else {
      insert(a, b, val, 2 * k + 1, l, (l + r) / 2);
      insert(a, b, val, 2 * k + 2, (l + r) / 2, r);
      node[k] = min(node[2 * k + 1], node[2 * k + 2]);
    }
    return;
  }

  ll get_min(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }

    lazy_evaluate(k, l, r);

    if (r <= a || b <= l) {
      return MAX;
    }
    if (a <= l && r <= b) {
      return node[k];
    }

    return min(get_min(a, b, 2 * k + 1, l, (l + r) / 2),
               get_min(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int h, w, n, r[int(2e5 + 5)], c[int(2e5 + 5)], l[int(2e5 + 5)];
Pii r_idx[int(2e5 + 5)];
ll ans[int(2e5 + 5)];

int main() {
  cin >> h >> w >> n;
  for (int i = 1; i <= n; i++) {
    cin >> r[i] >> c[i] >> l[i];
    r_idx[i] = {r[i], i};
  }
  sort(r_idx + 1, r_idx + n + 1, greater<Pii>());

  LazySegmentTree tree(w + 1);
  tree.insert(1, w + 1, h + 1);

  for (int i = 1; i <= n; i++) {
    int idx = r_idx[i].second;
    ans[idx] = tree.get_min(c[idx], c[idx] + l[idx]) - 1;
    tree.insert(c[idx], c[idx] + l[idx], ans[idx]);
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
