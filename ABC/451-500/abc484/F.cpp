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

struct SegmentTree {
public:
  int n;
  vector<int> min_node, max_node;

private:
  const int MAX = 1e9;
  const int MIN = -1;

public:
  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }

    min_node.resize(2 * n - 1, MAX);
    max_node.resize(2 * n - 1, MIN);
  }

  void insert(int idx, int val) {
    idx += n - 1;
    max_node[idx] = val;
    min_node[idx] = (val == -1 ? MAX : val);

    while (idx > 0) {
      idx = (idx - 1) / 2;
      max_node[idx] = max(max_node[2 * idx + 1], max_node[2 * idx + 2]);
      min_node[idx] = min(min_node[2 * idx + 1], min_node[2 * idx + 2]);
    }

    return;
  }

  int get_max(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    if (b <= l || r <= a) {
      return MIN;
    }
    if (a <= l && r <= b) {
      return max_node[k];
    }

    return max(get_max(a, b, 2 * k + 1, l, (l + r) / 2),
               get_max(a, b, 2 * k + 2, (l + r) / 2, r));
  }

  int get_min(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    if (b <= l || r <= a) {
      return MAX;
    }
    if (a <= l && r <= b) {
      return min_node[k];
    }
    return min(get_min(a, b, 2 * k + 1, l, (l + r) / 2),
               get_min(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int n, q, a[int(3e5 + 5)];
int op, idx, x, l, r;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  SegmentTree tree(n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tree.insert(i, a[i]);
  }

  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> idx >> x;
      a[idx] = x;
      tree.insert(idx, x);
    } else {
      cin >> l >> r;

      int now_min = tree.get_min(l, r + 1), now_max = tree.get_max(l, r + 1);

      if (now_max == -1) {
        Yes();
      } else {
        if (now_min == now_max) {
          Yes();
        } else {
          No();
        }
      }
    }
  }

  return 0;
}
