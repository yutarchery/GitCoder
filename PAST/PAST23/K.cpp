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
  vector<int> node;

  void init(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }

    node.resize(2 * n - 1);
    return;
  }

  void add(int idx, int val) {
    idx += n - 1;
    node[idx] += val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = node[2 * idx + 1] + node[2 * idx + 2];
    }
    return;
  }

  int get_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
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

int n, q;
char s[int(2e5 + 5)];
int op, p, l, r;
char c;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  SegmentTree tree[26];
  for (int i = 0; i < 26; i++) {
    tree[i].init(n + 5);
  }
  for (int i = 1; i <= n; i++) {
    tree[s[i] - 'a'].add(i, 1);
  }

  while (q--) {
    cin >> op;

    if (op == 1) {
      cin >> p >> c;
      tree[s[p] - 'a'].add(p, -1);
      tree[c - 'a'].add(p, 1);
      s[p] = c;
    } else {
      cin >> l >> r;
      int ans = 0;
      for (int i = 0; i < 26; i++) {
        ans = max(tree[i].get_sum(l, r + 1), ans);
      }
      cout << ans << '\n';
    }
  }

  return 0;
}
