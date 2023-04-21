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

struct SegmentTree {
private:
  int n;
  vector<ll> sum_node;

public:
  void prepare(int node_size) {
    n = 1;
    while (n < node_size) {
      n *= 2;
    }
    sum_node.resize(n * 2 - 1);
    return;
  }

  void add(int idx, ll val) {
    idx += n - 1;
    sum_node[idx] += val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      sum_node[idx] = sum_node[idx * 2 + 1] + sum_node[idx * 2 + 2];
    }
    return;
  }

  ll getsum(int a, int b, int idx = 0, int l = 0, int r = -1) {
    if (r < 0) {
      r = n;
    }
    if (b <= l || r <= a) {
      return 0;
    }
    if (a <= l && r <= b) {
      return sum_node[idx];
    }
    return getsum(a, b, idx * 2 + 1, l, (l + r) / 2) +
           getsum(a, b, idx * 2 + 2, (l + r) / 2, r);
  }
};

int n, q;
ll a[int(5e5 + 5)];
SegmentTree tree;

int main() {
  cin >> n >> q;
  tree.prepare(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tree.add(i, a[i]);
  }

  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 0) {
      int p;
      ll x;
      cin >> p >> x;
      tree.add(p, x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << tree.getsum(l, r) << endl;
    }
  }

  return 0;
}