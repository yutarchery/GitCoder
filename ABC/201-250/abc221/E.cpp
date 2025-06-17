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
  vector<ll> tree;

public:
  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }

    tree.resize(2 * n - 1);
  }

  void insert(int idx, ll val) {
    idx += n - 1;
    tree[idx] = val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      tree[idx] = (tree[2 * idx + 1] + tree[2 * idx + 2]) % MOD2;
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
      return tree[k];
    }
    return (get_sum(a, b, 2 * k + 1, l, (l + r) / 2) +
            get_sum(a, b, 2 * k + 2, (l + r) / 2, r)) %
           MOD2;
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

int n, a[int(3e5 + 5)];
Pii p[int(3e5 + 5)];

ll pows[int(3e5 + 5)], revs[int(3e5 + 5)];
ll ans = 0;

int main() {
  cin >> n;
  SegmentTree tree(n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tree.insert(i, my_pow(2, i, MOD2));
    p[i] = {a[i], i};
  }
  sort(p + 1, p + n + 1);

  pows[0] = 1;
  for (int i = 1; i <= n + 1; i++) {
    pows[i] = pows[i - 1] * 2 % MOD2;
  }
  const ll base = my_pow(2, MOD2 - 2, MOD2);
  revs[0] = 1;
  for (int i = 1; i <= n + 1; i++) {
    revs[i] = revs[i - 1] * base % MOD2;
  }

  for (int i = 1; i <= n; i++) {
    int idx = p[i].second;
    ll sum = tree.get_sum(idx + 1, n + 1);
    ans += sum * revs[idx + 1] % MOD2;
    ans %= MOD2;
    tree.insert(idx, 0);
  }

  cout << ans << endl;

  return 0;
}
