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
  vector<ll> node;

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

int n;
ll l, r, a[int(3e5 + 5)];

ll sum[int(3e5 + 5)];
set<ll> st;
map<ll, int> idx;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> l >> r;
  sum[0] = -2e18;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  sum[n + 1] = 2e18;

  for (int i = 0; i <= n + 1; i++) {
    st.insert(sum[i]);
  }
  int cnt = 0;
  for (ll now : st) {
    idx[now] = cnt;
    cnt++;
  }

  SegmentTree tree(n + 5);
  for (int i = 1; i <= n; i++) {
    tree.add(idx[sum[i]], 1);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    auto min_iter = st.lower_bound(sum[i - 1] + l);
    auto max_iter = st.upper_bound(sum[i - 1] + r);

    ans += tree.get_sum(idx[*min_iter], idx[*max_iter]);

    tree.add(idx[sum[i]], -1);
  }

  cout << ans << '\n';

  return 0;
}
