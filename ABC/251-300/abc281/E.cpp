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
  vector<int> cnt;
  vector<ll> sum;

public:
  void prepare(int node_num) {
    n = 1;
    while (n < node_num) {
      n *= 2;
    }
    sum.resize(n * 2 - 1);
    cnt.resize(n * 2 - 1);
  }

  void add(int idx, ll val) {
    idx = idx + n - 1;
    cnt[idx]++;
    sum[idx] += val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      cnt[idx] = cnt[idx * 2 + 1] + cnt[idx * 2 + 2];
      sum[idx] = sum[idx * 2 + 1] + sum[idx * 2 + 2];
    }
  }

  void remove(int idx, ll val) {
    idx = idx + n - 1;
    cnt[idx]--;
    sum[idx] -= val;

    while (idx > 0) {
      idx = (idx - 1) / 2;
      cnt[idx] = cnt[idx * 2 + 1] + cnt[idx * 2 + 2];
      sum[idx] = sum[idx * 2 + 1] + sum[idx * 2 + 2];
    }
  }

  int getCount(int a, int b, int idx = 0, int l = 0, int r = -1) {
    if (r < 0) {
      r = n;
    }
    if (b <= l || r <= a) {
      return 0;
    }
    if (a <= l && r <= b) {
      return cnt[idx];
    }
    return getCount(a, b, idx * 2 + 1, l, (l + r) / 2) +
           getCount(a, b, idx * 2 + 2, (l + r) / 2, r);
  }

  ll getSum(int a, int b, int idx = 0, int l = 0, int r = -1) {
    if (r < 0) {
      r = n;
    }
    if (b <= l || r <= a) {
      return 0;
    }
    if (a <= l && r <= b) {
      return sum[idx];
    }
    return getSum(a, b, idx * 2 + 1, l, (l + r) / 2) +
           getSum(a, b, idx * 2 + 2, (l + r) / 2, r);
  }
};

int n, m, k;
ll a[int(2e5 + 5)];
Pli p[int(2e5 + 5)];
int idx[int(2e5 + 5)];
SegmentTree segmentTree;

ll solve() {
  ll l_idx = 0, r_idx = ll(2e5 + 1);
  while (r_idx - l_idx > 1) {
    int mid = (l_idx + r_idx) / 2;
    if (segmentTree.getCount(0, mid) < k) {
      l_idx = mid;
    } else {
      r_idx = mid;
    }
  }

  return segmentTree.getSum(0, l_idx + 1);
}

int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    p[i] = {a[i], i};
  }
  sort(p + 1, p + n + 1);
  for (int i = 1; i <= n; i++) {
    idx[p[i].second] = i;
  }

  segmentTree.prepare(int(2e5 + 5));
  for (int i = 1; i <= m - 1; i++) {
    segmentTree.add(idx[i], a[i]);
  }

  for (int i = m; i <= n; i++) {
    segmentTree.add(idx[i], a[i]);
    cout << solve();
    segmentTree.remove(idx[i - m + 1], a[i - m + 1]);

    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}