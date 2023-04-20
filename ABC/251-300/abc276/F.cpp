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

  void prepare() {
    int res = 1;
    while (res < n) {
      res *= 2;
    }

    n = res;
    node.resize(2 * res - 1);
    return;
  }

  void insert(int x, ll val) {
    x += n - 1;
    node[x] += val;
    node[x] %= MOD2;
    while (x > 0) {
      x = (x - 1) / 2;
      node[x] = (node[2 * x + 1] + node[2 * x + 2]) % MOD2;
    }
    return;
  }

  ll getsum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    if (r <= a || b <= l) {
      return 0;
    }
    if (a <= l && r <= b) {
      return node[k];
    }
    return (getsum(a, b, 2 * k + 1, l, (l + r) / 2) +
            getsum(a, b, 2 * k + 2, (l + r) / 2, r)) %
           MOD2;
  }
};

ll my_pow(ll a, ll b) {
  if (b == 0) {
    return 1;
  }
  if (b % 2 == 0) {
    return my_pow(a * a % MOD2, b / 2);
  } else {
    return my_pow(a, b - 1) * a % MOD2;
  }
}

int n, l = int(2e5 + 2);
ll a[int(2e5 + 5)], ans[int(2e5 + 5)];

int main() {
  cin >> n;
  SegmentTree cnt, sum;
  cnt.n = l;
  cnt.prepare();
  sum.n = l;
  sum.prepare();

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    ans[i] += ans[i - 1];
    ans[i] += sum.getsum(a[i], l) * 2 % MOD2;
    ans[i] += a[i] * (cnt.getsum(0, a[i])) * 2 % MOD2;
    cnt.insert(a[i], 1);
    sum.insert(a[i], a[i]);
    ans[i] += a[i];
    ans[i] %= MOD2;
  }

  for (ll i = 1; i <= n; i++) {
    ll frac = my_pow(my_pow(i, MOD2 - 2), 2);
    cout << ans[i] * frac % MOD2 << endl;
  }

  return 0;
}