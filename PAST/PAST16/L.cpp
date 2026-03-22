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
  vector<ll> max_node, min_node;

  const ll MIN = -1e16, MAX = 1e16;

  SegmentTree(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    max_node.resize(2 * n - 1, MIN);
    min_node.resize(2 * n - 1, MAX);
  }

  void insert(int idx, bool is_same) {
    int val = idx;
    idx += n - 1;

    if (is_same) {
      max_node[idx] = val, min_node[idx] = val;
    } else {
      max_node[idx] = MIN, min_node[idx] = MAX;
    }

    while (idx > 0) {
      idx = (idx - 1) / 2;
      max_node[idx] = max(max_node[2 * idx + 1], max_node[2 * idx + 2]);
      min_node[idx] = min(min_node[2 * idx + 1], min_node[2 * idx + 2]);
    }
    return;
  }

  ll get_max(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }

    if (r <= a || b <= l) {
      return MIN;
    }
    if (a <= l && r <= b) {
      return max_node[k];
    }
    return max(get_max(a, b, 2 * k + 1, l, (l + r) / 2),
               get_max(a, b, 2 * k + 2, (l + r) / 2, r));
  }

  ll get_min(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      r = n;
    }

    if (r <= a || b <= l) {
      return MAX;
    }
    if (a <= l && r <= b) {
      return min_node[k];
    }
    return min(get_min(a, b, 2 * k + 1, l, (l + r) / 2),
               get_min(a, b, 2 * k + 2, (l + r) / 2, r));
  }
};

int t, x;

ll my_gcd(ll a, ll b) {
  if (a < b) {
    return my_gcd(b, a);
  }
  if (a % b == 0) {
    return b;
  } else {
    return my_gcd(b, a % b);
  }
}

int n, q;
ll a[int(1e5 + 5)], sum[int(1e5 + 5)];

struct my_comp {
  bool operator()(Pii p1, Pii p2) {
    ll l1 = p1.first, r1 = p1.second;
    ll l2 = p2.first, r2 = p2.second;

    return (sum[r1] - sum[l1]) * (r2 - l2) < (sum[r2] - sum[l2]) * (r1 - l1);
  }
};

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }

  SegmentTree tree(n + 5);
  priority_queue<Pii, vector<Pii>, my_comp> que;
  set<Pii> st;

  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> x;

      if (tree.get_max(0, x + 1) != x) {
        tree.insert(x, true);
        ll bf = tree.get_max(0, x), af = tree.get_min(x + 1, n + 1);

        if (bf != tree.MIN && af != tree.MAX) {
          st.erase({bf, af});
        }
        if (bf != tree.MIN) {
          st.insert({bf, x});
          que.push({bf, x});
        }
        if (af != tree.MAX) {
          st.insert({x, af});
          que.push({x, af});
        }
      } else {
        tree.insert(x, false);
        ll bf = tree.get_max(0, x), af = tree.get_min(x + 1, n + 1);

        if (bf != tree.MIN && af != tree.MAX) {
          st.insert({bf, af});
          que.push({bf, af});
        }
        if (bf != tree.MIN) {
          st.erase({bf, x});
        }
        if (af != tree.MAX) {
          st.erase({x, af});
        }
      }
    } else {
      while (!que.empty()) {
        Pii q1 = que.top();
        auto iter = st.find(q1);

        if (iter == st.end()) {
          que.pop();
        } else {
          int l = q1.first, r = q1.second;
          ll g = my_gcd(r - l, sum[r] - sum[l]);
          cout << (sum[r] - sum[l]) / g << " " << (r - l) / g << '\n';
          break;
        }
      }
    }
  }

  return 0;
}
