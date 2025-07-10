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
  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }

    node.resize(2 * n - 1);
  }

  void add(int idx, ll val) {
    idx += n - 1;
    node[idx] += val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = node[2 * idx + 1] + node[2 * idx + 2];
    }
    return;
  }

  ll get_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
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

int n, a[int(3e5 + 5)];
ll ans[int(3e5 + 5)];

int main() {
  cin >> n;

  SegmentTree tree(n);

  for (int i = 0; i <= n - 1; i++) {
    cin >> a[i];
    ans[0] += tree.get_sum(a[i] + 1, n);
    tree.add(a[i], 1);
  }

  for (int i = 1; i <= n - 1; i++) {
    ans[i] += ans[i - 1];
    ans[i] -= tree.get_sum(0, a[i - 1]);
    ans[i] += tree.get_sum(a[i - 1] + 1, n);
  }

  for (int i = 0; i <= n - 1; i++) {
    cout << ans[i] << endl;
  }

  return 0;
}
