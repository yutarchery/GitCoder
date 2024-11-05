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
  vector<ll> node;

  void init() {
    int sz = 1;
    while (sz < n) {
      sz *= 2;
    }
    n = sz;
    node.resize(2 * sz - 1);
    return;
  }

  void update(int idx, ll val) {
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

ll n, m, a[int(2e5 + 5)], s[int(2e5 + 5)], ss[int(2e5 + 5)];
ll ans = 0;

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= m;
    s[i] = (s[i - 1] + a[i]) % m;
    ss[i] = ss[i - 1] + s[i];
  }

  SegmentTree tree;
  tree.n = m + 1;
  tree.init();
  tree.update(0, 1);

  for (ll i = 1; i <= n; i++) {
    ans += s[i] * i - ss[i - 1];
    ll cnt = tree.get_sum(s[i] + 1, m);
    ans += cnt * m;
    tree.update(s[i], 1);
  }
  cout << ans << endl;

  return 0;
}
