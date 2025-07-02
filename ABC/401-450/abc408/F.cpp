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
  vector<int> tree;

public:
  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    tree.resize(2 * n - 1, -1e9);
  }

  void insert(int idx, int val) {
    idx += n - 1;
    tree[idx] = val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      tree[idx] = max(tree[2 * idx + 1], tree[2 * idx + 2]);
    }
    return;
  }

  int get_max(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    if (b <= l || r <= a) {
      return -1e9;
    }
    if (a <= l && r <= b) {
      return tree[k];
    }
    return max(get_max(a, b, 2 * k + 1, l, (l + r) / 2),
               get_max(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int n, d, r, h[int(5e5 + 5)];

Pii p[int(5e5 + 5)];
int ans[int(5e5 + 5)];

int main() {
  cin >> n >> d >> r;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    p[i] = {h[i], i};
  }
  sort(p + 1, p + n + 1);

  SegmentTree tree(n + 5);
  for (int i = 1; i <= n; i++) {
    if (i - d >= 1) {
      tree.insert(p[i - d].second, ans[p[i - d].second]);
    }

    int m = tree.get_max(max(1, p[i].second - r), min(n, p[i].second + r) + 1);

    if (m < 0) {
      ans[p[i].second] = 0;
    } else {
      ans[p[i].second] = m + 1;
    }
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    res = max(res, ans[i]);
  }
  cout << res << endl;

  return 0;
}
