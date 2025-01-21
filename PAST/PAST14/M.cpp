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
private:
  int n;
  vector<ll> node;

public:
  SegmentTree(int _n) {
    int sz = 1;
    while (sz < _n) {
      sz *= 2;
    }
    n = sz;
    node.resize(2 * sz - 1);
  }

  void insert(int idx, ll val) {
    idx += n - 1;
    node[idx] = val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = max(node[2 * idx + 1], node[2 * idx + 2]);
    }
    return;
  }

  ll get_max(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }

    if (r <= a || b <= l) {
      return 0;
    }
    if (a <= l && r <= b) {
      return node[k];
    }

    return max(get_max(a, b, 2 * k + 1, l, (l + r) / 2),
               get_max(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int n, m;
ll a[int(2e5 + 5)], b[int(2e5 + 5)], ans[int(2e5 + 5)];

int main() {
  cin >> n >> m;
  SegmentTree tree(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    tree.insert(i, b[i]);
  }

  for (int i = 1; i <= n; i++) {
    if (tree.get_max(1, m + 1) < a[i]) {
      No();
      cout << i << endl;
      return 0;
    }
    int l = 1, r = m + 1;
    while (r - l > 1) {
      int mid = (l + r) / 2;

      if (a[i] <= tree.get_max(l, mid)) {
        r = mid;
      } else {
        l = mid;
      }
    }

    ans[l] += a[i];
    b[l] -= a[i];
    tree.insert(l, b[l]);
  }

  Yes();
  for (int i = 1; i <= m; i++) {
    cout << ans[i];
    if (i == m) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
