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
  vector<Pii> min_node, max_node;

  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    min_node.resize(2 * n - 1);
    max_node.resize(2 * n - 1);
  }

  void insert(int val, int idx) {
    idx += n - 1;
    min_node[idx] = {val, idx - (n - 1)};
    max_node[idx] = {val, idx - (n - 1)};

    while (idx > 0) {
      idx = (idx - 1) / 2;
      min_node[idx] = min(min_node[2 * idx + 1], min_node[2 * idx + 2]);
      max_node[idx] = max(max_node[2 * idx + 1], max_node[2 * idx + 2]);
    }

    return;
  }

  Pii get_min(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    if (r <= a || b <= l) {
      return {1e9, 0};
    }
    if (a <= l && r <= b) {
      return min_node[k];
    }

    return min(get_min(a, b, 2 * k + 1, l, (l + r) / 2),
               get_min(a, b, 2 * k + 2, (l + r) / 2, r));
  }

  Pii get_max(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    if (r <= a || b <= l) {
      return {0, 0};
    }
    if (a <= l && r <= b) {
      return max_node[k];
    }

    return max(get_max(a, b, 2 * k + 1, l, (l + r) / 2),
               get_max(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int n, m, p[int(2e5 + 5)], l[int(2e5 + 5)], r[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  SegmentTree tree(n + 5);

  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    tree.insert(p[i], i);
  }

  for (int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i];
    Pii now_max = tree.get_max(l[i], r[i] + 1);
    Pii now_min = tree.get_min(l[i], r[i] + 1);

    tree.insert(now_max.first, now_min.second);
    tree.insert(now_min.first, now_max.second);
  }

  for (int i = 1; i <= n; i++) {
    cout << tree.get_min(i, i + 1).first << (i == n ? '\n' : ' ');
  }

  return 0;
}
