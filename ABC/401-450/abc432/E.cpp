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

struct SegmentTree {
  int n;
  vector<ll> node;

  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    node.resize(2 * n - 1, 0);
  }

  void add(int idx, ll val) {
    idx += n - 1;
    node[idx] += val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = node[2 * idx + 1] + node[2 * idx + 2];
    }
    return;
  }

  ll get_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
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

ll n, q, a[int(5e5 + 5)], op, x, y, l, r;

int main() {
  cin >> n >> q;
  SegmentTree cnt(int(5e5 + 5)), sum(int(5e5 + 5));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt.add(a[i], 1);
    sum.add(a[i], a[i]);
  }

  for (int i = 1; i <= q; i++) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y;
      cnt.add(a[x], -1);
      sum.add(a[x], -1 * a[x]);

      a[x] = y;
      cnt.add(y, 1);
      sum.add(y, y);
    } else {
      cin >> l >> r;

      ll ans = 0;
      if (l <= r) {
        ans += r * cnt.get_sum(r + 1, ll(5e5 + 1));
        ans += sum.get_sum(l, r + 1);
        ans += l * cnt.get_sum(0, l);
        cout << ans << endl;
      } else {
        cout << l * n << endl;
      }
    }
  }

  return 0;
}
