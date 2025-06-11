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
  vector<int> tree;

  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    tree.resize(2 * n - 1);
  }

  void add(int idx, int val) {
    idx += n - 1;
    tree[idx] += val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }
    return;
  }

  int get_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }

    if (b <= l || r <= a) {
      return 0;
    }
    if (a <= l && r <= b) {
      return tree[k];
    }

    return get_sum(a, b, 2 * k + 1, l, (l + r) / 2) +
           get_sum(a, b, 2 * k + 2, (l + r) / 2, r);
  }
};

int n, p[int(5e5 + 5)];
int ans[int(5e5 + 5)];

int main() {
  cin >> n;

  SegmentTree tree(n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    tree.add(i, 1);
  }

  for (int i = n; i >= 1; i--) {
    int ok = 0, ng = n + 1;
    while (ng - ok > 1) {
      int now = (ok + ng) / 2;

      if (tree.get_sum(0, now + 1) < p[i]) {
        ok = now;
      } else {
        ng = now;
      }
    }

    ans[ok + 1] = i;
    tree.add(ok + 1, -1);
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }

  return 0;
}
