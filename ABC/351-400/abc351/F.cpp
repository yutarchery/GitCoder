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
  int sz;
  vector<Pll> node;

  void init(int n) {
    sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    node.resize(2 * sz - 1);
    return;
  }

  void add(int idx, Pll val) {
    idx += sz - 1;
    node[idx].first += val.first;
    node[idx].second += val.second;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx].first = node[2 * idx + 1].first + node[2 * idx + 2].first;
      node[idx].second = node[2 * idx + 1].second + node[2 * idx + 2].second;
    }
    return;
  }

  Pll get_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = sz;
    }

    if (b <= l || r <= a) {
      return {0, 0};
    }

    if (a <= l && r <= b) {
      return node[k];
    }

    Pll p1 = get_sum(a, b, 2 * k + 1, l, (l + r) / 2);
    Pll p2 = get_sum(a, b, 2 * k + 2, (l + r) / 2, r);
    return {p1.first + p2.first, p1.second + p2.second};
  }
};

int n;
ll a[int(4e5 + 5)];
Pli p[int(4e5 + 5)];

map<int, int> idx;
ll ans = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = {a[i], i};
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++) {
    idx[p[i].second] = i;
  }

  SegmentTree tree;
  tree.init(n + 1);

  for (int i = 1; i <= n; i++) {
    tree.add(idx[i], {a[i], 1});
    Pll sum_cnt = tree.get_sum(0, idx[i] + 1);
    ans += a[i] * sum_cnt.second - sum_cnt.first;
  }
  cout << ans << endl;

  return 0;
}
