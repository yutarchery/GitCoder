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
  int n;
  vector<ll> node;

  void prepare(int tree_size) {
    int res = 1;
    while (res < tree_size) {
      res *= 2;
    }
    n = res;
    node.resize(n * 2 - 1);
  }

  void update(int idx, ll val) {
    idx += n - 1;
    node[idx] = val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = max(node[idx * 2 + 1], node[idx * 2 + 2]);
    }
  }

  ll getmax(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r < 0) {
      r = n;
    }
    if (b <= l || r <= a) {
      return 0;
    }
    if (a <= l && r <= b) {
      return node[k];
    }

    return max(getmax(a, b, k * 2 + 1, l, (l + r) / 2),
               getmax(a, b, k * 2 + 2, (l + r) / 2, r));
  }
};

int n, h[int(2e5 + 5)];
ll a[int(2e5 + 5)];
SegmentTree segmentTree;

int main() {
  cin >> n;
  segmentTree.prepare(n + 1);

  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < n; i++) {
    ll m = segmentTree.getmax(0, h[i]);
    segmentTree.update(h[i], m + a[i]);
  }

  cout << segmentTree.getmax(0, n + 1) << endl;

  return 0;
}