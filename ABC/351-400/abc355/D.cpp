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
  vector<ll> node;

  void init(int n) {
    sz = 1;
    while (sz <= n) {
      sz *= 2;
    }
    node.resize(2 * sz - 1);
    return;
  }

  void add(int idx) {
    idx += sz - 1;
    node[idx]++;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = node[2 * idx + 1] + node[2 * idx + 2];
    }
    return;
  }

  ll sum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = sz;
    }
    if (b <= l || r <= a) {
      return 0;
    }
    if (a <= l && r <= b) {
      return node[k];
    }

    return sum(a, b, 2 * k + 1, l, (l + r) / 2) +
           sum(a, b, 2 * k + 2, (l + r) / 2, r);
  }
};

int n, l[int(5e5 + 5)], r[int(5e5 + 5)];
Pii p[int(5e5 + 5)];
set<int> st;
map<int, int> idx;
ll ans = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    st.insert(l[i]);
    st.insert(r[i]);
    p[i] = {l[i], r[i]};
  }
  sort(p + 1, p + n + 1);

  int cnt = 1;
  for (int s : st) {
    idx[s] = cnt;
    cnt++;
  }

  SegmentTree tree;
  tree.init(2 * n + 1);
  for (int i = 1; i <= n; i++) {
    ans += (i - 1) - tree.sum(0, idx[p[i].first]);
    tree.add(idx[p[i].second]);
  }
  cout << ans << endl;

  return 0;
}
