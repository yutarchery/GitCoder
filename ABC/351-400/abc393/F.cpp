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

  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    node.resize(2 * n - 1);
  }

  void update(int idx, ll val) {
    idx += n - 1;
    node[idx] = max(node[idx], val);

    while (idx > 0) {
      idx = (idx - 1) / 2;
      node[idx] = max(node[idx * 2 + 1], node[idx * 2 + 2]);
    }

    return;
  }

  ll get_max(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }

    if (r <= a || b <= l) {
      return 0;
    }

    if (a <= l && r <= b) {
      return node[k];
    }

    return max(get_max(a, b, 2 * k + 1, l, (l + r) / 2),
               get_max(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int n, q, a[int(2e5 + 5)], r[int(2e5 + 5)], x[int(2e5 + 5)];
Pii r_idx[int(2e5 + 5)];
int ans[int(2e5 + 5)];

map<int, bool> visited;
vector<int> v;
map<int, int> indexes;

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (!visited[a[i]]) {
      visited[a[i]] = true;
      v.push_back(a[i]);
    }
  }
  for (int i = 1; i <= q; i++) {
    cin >> r[i] >> x[i];
    r_idx[i] = {r[i], i};

    if (!visited[x[i]]) {
      visited[x[i]] = true;
      v.push_back(x[i]);
    }
  }
  sort(r_idx + 1, r_idx + q + 1);

  sort(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) {
    indexes[v[i]] = i + 1;
  }
  SegmentTree tree(n + q + 1);

  int a_idx = 1;
  for (int i = 1; i <= q; i++) {
    while (a_idx <= r_idx[i].first) {
      int now = tree.get_max(0, indexes[a[a_idx]]);
      tree.update(indexes[a[a_idx]], now + 1);
      a_idx++;
    }

    ans[r_idx[i].second] = tree.get_max(0, indexes[x[r_idx[i].second]] + 1);
  }

  for (int i = 1; i <= q; i++) {
    cout << ans[i] << "\n";
  }

  return 0;
}
