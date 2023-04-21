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
  vector<int> max_node;

public:
  void prepare(int node_size) {
    n = 1;
    while (n < node_size) {
      n *= 2;
    }
    max_node.resize(2 * n - 1);
    return;
  }

  void update(int idx, int val) {
    idx += n - 1;
    max_node[idx] = val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      max_node[idx] = max(max_node[2 * idx + 1], max_node[2 * idx + 2]);
    }
    return;
  }

  int getmax(int a, int b, int idx = 0, int l = 0, int r = -1) {
    if (r < 0) {
      r = n;
    }
    if (b <= l || r <= a) {
      return 0;
    }
    if (a <= l && r <= b) {
      return max_node[idx];
    }
    return max(getmax(a, b, 2 * idx + 1, l, (l + r) / 2),
               getmax(a, b, 2 * idx + 2, (l + r) / 2, r));
  }
};

int n, q, a[int(2e5 + 5)];
SegmentTree tree;

int main() {
  cin >> n >> q;
  tree.prepare(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tree.update(i, a[i]);
  }

  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x, v;
      cin >> x >> v;
      tree.update(x, v);
    } else if (t == 2) {
      int a, b;
      cin >> a >> b;
      cout << tree.getmax(a, b + 1) << endl;
    } else {
      int x, v;
      cin >> x >> v;
      if (tree.getmax(x, n + 1) < v) {
        cout << n + 1 << endl;
        continue;
      }
      int l = x, r = n + 1;
      while (r - l > 1) {
        int mid = (l + r) / 2;
        if (tree.getmax(l, mid) < v) {
          l = mid;
        } else {
          r = mid;
        }
      }
      cout << l << endl;
    }
  }

  return 0;
}