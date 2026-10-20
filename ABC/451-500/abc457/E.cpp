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
  const int MAX = 1e9;
  vector<int> node;

  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    node.resize(2 * n - 1, MAX);
  }

  void insert(int idx, int val) {
    idx += n - 1;
    node[idx] = min(node[idx], val);

    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = min(node[2 * idx + 1], node[2 * idx + 2]);
    }
  }

  int get_min(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    if (b <= l || r <= a) {
      return MAX;
    }
    if (a <= l && r <= b) {
      return node[k];
    }
    return min(get_min(a, b, 2 * k + 1, l, (l + r) / 2),
               get_min(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int n, m, l[int(2e5 + 5)], r[int(2e5 + 5)];
int q, s[int(2e5 + 5)], t[int(2e5 + 5)];

map<Pii, int> cnt;
vector<int> from_l[int(2e5 + 5)], from_r[int(2e5 + 5)];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  SegmentTree tree(n + 5);

  for (int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i];

    cnt[{l[i], r[i]}]++;
    from_l[l[i]].emplace_back(r[i]);
    from_r[r[i]].emplace_back(l[i]);
    tree.insert(l[i], r[i]);
  }

  for (int i = 1; i <= n; i++) {
    sort(from_l[i].begin(), from_l[i].end());
    sort(from_r[i].begin(), from_r[i].end());
  }

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> s[i] >> t[i];

    if (cnt[{s[i], t[i]}] >= 2) {
      Yes();
      continue;
    }
    if (cnt[{s[i], t[i]}] == 1) {
      if (tree.get_min(s[i], s[i] + 1) < t[i]) {
        Yes();
      } else if (tree.get_min(s[i] + 1, t[i] + 1) <= t[i]) {
        Yes();
      } else {
        No();
      }
      continue;
    }

    if (from_l[s[i]].size() == 0 || from_r[t[i]].size() == 0) {
      No();
      continue;
    }

    if (from_l[s[i]][0] > t[i] ||
        from_r[t[i]][from_r[t[i]].size() - 1] < s[i]) {
      No();
      continue;
    }

    int l_ok = 0, l_ng = from_l[s[i]].size();
    while (l_ng - l_ok > 1) {
      int mid = (l_ok + l_ng) / 2;
      if (from_l[s[i]][mid] <= t[i]) {
        l_ok = mid;
      } else {
        l_ng = mid;
      }
    }

    int r_ng = -1, r_ok = from_r[t[i]].size() - 1;
    while (r_ok - r_ng > 1) {
      int mid = (r_ok + r_ng) / 2;
      if (s[i] <= from_r[t[i]][mid]) {
        r_ok = mid;
      } else {
        r_ng = mid;
      }
    }

    if (from_l[s[i]][l_ok] + 1 >= from_r[t[i]][r_ok]) {
      Yes();
    } else {
      No();
    }
  }

  return 0;
}
