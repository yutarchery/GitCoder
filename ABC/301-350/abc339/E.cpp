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
  vector<int> node;

  void init() {
    int sz = 1;
    while (sz <= n) {
      sz *= 2;
    }
    n = sz;
    node.resize(2 * sz - 1);
    return;
  }

  void update(int idx, int val) {
    idx += n - 1;
    node[idx] = val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = max(node[idx * 2 + 1], node[idx * 2 + 2]);
    }
    return;
  }

  int get_max(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }

    if (r <= a || b <= l) {
      return 0;
    }
    if (a <= l && r <= b) {
      return node[k];
    }
    return max(get_max(a, b, k * 2 + 1, l, (l + r) / 2),
               get_max(a, b, k * 2 + 2, (l + r) / 2, r));
  }
};

int n, d, a[int(5e5 + 5)];

int main() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  SegmentTree tree;
  tree.n = int(5e5 + 5);
  tree.init();
  for (int i = 1; i <= n; i++) {
    int now_a = max(1, a[i] - d), now_b = min(int(5e5), a[i] + d);
    int now_max = tree.get_max(now_a, now_b + 1);
    tree.update(a[i], now_max + 1);
  }

  cout << tree.get_max(1, int(5e5 + 1)) << endl;

  return 0;
}
