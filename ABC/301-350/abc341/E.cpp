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
    while (sz < n) {
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
      node[idx] = node[2 * idx + 1] + node[2 * idx + 2];
    }
    return;
  }

  int get_val(int idx) { return node[idx + n - 1]; }

  int get_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
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

int n, q, num, l, r;
string s;

int main() {
  cin >> n >> q;
  cin >> s;
  SegmentTree tree;
  tree.n = n;
  tree.init();

  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      tree.update(i + 1, 0);
    } else {
      tree.update(i + 1, 1);
    }
  }

  while (q > 0) {
    q--;
    cin >> num >> l >> r;

    if (num == 1) {
      int l_val = tree.get_val(l - 1), r_val = tree.get_val(r);
      tree.update(l - 1, 1 - l_val);
      tree.update(r, 1 - r_val);
    } else {
      int sum = tree.get_sum(l, r);

      if (sum == r - l) {
        Yes();
      } else {
        No();
      }
    }
  }

  return 0;
}
