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
  vector<ll> node;

public:
  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    node.resize(2 * n - 1, 0);
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
char s[int(5e5 + 5)];

int val[int(5e5 + 5)], min_val = 1e9;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];

    if (s[i] == 'A') {
      val[i] = val[i - 1] + 1;
    } else if (s[i] == 'B') {
      val[i] = val[i - 1] - 1;
    } else {
      val[i] = val[i - 1];
    }
    min_val = min(min_val, val[i]);
  }

  SegmentTree tree(n + 5);
  for (int i = 0; i <= n; i++) {
    val[i] = val[i] - min_val;
    tree.add(val[i], 1);
  }

  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += tree.get_sum(val[i] + 1, n + 5);
    tree.add(val[i], -1);
  }
  cout << ans << endl;

  return 0;
}
