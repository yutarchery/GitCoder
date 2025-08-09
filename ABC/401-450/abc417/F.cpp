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
  vector<ll> tree, lazy_val;
  vector<bool> is_changed;
  const ll mod = MOD2;

public:
  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }

    tree.resize(2 * n - 1);
    lazy_val.resize(2 * n - 1);
    is_changed.resize(2 * n - 1);
  }

  void evaluate(int k, ll l, ll r) {
    if (!is_changed[k]) {
      return;
    }

    tree[k] = lazy_val[k] * (r - l) % mod;
    if (r - l > 1) {
      is_changed[2 * k + 1] = true;
      lazy_val[2 * k + 1] = lazy_val[k];
      is_changed[2 * k + 2] = true;
      lazy_val[2 * k + 2] = lazy_val[k];
    }

    is_changed[k] = false;
    lazy_val[k] = 0;
    return;
  }

  void insert(int a, int b, ll val, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }

    evaluate(k, l, r);
    if (b <= l || r <= a) {
      return;
    }
    if (a <= l && r <= b) {
      is_changed[k] = true;
      lazy_val[k] = val;
      evaluate(k, l, r);
      return;
    }

    insert(a, b, val, 2 * k + 1, l, (l + r) / 2);
    insert(a, b, val, 2 * k + 2, (l + r) / 2, r);
    tree[k] = (tree[2 * k + 1] + tree[2 * k + 2]) % mod;

    return;
  }

  ll get_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    evaluate(k, l, r);
    if (b <= l || r <= a) {
      return 0;
    }
    if (a <= l && r <= b) {
      return tree[k];
    }

    return (get_sum(a, b, 2 * k + 1, l, (l + r) / 2) +
            get_sum(a, b, 2 * k + 2, (l + r) / 2, r)) %
           mod;
  }
};

ll my_pow(ll a, ll n, ll mod) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return my_pow(a * a % mod, n / 2, mod);
  } else {
    return a * my_pow(a, n - 1, mod) % mod;
  }
}

int n, m, l[int(2e5 + 5)], r[int(2e5 + 5)];
ll a[int(2e5 + 5)];

int main() {
  cin >> n >> m;

  SegmentTree tree(n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tree.insert(i, i + 1, a[i]);
  }

  for (int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i];

    ll sum = tree.get_sum(l[i], r[i] + 1);
    ll e = sum * my_pow(r[i] - l[i] + 1, MOD2 - 2, MOD2) % MOD2;

    tree.insert(l[i], r[i] + 1, e);
  }

  for (int i = 1; i <= n; i++) {
    cout << tree.get_sum(i, i + 1) << (i == n ? '\n' : ' ');
  }

  return 0;
}
