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

  void prepare(int node_size) {
    int res = 1;
    while (res < node_size) {
      res *= 2;
    }
    n = res;
    node.resize(2 * n - 1);
  }

  void add(int idx, int val) {
    idx += n - 1;
    node[idx] += val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] += val;
    }
  }

  int getsum(int a, int b, int now = 0, int l = 0, int r = -1) {
    if (r < 0) {
      r = n;
    }
    if (b <= l || r <= a) {
      return 0;
    }
    if (a <= l && r <= b) {
      return node[now];
    }

    return getsum(a, b, now * 2 + 1, l, (l + r) / 2) +
           getsum(a, b, now * 2 + 2, (l + r) / 2, r);
  }

  int search(int cnt) {
    int l = 0, r = n;
    while (r - l > 1) {
      int mid = (l + r) / 2;

      if (getsum(0, mid) < cnt) {
        l = mid;
      } else {
        r = mid;
      }
    }
    return l;
  }
};

int main() {
  SegmentTree segmentTree;
  segmentTree.prepare(int(2e5 + 5));

  int q, t, x;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> t >> x;

    if (t == 1) {
      segmentTree.add(x, 1);
    } else {
      int ans = segmentTree.search(x);
      cout << ans << endl;
      segmentTree.add(ans, -1);
    }
  }

  return 0;
}