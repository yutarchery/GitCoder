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
  vector<Pll> max_tree, second_tree;
  vector<Pll> tmp;

public:
  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    max_tree.resize(2 * n - 1);
    second_tree.resize(2 * n - 1);
  }

  void insert(int idx, ll val) {
    idx += n - 1;
    max_tree[idx] = {val, 1};

    while (idx > 0) {
      idx = (idx - 1) / 2;

      tmp.resize(0);
      for (int k = 1; k <= 2; k++) {
        tmp.push_back(max_tree[2 * idx + k]);
        tmp.push_back(second_tree[2 * idx + k]);
      }
      sort(tmp.begin(), tmp.end(), greater<Pll>());

      ll second_value = 0;
      for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i].first < tmp[0].first) {
          second_value = tmp[i].first;
          break;
        }
      }

      max_tree[idx].first = tmp[0].first;
      max_tree[idx].second = 0;
      second_tree[idx].first = second_value;
      second_tree[idx].second = 0;

      for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i].first == tmp[0].first) {
          max_tree[idx].second += tmp[i].second;
        }

        if (tmp[i].first == second_value) {
          second_tree[idx].second += tmp[i].second;
        }
      }

      tmp.resize(0);
    }

    return;
  }

  void prepare(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
      tmp.resize(0);
    }
    if (b <= l || r <= a) {
      return;
    }

    if (a <= l && r <= b) {
      tmp.push_back(max_tree[k]);
      tmp.push_back(second_tree[k]);
      return;
    }

    prepare(a, b, 2 * k + 1, l, (l + r) / 2);
    prepare(a, b, 2 * k + 2, (l + r) / 2, r);
    return;
  }

  int calc_seconds(int a, int b) {
    prepare(a, b);
    sort(tmp.begin(), tmp.end(), greater<Pll>());

    ll second_value;
    for (Pll p : tmp) {
      if (p.first < tmp[0].first) {
        second_value = p.first;
        break;
      }
    }

    ll res = 0;
    for (int i = 0; i < tmp.size(); i++) {
      if (tmp[i].first == second_value) {
        res += tmp[i].second;
      }
    }

    tmp.resize(0);
    return res;
  }
};

int n, q, num, p, x, l, r;
ll a[int(2e5 + 5)];

int main() {
  cin >> n >> q;
  SegmentTree tree(n + 5);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tree.insert(i, a[i]);
  }

  while (q--) {
    cin >> num;
    if (num == 1) {
      cin >> p >> x;
      tree.insert(p, x);
    } else {
      cin >> l >> r;
      cout << tree.calc_seconds(l, r + 1) << endl;
    }
  }

  return 0;
}
