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
  vector<Pii> tree;

public:
  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    tree.resize(2 * n - 1);
  }

  void insert(int idx, int val) {
    idx += n - 1;
    tree[idx] = {val, val};

    while (idx > 0) {
      idx = (idx - 1) / 2;
      tree[idx].first = min(tree[2 * idx + 1].first, tree[2 * idx + 2].first);
      tree[idx].second =
          max(tree[2 * idx + 1].second, tree[2 * idx + 2].second);
    }
  }

  Pii get_value(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }
    if (b <= l || r <= a) {
      return {int(1e9), 0};
    }
    if (a <= l && r <= b) {
      return tree[k];
    }

    Pii next1 = get_value(a, b, 2 * k + 1, l, (l + r) / 2),
        next2 = get_value(a, b, 2 * k + 2, (l + r) / 2, r);
    return {min(next1.first, next2.first), max(next1.second, next2.second)};
  }
};

int n, x, y, a[int(2e5 + 5)];
vector<int> points;

int main() {
  cin >> n >> x >> y;
  points.push_back(0);

  SegmentTree tree(n + 5);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tree.insert(i, a[i]);

    if (a[i] == x || a[i] == y) {
      points.push_back(i);
    }
  }
  points.push_back(n + 1);

  ll ans = 0, next_idx = 0;
  for (ll i = 0; i < points.size(); i++) {
    int now = points[i];
    if (a[now] != x && a[now] != y) {
      continue;
    }

    if (next_idx < i) {
      next_idx = i;
    }

    bool flag = false;
    for (ll j = next_idx; j < points.size(); j++) {
      next_idx = j;
      Pii val = tree.get_value(now, points[j] + 1);

      if (val.first < y || val.second > x) {
        break;
      } else if (val.first == y && val.second == x) {
        flag = true;
        break;
      }
    }

    if (!flag) {
      continue;
    }

    ll before_ng = points[i - 1], before_ok = points[i];
    while (before_ok - before_ng > 1) {
      ll mid = (before_ng + before_ok) / 2;
      Pii val = tree.get_value(mid, points[next_idx] + 1);

      if (val.first == y && val.second == x) {
        before_ok = mid;
      } else {
        before_ng = mid;
      }
    }

    ll next_ok = points[next_idx], next_ng = n + 1;
    while (next_ng - next_ok > 1) {
      ll mid = (next_ok + next_ng) / 2;
      Pii val = tree.get_value(before_ok, mid + 1);

      if (val.first == y && val.second == x) {
        next_ok = mid;
      } else {
        next_ng = mid;
      }
    }

    ans += (points[i] - before_ok + 1) * (next_ok - points[next_idx] + 1);
  }

  cout << ans << endl;

  return 0;
}
