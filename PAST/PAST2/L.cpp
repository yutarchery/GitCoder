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
  vector<int> max_node;

public:
  SegmentTree(int _n) {
    int sz = 1;
    while (sz < _n) {
      sz *= 2;
    }

    n = sz;
    max_node.resize(sz * 2 - 1, 0);
    return;
  }

  void insert(int idx, int val) {
    idx += n - 1;
    max_node[idx] = val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      max_node[idx] = max(max_node[2 * idx + 1], max_node[2 * idx + 2]);
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
      return max_node[k];
    }

    return max(get_max(a, b, 2 * k + 1, l, (l + r) / 2),
               get_max(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int n, k, d, a[int(2e5 + 5)];

int ans[int(2e5 + 5)];

int main() {
  cin >> n >> k >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (1 + d * (k - 1) > n) {
    cout << -1 << endl;
    return 0;
  }

  SegmentTree tree(k + 5);
  int now_r = 1, r_idx = 1;
  ans[1] = a[1];
  tree.insert(1, a[1]);

  for (int i = 2; i <= n; i++) {
    if (i - r_idx >= d && now_r < k) {
      ans[now_r + 1] = a[i];
      now_r++;
      r_idx = i;
      tree.insert(now_r, a[i]);
    }

    int now_l = max(1, k - (n - i) / d);

    if (tree.get_max(now_l, now_r + 1) <= a[i]) {
      continue;
    }

    if (tree.get_max(now_l, now_l + 1) > a[i]) {
      now_r = now_l;
      r_idx = i;
      ans[now_r] = a[i];
      tree.insert(now_r, a[i]);
      continue;
    }

    int ng = now_l, ok = now_r + 1;
    while (ok - ng > 1) {
      int mid = (ng + ok) / 2;
      if (tree.get_max(now_l, mid + 1) > a[i]) {
        ok = mid;
      } else {
        ng = mid;
      }
    }

    now_r = ok;
    r_idx = i;
    ans[now_r] = a[i];
    tree.insert(now_r, a[i]);
  }

  for (int i = 1; i <= k; i++) {
    cout << ans[i];
    if (i == k) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
