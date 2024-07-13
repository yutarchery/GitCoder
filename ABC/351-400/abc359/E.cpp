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
    while (sz < n) {
      sz *= 2;
    }
    node.resize(sz * 2 - 1);
    return;
  }

  void insert(int idx, ll val) {
    idx += sz - 1;
    node[idx] = max(node[idx], val);

    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = max(node[2 * idx + 1], node[2 * idx + 2]);
    }

    return;
  }

  ll get_max(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = sz;
    }

    if (b <= l || r <= a) {
      return 0;
    }
    if (a <= l && r <= b) {
      return node[k];
    }
    return max(get_max(a, b, 2 * k + 1, l, (l + r) / 2),
               get_max(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int n;
ll h[int(2e5 + 5)];

set<ll> st;
map<ll, int> idx;

SegmentTree tree;
ll dp[int(2e5 + 5)];

int main() {
  cin >> n;
  h[0] = ll(2e9);
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    st.insert(h[i]);
  }

  for (int i = 0; i <= n; i++) {
    st.insert(h[i]);
  }

  int now = 0;
  for (ll l : st) {
    idx[l] = now;
    now++;
  }
  tree.init(n + 1);
  tree.insert(idx[h[0]], 0);

  for (int i = 1; i <= n; i++) {
    int j = tree.get_max(idx[h[i]], n + 1);
    dp[i] = dp[j] + h[i] * (i - j);
    tree.insert(idx[h[i]], i);
  }

  for (int i = 1; i <= n; i++) {
    cout << dp[i] + 1;
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
