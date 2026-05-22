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
  int n;
  vector<int> node;

  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    node.resize(2 * n - 1, 0);
  }

  void add(int idx, int val) {
    idx += n - 1;
    node[idx] += val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = node[2 * idx + 1] + node[2 * idx + 2];
    }
  }

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

int x, q, a[int(2e5 + 5)], b[int(2e5 + 5)];

set<int> nums;

vector<int> vals;
map<int, int> idx;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> x;
  nums.insert(x);
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i] >> b[i];
    nums.insert(a[i]);
    nums.insert(b[i]);
  }

  int cnt = 0;
  for (int num : nums) {
    vals.emplace_back(num);
    idx[num] = cnt;
    cnt++;
  }

  SegmentTree tree(2 * q + 5);
  tree.add(idx[x], 1);
  for (int i = 1; i <= q; i++) {
    tree.add(idx[a[i]], 1);
    tree.add(idx[b[i]], 1);

    int ok = 0, ng = 2 * q + 1;
    while (ng - ok > 1) {
      int now = (ok + ng) / 2;

      if (tree.get_sum(0, now) <= i) {
        ok = now;
      } else {
        ng = now;
      }
    }

    cout << vals[ok] << '\n';
  }

  return 0;
}
