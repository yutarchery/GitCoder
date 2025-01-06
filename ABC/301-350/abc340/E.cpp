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

public:
  LazySegmentTree(int _n) {
    int sz = 1;
    while (sz < _n) {
      sz *= 2;
    }
    n = sz;
    node.resize(2 * n - 1);
    lazy.resize(2 * n - 1);
  }

  void lazy_evaluate(int k, int l, int r) {
    node[k] += lazy[k];
    if (r - l > 1) {
      lazy[2 * k + 1] += lazy[k] / 2;
      lazy[2 * k + 2] += lazy[k] / 2;
    }
    lazy[k] = 0;
    return;
  }

  void add(int a, int b, ll val, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }

    lazy_evaluate(k, l, r);
    if (b <= l || r <= a) {
      return;
    }

    if (a <= l && r <= b) {
      lazy[k] += val * ll(r - l);
      lazy_evaluate(k, l, r);
    } else {
      add(a, b, val, 2 * k + 1, l, (l + r) / 2);
      add(a, b, val, 2 * k + 2, (l + r) / 2, r);
      node[k] = node[2 * k + 1] + node[2 * k + 2];
    }
    return;
  }

  ll get_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }

    lazy_evaluate(k, l, r);
    if (b <= l || r <= a) {
      return 0;
    }

    if (a <= l && r <= b) {
      return node[k];
    }

    return get_sum(a, b, 2 * k + 1, l, (l + r) / 2) +
           get_sum(a, b, 2 * k + 2, (l + r) / 2, r);
  }
};

ll n, m, a[int(2e5 + 5)], b[int(2e5 + 5)];

int main() {
  cin >> n >> m;

  LazySegmentTree tree(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tree.add(i, i + 1, a[i]);
  }

  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    ll now = tree.get_sum(b[i], b[i] + 1);
    tree.add(b[i], b[i] + 1, -1 * now);
    tree.add(0, n, now / n);
    ll rest = now % n;

    if ((b[i] + 1) + rest > n) {
      tree.add(b[i] + 1, n, 1);
      tree.add(0, (b[i] + 1 + rest) - n, 1);
    } else {
      tree.add(b[i] + 1, (b[i] + 1) + rest, 1);
    }
  }

  cout << tree.get_sum(0, 1);
  for (int i = 1; i < n; i++) {
    cout << " " << tree.get_sum(i, i + 1);
  }
  cout << endl;

  return 0;
}
