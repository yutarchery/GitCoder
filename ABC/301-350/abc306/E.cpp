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
  vector<ll> values;

public:
  void prepare(int size) {
    n = 1;
    while (n < size) {
      n *= 2;
    }
    values.resize(2 * n - 1);
    return;
  }

  void add_value(int idx, ll v) {
    idx += n - 1;
    values[idx] += v;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      values[idx] = values[idx * 2 + 1] + values[idx * 2 + 2];
    }
    return;
  }

  ll get_sum(int a, int b, int k = 0, int l = 0, int r = -1) {
    if (r == -1) {
      return get_sum(a, b, k, l, n);
    }

    if (r <= a || b <= l) {
      return 0;
    }

    if (a <= l && r <= b) {
      return values[k];
    }

    return get_sum(a, b, 2 * k + 1, l, (l + r) / 2) +
           get_sum(a, b, 2 * k + 2, (l + r) / 2, r);
  }
};

int n, q, x[int(5e5 + 5)];
ll k;
ll y[int(5e5 + 5)], now[int(5e5 + 5)];

vector<ll> used_numbers;
map<ll, bool> used;
map<ll, int> indexes;
SegmentTree count_tree, sum_tree;

ll solve() {
  int r_max = used_numbers.size() + 2;

  int l = 0, r = r_max;

  while (r - l > 1) {
    int mid = (l + r) / 2;

    if (count_tree.get_sum(mid, r_max) >= k) {
      l = mid;
    } else {
      r = mid;
    }
  }

  ll ans = sum_tree.get_sum(r, r_max);
  ans += (k - count_tree.get_sum(r, r_max)) * used_numbers[l - 1];

  return ans;
}

int main() {
  cin >> n >> k >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x[i] >> y[i];
  }

  for (int i = 0; i <= q; i++) {
    if (!used[y[i]]) {
      used[y[i]] = true;
      used_numbers.push_back(y[i]);
    }
  }
  sort(used_numbers.begin(), used_numbers.end());
  for (int i = 1; i <= int(used_numbers.size()); i++) {
    indexes[used_numbers[i - 1]] = i;
  }
  count_tree.prepare(int(5e5 + 5));
  sum_tree.prepare(int(5e5 + 5));

  count_tree.add_value(indexes[0], n);
  for (int i = 1; i <= q; i++) {
    count_tree.add_value(indexes[now[x[i]]], -1);
    count_tree.add_value(indexes[y[i]], 1);
    sum_tree.add_value(indexes[now[x[i]]], -1 * now[x[i]]);
    sum_tree.add_value(indexes[y[i]], y[i]);

    now[x[i]] = y[i];
    cout << solve() << endl;
  }

  return 0;
}