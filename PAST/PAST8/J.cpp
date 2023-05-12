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
  vector<int> node;

public:
  void prepare(int node_size) {
    n = 1;
    while (n < node_size) {
      n *= 2;
    }
    node.resize(2 * n - 1);
  }

  void add(int idx, int val) {
    idx += n - 1;
    node[idx] += val;
    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = node[idx * 2 + 1] + node[idx * 2 + 2];
    }
  }

  int sum(int a, int b, int now = 0, int l = 0, int r = -1) {
    if (r < 0) {
      r = n;
    }
    if (r <= a || b <= l) {
      return 0;
    }
    if (a <= l && r <= b) {
      return node[now];
    }

    return sum(a, b, now * 2 + 1, l, (l + r) / 2) +
           sum(a, b, now * 2 + 2, (l + r) / 2, r);
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  SegmentTree segmentTree;
  segmentTree.prepare(2 * n + 2);

  for (int i = 0; i < q; i++) {
    int t, k;
    cin >> t >> k;

    if (t == 1) {
      int val = segmentTree.sum(0, k + 1);
      if (val % 2 == 0) {
        cout << k << endl;
      } else {
        cout << 2 * n - k + 1 << endl;
      }
    } else {
      segmentTree.add(n - k + 1, 1);
      segmentTree.add(n + k + 1, -1);
    }
  }

  return 0;
}