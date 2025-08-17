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
  vector<int> node, lazy;

public:
  LazySegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    node.resize(2 * n - 1);
    lazy.resize(2 * n - 1);
  }

  void evaluate(int k, int l, int r) {
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

    evaluate(k, l, r);
    if (b <= l || r <= a) {
      return;
    }
    if (a <= l && r <= b) {
      lazy[k] += val * ll(r - l);
      evaluate(k, l, r);
      return;
    }

    add(a, b, val, 2 * k + 1, l, (l + r) / 2);
    add(a, b, val, 2 * k + 2, (l + r) / 2, r);
    node[k] = node[2 * k + 1] + node[2 * k + 2];
    return;
  }

  ll get_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    evaluate(k, l, r);
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

int n, m, l[int(2e5 + 5)], r[int(2e5 + 5)];
char s[int(5e5 + 5)], t[int(5e5 + 5)];

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> t[i];
  }

  LazySegmentTree tree(n + 5);
  for (int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i];
    tree.add(l[i], r[i] + 1, 1);
  }

  for (int i = 1; i <= n; i++) {
    if (tree.get_sum(i, i + 1) % 2 == 0) {
      cout << s[i];
    } else {
      cout << t[i];
    }
  }
  cout << endl;

  return 0;
}
